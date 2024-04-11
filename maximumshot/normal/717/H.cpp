#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const mod = inf + 7;

inline int sum(int a, int b) { return (a + b) % mod; }
inline int mul(int a, int b) { return (1ll * a * b) % mod; }
inline int raz(int a, int b) { return ((a - b) % mod + mod) % mod; }

int binpow(int n, int p) {
    if(p == 0) return 1;
    int q = binpow(n, p / 2);
    q = mul(q, q);
    if(p % 2) q = mul(q, n);
    return q;
}

bool solve() {

    int n, e;

    scanf("%d %d", &n, &e);

    vec< pii > hate(e);
    for(int i = 0;i < e;i++) {
        scanf("%d %d", &hate[i].first, &hate[i].second);
    }

    vec< vec< int > > want(n + 1);

    int T = 0;

    for(int sz, i = 1;i <= n;i++) {
        scanf("%d", &sz);
        want[i].resize(sz);
        for(int j = 0;j < sz;j++) {
            scanf("%d", &want[i][j]);
            T = max(T, want[i][j]);
        }
    }

    vec< int > dole(T + 1);
    vec< int > coach(n + 1);

    for(pii ed : hate) {
        int u, v;
        tie(u, v) = ed;
        if(coach[u] && coach[v]) continue;
        int u1, u2, v1, v2;
        u1 = u2 = v1 = v2 = -1;
        for(int j : want[u]) {
            if(dole[j] == 1) u1 = j;
            if(dole[j] == 2) u2 = j;
        }
        for(int j : want[v]) {
            if(dole[j] == 1) v1 = j;
            if(dole[j] == 2) v2 = j;
        }
        if(coach[u] && dole[coach[u]] == 1) {
            if (v2 != -1) {
                coach[v] = v2;
            } else {
                for (int j : want[v]) {
                    if (!dole[j]) {
                        dole[j] = 2;
                        coach[v] = j;
                        break;
                    }
                }
            }
        }else if(coach[u] && dole[coach[u]] == 2) {
            if(v1 != -1) {
                coach[v] = v1;
            }else {
                for(int j : want[v]) {
                    if(!dole[j]) {
                        dole[j] = 1;
                        coach[v] = j;
                        break;
                    }
                }
            }
        }else if(coach[v] && dole[coach[v]] == 1) {
            if(u2 != -1) {
                coach[u] = u2;
            }else {
                for(int j : want[u]) {
                    if(!dole[j]) {
                        dole[j] = 2;
                        coach[u] = j;
                        break;
                    }
                }
            }
        }else if(coach[v] && dole[coach[v]] == 2) {
            if(u1 != -1) {
                coach[u] = u1;
            }else {
                for(int j : want[u]) {
                    if(!dole[j]) {
                        dole[j] = 1;
                        coach[u] = j;
                        break;
                    }
                }
            }
        }else {
            if(u1 != -1 && v2 != -1) {
                coach[u] = u1;
                coach[v] = v2;
            }else if(u2 != -1 && v1 != -1) {
                coach[u] = u2;
                coach[v] = v1;
            }else {
                int tu, tv;
                tu = tv = -1;
                for(int j : want[u]) {
                    if(!dole[j]) {
                        tu = j;
                        break;
                    }
                }
                for(int j : want[v]) {
                    if(!dole[j]) {
                        tv = j;
                        break;
                    }
                }
                if(tu != -1 && tv != -1) {
                    dole[tu] = 1;
                    dole[tv] = 2;
                    coach[u] = tu;
                    coach[v] = tv;
                }
            }
        }
    }



    for(int i = 1;i <= n;i++) {
        if(!coach[i]) coach[i] = want[i].front();
        printf("%d ", coach[i]);
    }

    printf("\n");

    for(int i = 1;i <= T;i++) {
        printf("%d ", dole[i]?dole[i] : 1);
    }

    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}