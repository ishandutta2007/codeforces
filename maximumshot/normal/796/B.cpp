#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e6 + 5;

int n, m, k;
bool slot[N];
int now = 1;

int main() {

    scanf("%d %d %d", &n, &m, &k);

    for(int x, i = 1;i <= m;i++) {
        scanf("%d", &x);
        slot[x] = 1;
    }

    for(int u, v, i = 0;i < k;i++) {
        scanf("%d %d", &u, &v);
        if(now == u) {
            if(!slot[u]) {
                now = v;
            }
        }else if(now == v) {
            if(!slot[v]) {
                now = u;
            }
        }
    }

    printf("%d\n", now);

    return 0;
}