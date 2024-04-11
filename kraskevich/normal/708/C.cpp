#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 400 * 1000 + 10;
const int L = 22;

vector<int> g[N];
vector<int> tree[N];
int go[N][L];
int sz[N];
int n;
bool ans[N];
bool splitable[N];
int max_small[N];

bool dfs1(int v, int par) {
    go[v][0] = par;
    for (int i = 1; i < L; i++)
        go[v][i] = go[go[v][i - 1]][i - 1];
    sz[v] = 1;
    max_small[v] = 1;
    splitable[v] = true;
    for (int to : g[v]) 
        if (to != par) {
            tree[v].push_back(to);
            splitable[v] &= dfs1(to, v);
            sz[v] += sz[to];
            max_small[v] = max(max_small[v], max_small[to]); 
        }   
    if (sz[v] * 2 <= n)
        max_small[v] = max(max_small[v], sz[v]);
    return (2 * (sz[v] - max_small[v]) <= n);
} 

void dfs2(int v, int low_small) {
    vector<int> kids_small;
    for (int to : tree[v])
        kids_small.push_back(max_small[to]);
    sort(kids_small.begin(), kids_small.end());
    reverse(kids_small.begin(), kids_small.end());
    for (int to : tree[v]) {
        int cur = low_small;
        if (max_small[to] != kids_small[0])
            cur = max(cur, kids_small[0]);
        if (kids_small.size() >= 2)
            cur = max(cur, kids_small[1]);
        dfs2(to, cur);
    }
    int lo_sz = n - sz[v];
    if (!splitable[v])
        return;
    if (lo_sz * 2 <= n) {
        ans[v] = true;
        return;
    }         
    if ((lo_sz - low_small) * 2 <= n) {
        ans[v] = true;
        return;
    }
    int x = v;
    for (int i = L - 1; i >= 0; i--)
        if (2 * sz[go[x][i]] < n)
            x = go[x][i];
    x = go[x][0];
    int s1 = lo_sz - sz[x];
    assert (s1 * 2 <= n);
    int s2 = sz[x] - sz[v];
    if (s2 * 2 <= n)
        ans[v] = true;                                    
}


int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs1(0, 0);
    dfs2(0, 0);
    for (int i = 0; i < n; i++)
        cout << (ans[i] ? '1' : '0') << " ";
    cout << endl;     
    return 0;
}