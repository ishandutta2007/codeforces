#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
struct node{
    int nxt[2];
    int path;
    node() {
        nxt[0] = nxt[1] = -1;
        path = 0;
    }
};
vector < node > t[maxN];
int all[maxN];
bool used[maxN];
const int LOG = 18;
int q;
void add(int v, int num) {
    int cur = 0;
    for (int i = LOG; i >= 0; i--) {
        int bit = (num >> i) & 1;
        t[v][cur].path++;
        if (t[v][cur].nxt[bit] == -1) {
            node p;
            t[v].push_back(p);
            t[v][cur].nxt[bit] = all[v];
            all[v]++;
        }
        cur = t[v][cur].nxt[bit];
    }
    t[v][cur].path++;
}
pair < int, int > _find(int v, int lim, int val) {
    int ans = -1;
    int opt = -1;
    for (int i = 0; i <= LOG; i++) {
        int cur = 0;
        bool ok = true;
        int curnum = 0;
        for (int j = LOG; j > LOG - i; j--) {
            int bit = (lim >> j) & 1;
            if (t[v][cur].nxt[bit] != -1) {
                curnum += (1 << j) * bit;
                cur = t[v][cur].nxt[bit];
            }
            else {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        int bit = (lim >> (LOG - i)) & 1;
        if (bit == 0) continue;
        if (t[v][cur].nxt[0] == -1) continue;
        cur = t[v][cur].nxt[0];
        for (int j = LOG - i - 1; j >= 0; j--) {
            int bit = (val >> j) & 1;
            if (t[v][cur].nxt[bit ^ 1] != -1) {
                curnum += (1 << j) * (bit ^ 1);
                cur = t[v][cur].nxt[bit ^ 1];
            }
            else {
                cur = t[v][cur].nxt[bit];
                curnum += (1 << j) * bit;
            }
        }
        if ((curnum ^ val) > ans) {
            ans = curnum ^ val;
            opt = curnum;
        }
    }
    if (used[lim] && ((lim % v) == 0)) {
        if ((lim ^ val) > ans) {
            ans = lim ^ val;
            opt = lim;
        }
    }
    return make_pair(ans, opt);
}
vector < int > divi[maxN];
void calc() {
    for (int i = 1; i < maxN; i++) {
        for (int j = i; j < maxN; j += i) {
            divi[j].push_back(i);
        }
    }
}
int main() {
    srand(time(0));
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    calc();
    cin >> q;
    for (int i = 0; i < maxN; i++) {
        node p;
        t[i].push_back(p);
        all[i] = 1;
    }
    for (int i = 1; i <= q; i++) {
        int type;
        cin >> type;
        if (type == 1) {
            int u;
            cin >> u;
            if (used[u]) continue;
            used[u] = true;
            for (int j = 0; j < divi[u].size(); j++) {
                add(divi[u][j], u);
            }
        }
        else {
            int x, k, s;
            cin >> x >> k >> s;
            if ((x % k) != 0) {
                cout << -1 << '\n';
                continue;
            }
            if (x > s) {
                cout << -1 << '\n';
                continue;
            }
            auto t = _find(k, s - x, x);
            if (t.first == -1) {
                cout << -1 << '\n';
            }
            else {
                cout << t.second << '\n';
            }
        }
    }
    return 0;
}