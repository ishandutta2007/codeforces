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

int n;
ll k, a[100005], cost, num, mx, res;

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    for (int i = 0; i < n; i++) 
    cin >> a[i];

    sort (a, a + n);

    ll i = 0, j = 0;
    cost = 0, num = 1, mx = 0;

    while ( i < n ) {
        if ( cost <= k ) {
            if ( num > mx ) {
                mx = num;
                res = a[j];
            }

            if ( j < n - 1 ) {
                j++;
                num++;
                cost += (j - i) * (a[j] - a[j-1]);
            } else {
                i = n;
            }
        } else {
            cost -= a[j] - a[i];
            i++;
            num--;
        }
    }

    cout << mx << " " << res << endl;

    return 0;
}