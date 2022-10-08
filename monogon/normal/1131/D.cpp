
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define Mp make_pair
#define PII pair<int, int>
#define ll long long
#define VI vector<int>

using namespace std;

const int MAX_N = 1005;

int n, m;
string str[MAX_N];
int par[2 * MAX_N], sz[2 * MAX_N];
vector<int> adj[2 * MAX_N];
int visited[2 * MAX_N];
bool cross[2 * MAX_N];
int val[2 * MAX_N];
bool cycle = false;

int Find(int x) {
    return par[x] == -1 ? x : par[x] = Find(par[x]);
}
void Union(int a, int b) {
    a = Find(a);
    b = Find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
}

int dfs(int x, int visit) {
    if(visited[x] == visit) {
        cross[x] = true;
    }
    if(visited[x])
        return val[x];
    visited[x] = visit;
    val[x] = 1;
    for(int y : adj[x]) {
        val[x] = max(val[x], 1 + dfs(y, visit));
    }
    if(cross[x]) {
        cycle = true;
    }
    return val[x];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> m;
    fill(par, par + n + m, -1);
    fill(sz, sz + n + m, 1);
    fill(visited, visited + n + m, 0);
    fill(val, val + n + m, 1);
    FOR(i, n) {
        cin >> str[i];
        FOR(j, m) {
            if(str[i][j] == '=') {
                Union(i, j + n);
            }
        }
    }
    FOR(i, n) {
        FOR(j, m) {
            if(str[i][j] != '=' && Find(i) == Find(j + n)) {
                cout << "No" << endl;
                return 0;
            }
            if(str[i][j] == '<') {
                adj[Find(j + n)].push_back(Find(i));
            }else if(str[i][j] == '>') {
                adj[Find(i)].push_back(Find(j + n));
            }
        }
    }
    for(int i = 0; i < n + m; i++) {
        if(!visited[Find(i)]) {
            dfs(Find(i), i + 1);
        }
    }
    if(cycle) {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    FOR(i, n) {
        cout << val[Find(i)] << " ";
    }
    cout << endl;
    FOR(j, m) {
        cout << val[Find(j + n)] << " ";
    }
    cout << endl;
}