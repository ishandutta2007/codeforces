#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n;
int a[N];
int p[N];
vec< int > g[N];
int h[N];

void dfs(int v) {
    if(v > 1) {
        h[v] = h[p[v]] ^ 1;
    }else {
        h[v] = 0;
    }
    for(int to : g[v]) {
        dfs(to);
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 2;i <= n;i++) {
        scanf("%d", &p[i]);
        g[p[i]].push_back(i);
    }

    dfs(1);

    int need;

    for(int i = 1;i <= n;i++) {
        if(g[i].empty()) {
            need = h[i];
            break;
        }
    }

    map< int, int > L;
    map< int, int > R;
    set< int > q;

    for(int v = 1;v <= n;v++) {
        if(h[v] == need) L[a[v]]++;
        else R[a[v]]++;
    }

    ll res = 0;

    int xl = 0;
    int xr = 0;

    for(int v = 1;v <= n;v++) {
        if(h[v] == need) {
            xl ^= a[v];
        }else {
            xr ^= a[v];
        }
    }

    for(int v = 1;v <= n;v++) {
        if(h[v] == need) {
            res += R[xl ^ a[v]];
        }
    }

    if(xl == 0) {
        int cl = 0;
        int cr = 0;
        for(int i = 1;i <= n;i++) {
            if(h[i] == need) {
                cl++;
            }else {
                cr++;
            }
        }
        res += 1ll * cl * (cl - 1) / 2;
        res += 1ll * cr * (cr - 1) / 2;
    }

    cout << res << "\n";

    return 0;
}