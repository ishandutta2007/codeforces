#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 105;

int n;
int f[N];
int col[N];
int par[N];
int st, fn;
int in[N];

int dfs(int v) {
    col[v] = 1;
    if(!col[ f[v] ]) {
        par[ f[v] ] = v;
        if(dfs(f[v])) return 1;
    }else if(col[ f[v] ] == 1) {
        st = f[v];
        fn = v;
        return 1;
    }
    col[v] = 2;
    return 0;
}

int gcd(int x, int y) {
    return x == 0 ? y : gcd(y % x, x);
}

ll lcm(ll x, ll y) {
    return (x / gcd(x, y) * y);
}

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &f[i]);
        in[ f[i] ] = i;
    }

    for(int i = 1;i <= n;i++) {
        if(!in[i]) {
            puts("-1");
            return 0;
        }
    }

    ll res = 1;

    for(int i = 1;i <= n;i++) {
        if(col[i]) continue;
        if(dfs(i)) {
            int len = 1;
            while(fn != st) {
                len++;
                fn = par[fn];
            }
            if(len % 2 == 0) len /= 2;
            res = lcm(res, len);
        }else {
            puts("-1");
            return 0;
        }
    }

    cout << res << "\n";

    return 0;
}