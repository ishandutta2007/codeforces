#include <bits/stdc++.h>

using namespace std;

int n, m, s;
int cnt[20000005], nnode;
int root[100005];
int nxt[20000005][2];
set<pair<int, int>> kids;
vector<pair<pair<int, int>, int>> prints;

void add(int id, int v, int ch) {
    int cur = root[id];
    cnt[cur] += ch;
    for (int i = 16; i >= 0; --i) {
        int bit = v >> i & 1;
        if (!nxt[cur][bit]) nxt[cur][bit] = ++nnode;
        cur = nxt[cur][bit];
        cnt[cur] += ch;
    }
}

void move(int fr, int to) {
    int item = 0;
    int u = root[fr], v = root[to];
    for (int i = 16; i >= 0; --i) {
        if (cnt[nxt[u][0]] > cnt[nxt[v][0]]) {
            u = nxt[u][0];
            v = nxt[v][0];
        }
        else {
            u = nxt[u][1];
            v = nxt[v][1];
            item += (1 << i);
        }
    }
    prints.push_back({ {fr, to}, item });
    add(fr, item, -1);
    add(to, item, 1);
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) root[i] = i;
    nnode = n;
    for (int i = 1; i <= n; ++i) {
        int sz;
        cin >> sz;
        s += sz;
        kids.insert({sz, i});
        while (sz--) {
            int x;
            cin >> x;
            add(i, x, 1);
        }
    }
    while (true) {
        auto fr = *(--kids.end());
        auto to = *(kids.begin());
        if (fr.first - to.first <= 1) {
            break;
        }
        move(fr.second, to.second);
        kids.erase(fr);
        kids.erase(to);
        --fr.first;
        ++to.first;
        kids.insert(fr);
        kids.insert(to);
    }
    
    cout << prints.size() << endl;
    for (auto z: prints) cout << z.first.first << ' ' << z.first.second << ' ' << z.second << '\n';
    return 0;
}