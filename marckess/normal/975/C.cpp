#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 200005;
int n, q;
ll a[MX], k[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < q; i++)
        cin >> k[i];

    for (int i = 1; i < n; i++)
        a[i] += a[i-1];

    int i = 0;
    ll act = 0;
    for (int j = 0; j < q; j++) {
        if (k[j] >= a[n-1] - act) {
            
            i = 0;
            act = 0;

        } else {

            i = upper_bound(a, a+n, k[j] + act) - a;

            act += k[j];

            if (i == n) {
                i = 0;
                act = 0;
            }

        }

        cout << n - i << endl;
    }

    return 0;
}