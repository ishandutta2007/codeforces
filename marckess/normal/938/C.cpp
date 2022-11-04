#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

ll t, n, m, x;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> t;
    while (t--) {
        cin >> x;

        for (ll i = 1; i <= 1e5; i++) {
            ll d = i * i - x;
            if (d < 0)
                continue;

            d = round(sqrt(d));

            if (d > 0 && i * i - d * d == x) {
                ll e = i / d;
                if (e > 0 && i * i - (i / e) * (i / e) == x) {
                    cout << i << " " << e << endl;
                    goto res;
                }    
            }
        }

        cout << -1 << endl;
        res:;
    }

    return 0;
}