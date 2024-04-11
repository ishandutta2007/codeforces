#include <bits/stdc++.h>

using namespace std;

int h;
bool vis[200];
vector<int> adj[200];

int used;

bool go(int cur, vector<int>& chain) {
    while (1) {
        vis[cur] = true;
        chain.push_back(cur);
        used++;
        cout << "? " << cur << endl;
        fflush(stdout);
        int k; cin >> k;
        if (k == 0) exit(0);
        for (int i = 0; i < k; i++) {
            int x; cin >> x;
            adj[cur].push_back(x);
        }

        if (k == 2) {
            cout << "! " << cur << endl;
            fflush(stdout);
            return true;
        }

        bool good = false;
        for (int i = 0; i < k; i++)
            if (!vis[adj[cur][i]]) {
                cur = adj[cur][i];
                good = true;
                break;
            }
        if (!good) break;
    }
    return false;
}

void bfs(int cur, int hv) {
    queue<int> que;
    que.push(cur);
    int cnt = 0;
    int ma = (hv == 5 ? 6 : 2);
    assert(used + ma <= 16);
    for (; cnt < ma && !que.empty();) {
        cur = que.front(); que.pop();
        if (vis[cur]) continue;
        vis[cur] = true;
        cnt++;
        cout << "? " << cur << endl;
        fflush(stdout);
        int k; cin >> k;
        if (k == 0) exit(0);
        for (int j = 0; j < k; j++) {
            int x; cin >> x;
            adj[cur].push_back(x);
            if (!vis[x]) que.push(x);
        }

        if (k == 2) {
            cout << "! " << cur << endl;
            fflush(stdout);
            return;
        }
    }

    while (!que.empty()) {
        int x = que.front(); que.pop();
        if (vis[x]) continue;
        cout << "! " << x << endl;
        fflush(stdout);
        return;
    }
}

void go() {
    cin >> h;
    if (h == 0) exit(0);
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < 200; i++) adj[i].clear();
    used = 0;

    //find chain
    vector<int> chain;
    int cur = 1;
    if (go(cur, chain)) return;

    reverse(chain.begin(), chain.end());
    bool good = false;
    for (int i : adj[1])
        if (!vis[i]) {
            cur = i;
            good = true;
        }

    if (good) {
        if (go(cur, chain)) return;
    }

    int hv = int(chain.size()) / 2 + 1;
    cur = chain[hv - 1];
    chain.resize(hv);
    for (int i : adj[cur])
        if (!vis[i]) {
            cur = i;
            break;
        }
    assert(cur != chain[hv - 1]);
    hv++;

    assert(used <= 11);

    while (1) { 
        if (hv < 5) {
            if (go(cur, chain)) return;
            hv = int(chain.size()) / 2 + 1;
            cur = chain[hv - 1];
            chain.resize(hv);
            for (int i : adj[cur])
                if (!vis[i]) {
                    cur = i;
                    break;
                }
            assert(cur != chain[hv - 1]);
            hv++;
        } else if (hv == 7) {
            cout << "! " << cur << endl;
            return;
        } else {
            bfs(cur, hv);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) go();
}