#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef pair< int, int > pii;
typedef long long ll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n;
int a[N];
ll g[N];

int main() {

    scanf("%d", &n);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 2;i <= n;i++) {
        g[i] = g[i - 1];
        if(i % 2 == 0) {
            g[i] += abs(a[i] - a[i - 1]);
        }else {
            g[i] -= abs(a[i] - a[i - 1]);
        }
    }

    ll res = -inf64;
    ll mx = -inf64;
    ll mn = +inf64;

    for(int i = 1;i <= n;i++) {
        if(i % 2 == 0) {
            mx = max(mx, g[i]);
        }else {
            mn = min(mn, g[i]);
        }
        res = max(res, -g[i] + mx);
        res = max(res, +g[i] - mn);
    }

    cout << res << "\n";

    return 0;
}