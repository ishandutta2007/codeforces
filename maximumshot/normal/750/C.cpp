#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int main() {

    ll ql = -inf64;
    ll qr = inf64;

    int n;
    scanf("%d", &n);

    ll pr = 0;
    for(int c, d, i = 0;i < n;i++) {
        scanf("%d %d", &c, &d);
        if(d == 1) {
            ql = max(ql, ll(1900ll - pr) );
        }else {
            qr = min(qr, ll(1900ll - pr - 1));
        }
        pr += c;
    }

    if(ql > qr) {
        cout << "Impossible\n";
    }else if(qr == inf64) {
        cout << "Infinity\n";
    }else {
        cout << qr + pr << "\n";
    }

    return 0;
}