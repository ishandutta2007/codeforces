#include <bits/stdc++.h>

using namespace std;

#define ALL(x) (x).begin(), (x).end()
#define vec vector

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;
const double pi = acos(-1.0);

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    ll n, m;

    cin >> n >> m;

    int ok = 0;

    while(n > 0 && m > 0) {
        // n >= 2mk
        // n - 2mk < 2m
        // n < 2m(k+1)
        // n/2m<k+1
        //k >n/2m-1=(n-2m)/2m
        if(n < m) swap(n, m), ok ^= 1;
        if(n >= 2 * m) {
            ll k = (n - 2 * m) / (2 * m) + 1;
            n -= 2 * m * k;
        }else {
            break;
        }
    }

    if(ok) swap(n, m);

    cout << n << " " << m << "\n";

    return 0;
}