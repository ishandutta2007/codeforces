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

int const N = 2e5 + 5;

int n, k;
int a[N];

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    ll cur = 0;
    ll res = 0;

    for(int i = 1;i <= n;i++) {
        cur += a[i];
        if(i < k) {
            continue;
        }
        cur -= a[i - k];
        res += cur;
    }

    printf("%.10lf\n", double(res) / double(n - k + 1));

    return 0;
}