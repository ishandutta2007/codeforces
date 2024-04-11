#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)



int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll a, b, k, f, x;

    cin >> a >> b >> f >> k;

    x = b;

    ll res = 0;

    if (f > b) {
        cout << -1 << endl;
        return 0;
    }

    x -= f;
    for (int i = 1; i < k; i++) {
        if (i % 2) {
            if (2*(a-f) > x) {
                if (2*(a-f) > b) {
                    cout << -1 << endl;
                    return 0;
                }

                res++;
                x = b;
            }
            x -= 2*(a-f);
        } else {
            if (2*f > x) {
                if (2*f > b) {
                    cout << -1 << endl;
                    return 0;
                }

                res++;
                x = b;
            }
            x -= 2*f;
        }
    }

    
    if (k % 2) {
        if ((a-f) > x) {
            if ((a-f) > b) {
                cout << -1 << endl;
                return 0;
            }

            res++;
            x = b;
        } else {
            x -= (a-f);
        }
    } else {
        if (f > x) {
            if (f > b) {
                cout << -1 << endl;
                return 0;
            }

            res++;
            x = b;
        } else {
            x -= f;
        }
    }

    cout << res << endl;

    return 0;
}