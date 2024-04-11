#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

ll n, k, sum;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll res = 0;

    cin >> n >> k;

    if ( k > 1e9 || k * (k + 1) / 2 > n ) {
        cout << -1 << endl;
        return 0;
    }

    sum = k * (k - 1L) / 2L;

    for (ll i = 1; i * i <= n; i++ ) {
        if ( n % i )
            continue;
        if ( n - sum * i > (k - 1L) * i )
            res = max(res, i);

        if ( i - sum > (k - 1) )
            res = max(res, n / i);
    }

    if (res) {
        for (ll i = 1; i < k; i++)
            cout << res * i << " ";
        cout << n - sum * res << endl;
    } else
        cout << -1; 

}