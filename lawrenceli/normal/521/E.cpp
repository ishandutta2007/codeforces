#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int MAXN = 200100;

int n, m, par[MAXN], ind[MAXN], low[MAXN], cnt, cmpcnt;
vector<int> adj[MAXN];
vector<pii> cmpn[MAXN];
stack<pii> stk;

void dfs(int cur, int p=-1) {
    par[cur] = p;
    ind[cur] = low[cur] = cnt++;
    for (int i : adj[cur])
        if (i != p)
            if (ind[i] == -1) {
                stk.push(pii(cur, i));
                dfs(i, cur);
                low[cur] = min(low[cur], low[i]);
                if (low[i] >= ind[cur]) {
                    for (bool b=0; !b; ) {
                        cmpn[cmpcnt].push_back(stk.top());
                        if (stk.top() == pii(cur, i)) b = 1;
                        stk.pop();
                    }
                    cmpcnt++;
                }
            } else {
                low[cur] = min(low[cur], ind[i]);
                if (ind[i] < ind[cur]) stk.push(pii(cur, i));
            }
}

bool vis[MAXN], in[MAXN];
vector<int> cyc;
stack<int> stk2;

void print(vector<int> v) {
    cout << v.size() << ' ';
    for (int i : v) cout << i << ' ';
    cout << '\n';
}

void dfs2(int st, int cur) {
    if (in[cur]) {
        cout << "YES\n";

        for (int i=0; i<cyc.size(); i++)
            if (cyc[i] == cur) {
                rotate(cyc.begin(), cyc.begin()+i, cyc.end());
                break;
            }

        vector<int> v;
        for (int i=0; 1; i++) {
            v.push_back(cyc[i]);
            if (cyc[i] == st) break;
        }
        print(v);

        v.clear();
        for (int i=0; 1; i=(i==0?cyc.size()-1:i-1)) {
            v.push_back(cyc[i]);
            if (cyc[i] == st) break;
        }
        print(v);

        v.clear();
        v.push_back(cur);
        while (!stk2.empty()) v.push_back(stk2.top()), stk2.pop();
        v.push_back(st);
        print(v);

        exit(0);
    }

    vis[cur] = 1;
    stk2.push(cur);
    for (int i : adj[cur])
        if (!vis[i])
            dfs2(st, i);
    stk2.pop();
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    memset(ind, -1, sizeof(ind));
    for (int i=1; i<=n; i++)
        if (ind[i] == -1)
            dfs(i);

    for (int i=1; i<=n; i++) adj[i].clear();
/*
    for (int i=0; i<cmpcnt; i++) {
        for (pii j : cmpn[i])
            cout << j.first << ' ' << j.second << endl;
        cout << endl;
    }
*/
    for (int c=0; c<cmpcnt; c++) {
        cyc.clear();

        for (pii p : cmpn[c]) {
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }

        int cur = cmpn[c][0].first, p = -1;
        bool b = 1;
        vector<int> v;
        while (!vis[cur]) {
            vis[cur] = 1;
            v.push_back(cur);
            b = 0;
            for (int i : adj[cur])
                if (i != p) {
                    p = cur, cur = i;
                    b = 1;
                    break;
                }
        }
        if (b) {
            for (int i=0, k=0; i<v.size(); i++) {
                if (v[i] == cur) k = 1;
                vis[v[i]] = 0;
                if (k) cyc.push_back(v[i]), in[v[i]] = 1;
            }
/*
            for (int i : cyc) cout << i << ' ';
            cout << endl;
*/
            for (int i=0; i<cyc.size(); i++)
                for (int j : adj[cyc[i]])
                    if (j != cyc[(i+1)%cyc.size()] && j != cyc[(i+cyc.size()-1)%cyc.size()]) {
                        vis[cyc[i]] = 1;
                        dfs2(cyc[i], j);
                        assert(0);
                    }
        }

        for (pii p : cmpn[c]) {
            adj[p.first].clear(), adj[p.second].clear();
            vis[p.first] = vis[p.second] = in[p.first] = in[p.second] = 0;
        }
    }

    cout << "NO\n";
}