
#include <bits/stdc++.h>
using namespace std;

// This is the O(n) two-pointer solution from the editorial

const int N = 1e5 + 5;
int t, n, a, b, u, v, par[N], branch[N], depth[N];
vector<int> adj[N], Q[N];

// find largest branch lengths from each node, using 2 DFS's.
// first DFS is for root = a
// second DFS is for re-rooting
void findpivots(int x, int p) {
    Q[x].assign(3, 0);
    branch[x] = 0;
    for(int y : adj[x]) {
        if(y != p) {
            depth[y] = 1 + depth[x];
            findpivots(y, x);
            Q[x].push_back(1 + branch[y]);
            branch[x] = max(branch[x], 1 + branch[y]);
        }
    }
}
void findpivots2(int x, int p) {
    // move the three largest branch lengths to the front
    partial_sort(Q[x].begin(), Q[x].begin() + 3, Q[x].end(), greater<int>());
    for(int y : adj[x]) {
        if(y != p) {
            Q[y].push_back(1 + Q[x][branch[y] + 1 == Q[x][0]]);
            findpivots2(y, x);
        }
    }
}

// compute branch[x] = height of subtree of non-snake nodes
bool dfs(int x, int p) {
    par[x] = p;
    branch[x] = 0;
    bool hasb = (x == b);
    for(int y : adj[x]) {
        if(y != p) {
            if(dfs(y, x)) hasb = true;
            else branch[x] = max(branch[x], 1 + branch[y]);
        }
    }
    return hasb;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> a >> b;
        for(int i = 1; i <= n; i++) adj[i].clear();
        for(int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        depth[a] = 0;
        findpivots(a, -1);
        findpivots2(a, -1);
        bool pivot = false;
        for(int i = 1; i <= n; i++)
            pivot |= (Q[i][2] >= depth[b]);
        if(!pivot) {
            cout << "NO\n";
            continue;
        }
        dfs(a, -1);
        // trace out path from a to b, converting into an array problem
        vector<int> ve;
        ve.push_back(branch[b]);
        while(b != a) {
            b = par[b];
            ve.push_back(branch[b]);
        }
        // two-pointers on the array.
        int len = (int) ve.size(), l = 0, r = len - 1;
        int L = ve[r], R = r - ve[l];
        while(l < r) {
            if(l < L) {
                l++;
                R = min(R, len - 1 - (ve[l] - l));
            }else if(r > R) {
                r--;
                L = max(L, ve[r] - (len - 1 - r));
            }else break;
        }
        cout << (l == r ? "YES" : "NO") << '\n';
    }
}