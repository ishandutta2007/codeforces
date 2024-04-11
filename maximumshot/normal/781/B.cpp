#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e3 + 5;

string a[N];
string b[N];
int n;
vec< int > g[N];
vec< int > gr[N];

inline void add_edge(int u, int v) {
    g[u].push_back(v);
    gr[v].push_back(u);

    int ru = u < n ? u + n : u - n;
    int rv = v < n ? v + n : v - n;

    g[rv].push_back(ru);
    gr[ru].push_back(rv);
}

bool used[N];
int tops[N];
int sz = 0;

void dfs1(int v) {
    if(used[v]) return;
    used[v] = 1;
    for(int to : g[v]) {
        dfs1(to);
    }
    tops[sz++] = v;
}

int color[N];

void dfs2(int v, int cur) {
    if(used[v]) return;
    used[v] = 1;
    color[v] = cur;
    for(int to : gr[v]) {
        dfs2(to, cur);
    }
}

int main() {

    cin >> n;

    for(int i = 0;i < n;i++) {
        string name, city;
        cin >> name >> city;
        a[i] = name.substr(0, 3);
        b[i] = name.substr(0, 2) + city.substr(0, 1);
    }

    for(int x = 0;x < n;x++) {
        for(int y = 0;y < n;y++) {
            if(x == y) continue;
            if(a[x] == a[y]) {
                add_edge(x, y + n);
            }
            if(a[x] == b[y]) {
                add_edge(x, y);
            }
            if(b[x] == a[y]) {
                add_edge(x + n, y + n);
            }
            if(b[x] == b[y]) {
                add_edge(x + n, y);
            }
            if(a[x] == a[y]) {
                add_edge(x + n, y + n);
            }
        }
    }

    for(int i = 0;i < n+n;i++) used[i] = 0;
    for(int i = 0;i < n+n;i++) {
        dfs1(i);
    }

    for(int i = 0;i < n+n;i++) {
        used[i] = 0;
        color[i] = -i - 1;
    }

    reverse(tops, tops + sz);

    for(int v, cur = 1, i = 0;i < sz;i++) {
        v = tops[i];
        if(used[v]) continue;
        dfs2(v, cur);
        cur++;
    }

    for(int i = 0;i < n;i++) {
        if(color[i] == color[i + n]) {
            cout << "NO\n";
            return 0;
        }
    }

    cout << "YES\n";

    for(int i = 0;i < n;i++) {
        if(color[i] > color[i + n]) {
            cout << a[i] << "\n";
        }else {
            cout << b[i] << "\n";
        }
    }

    return 0;
}