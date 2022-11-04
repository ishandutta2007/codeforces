#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
 
#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) (((n % k) + k ) % k)

int n, m;
vi a(1e5+5);

bool esPos (ll mit) {
    vi b = a;

    ll j = 0;
    for (int i = 0; i < m; i++) {
        ll t = mit;

        if (j + 1 <= t) {
            t -= j + 1;

            while (j < n && t > 0) {
                if (t < b[j]) {
                    b[j] -= t;
                    t = 0;
                } else {
                    t -= b[j];
                    b[j] = 0;
                    j++;
                    t--;
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
        if (b[i])
            return false;

    return true;
}

ll obtRes () {
    ll i = 1, j = 1e18, m = (i+j)/2, rep = 60;

    while (rep--) {
        if (esPos(m))
            j = m;
        else
            i = m;

        m = (i+j)/2;
    }

    if (esPos(i))
        return i;
    return j;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << obtRes() << endl;

    return 0;
}