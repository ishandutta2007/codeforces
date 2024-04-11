#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    int n, m, k;

    scanf("%d %d %d", &n, &m, &k);

    int x, s;

    scanf("%d %d", &x, &s);

    vec< int > a(m), b(m), c(k), d(k);

    for(int i = 0;i < m;i++) scanf("%d", &a[i]);
    for(int i = 0;i < m;i++) scanf("%d", &b[i]);
    for(int i = 0;i < k;i++) scanf("%d", &c[i]);
    for(int i = 0;i < k;i++) scanf("%d", &d[i]);

    ll res = 1ll * x * n;

    for(int i = 0;i < m;i++) {
        if(b[i] <= s) {
            res = min(res, 1ll * a[i] * n);
        }
    }

    for(int i = 0;i < k;i++) {
        if(d[i] <= s) {
            res = min(res, 1ll * (n - c[i]) * x);
        }
    }

    for(int pos, ost, i = 0;i < m;i++) {
        if(b[i] <= s) {
            ost = s - b[i];
            pos = upper_bound(ALL(d), ost) - d.begin() - 1;
            if(pos >= 0 && pos < k) {
                res = min(res, 1ll * a[i] * (n - c[pos]));
            }
        }
    }

    cout << res << "\n";

    return 0;
}