
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
#define ll long long
#define VI vector<int>

using namespace std;

const int MAX_N = 1e5+5;

int n;
ll a, b, p[MAX_N];

// index 0 is true, n + 1 is false.
vector<int> adj[2 * MAX_N], adjin[2 * MAX_N], component[2 * MAX_N];
set<int> adjcomp[2 * MAX_N];
bool visited[2 * MAX_N];
int comp[2 * MAX_N], val[2 * MAX_N];

stack<int> st;

void dfs1(int x) {
    if(visited[x]) return;
    visited[x] = true;
    for(int y : adj[x]) {
        dfs1(y);
    }
    st.push(x);
}

void dfs2(int x, int root) {
    if(comp[x] != -1) return;
    comp[x] = root;
    for(int y : adjin[x]) {
        dfs2(y, root);
    }
}

void dfs3(int x) {
    if(visited[x]) return;
    visited[x] = true;
    for(int y : adjcomp[x]) {
        dfs3(y);
    }
    // assign values
    for(int y : component[x]) {
        if(val[y] == -1) {
            val[y] = 1;
            val[(y + n + 1) % (2 * n + 2)] = 0;
        }
    }
}

void edge(int x, int y) {
    adj[x].push_back(y);
    adjin[y].push_back(x);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin >> n >> a >> b;
    set<pair<ll, int> > s;
    for(int i = 1; i <= n; i++) {
        cin >> p[i];
        s.insert(Mp(p[i], i));
    }
    for(int i = 1; i <= n; i++) {
        auto l1 = s.lower_bound(Mp(a - p[i], 0));
        auto r1 = s.upper_bound(Mp(a - p[i], n + 1));
        
        auto l2 = s.lower_bound(Mp(b - p[i], 0));
        auto r2 = s.upper_bound(Mp(b - p[i], n + 1));
        if(l1 == r1 && l2 == r2) {
            cout << "NO" << endl;
            return 0;
        }
        for(auto it = l1; it != r1; it++) {
            edge(i, it->second);
            edge(it->second + n + 1, i + n + 1);
        }
        for(auto it = l2; it != r2; it++) {
            edge(i + n + 1, it->second + n + 1);
            edge(it->second, i);
        }
        if(l1 == r1) {
            edge(0, i + n + 1);
            edge(i, n + 1);
        }
        if(l2 == r2) {
            edge(0, i);
            edge(i + n + 1, n + 1);
        }
    }
    edge(n + 1, 0);

    fill(visited, visited + (2 * n + 2), false);
    for(int i = 0; i <= 2 * n + 1; i++) {
        dfs1(i);
    }
    fill(comp, comp + (2 * n + 2), -1);
    while(!st.empty()) {
        dfs2(st.top(), st.top());
        st.pop();
    }
    for(int i = 0; i <= 2 * n + 1; i++) {
        for(int j : adj[i]) {
            if(comp[i] != comp[j]) {
                adjcomp[comp[i]].insert(comp[j]);
            }
        }
        component[comp[i]].push_back(i);
    }
    for(int i = 0; i <= n; i++) {
        if(comp[i] == comp[i + n + 1]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    // topological sort on components
    fill(visited, visited + (2 * n + 2), false);
    fill(val, val + (2 * n + 2), -1);
    for(int i = 0; i <= 2 * n + 1; i++) {
        dfs3(comp[i]);
    }
    cout << "YES" << endl;
    for(int i = 1; i <= n; i++) {
        cout << !val[i] << " ";
    }
    cout << endl;
}