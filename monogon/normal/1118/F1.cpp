
#include <bits/stdc++.h>

#define FOR(i, n) for(int i = 0; i < n; i++)
#define FORK(i, k, n) for(int i = k; i < n; i++)
#define FORr(i, n) for(int i = n - 1; i >= 0; i--)
#define FORKr(i, k, n) for(int i = n - 1; i >= k; i--)
#define PRINT(a, b) copy((a), (b), ostream_iterator<int>(cout, " "))
#define all(a) a.begin(), a.end()
#define in(a, b) ((b).find(a) != (b).end())
#define sz(a) ((int) (a).size())
#define Mp make_pair
#define PII pair<int, int>
#define LL long long
#define VI vector<int>

using namespace std;

// Find minimal subtrees spanning all red and blue vertices, respectively
// Then find distances between these subtrees, or 0 if they overlap

const int MAX_N = 3e5 + 5;

int n, u, v, red, blue;
int a[MAX_N];
vector<int> adj[MAX_N];
bool visited[MAX_N];
bool overlap = false;

bool dfs(int x, int color) {
    visited[x] = true;
    bool b = a[x] == color;
    for(int y : adj[x]) {
        if(!visited[y]) {
            if(dfs(y, color))
                b = true;
        }
    }
    if(b) {
        if(a[x] != color && a[x] != 0) {
            overlap = true;
        }
        a[x] = color;
    }
    return b;
}

int dist(int x) {
    if(a[x] == 2) return 0;
    visited[x] = true;
    int M = MAX_N;
    for(int y : adj[x]) {
        if(!visited[y]) {
            int d = dist(y);
            if(a[y] != 1) d++;
            M = min(M, d);
        }
    }
    return M;
} 

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n;
    FOR(i, n) {
        // colors
        cin >> a[i];
        if(a[i] == 1) red = i;
        if(a[i] == 2) blue = i;
    }
    FOR(i, n - 1) {
        // edges
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(red, 1);
    fill(visited, visited + n, false);
    dfs(blue, 2);
    if(overlap) {
        cout << 0 << endl;
        return 0;
    }
    fill(visited, visited + n, false);
    cout << dist(red) << endl;
}