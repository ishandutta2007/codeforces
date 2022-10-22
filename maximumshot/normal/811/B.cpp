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

int const N = 1e4 + 5;
int const SQRT = 105;

int n, m;
int p[N];
pii seg[N];
int x[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &m);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &p[i]);
    }

    for(int i = 1;i <= m;i++) {
        scanf("%d %d %d", &seg[i].first, &seg[i].second, &x[i]);
        int cnt = 0;
        for(int j = seg[i].first;j <= seg[i].second;j++) {
            cnt += p[j] < p[x[i]];
        }
        if(cnt == x[i] - seg[i].first) {
            puts("Yes");
        }else {
            puts("No");
        }
    }

    return 0;
}