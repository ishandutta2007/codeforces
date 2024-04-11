#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, k;

    scanf("%d %d", &n, &k);

    vec< int > a(n);

    for(int i = 0;i < n;i++) {
        scanf("%d", &a[i]);
    }

    sort(ALL(a));

    ll res = 0;

    for(int i = 1;i < n;i++) {
        if((a[i] - a[0]) % k) {
            printf("-1\n");
            return 0;
        }else {
            res += (a[i] - a[0]) / k;
        }
    }

    cout << res << "\n";

    return 0;
}