#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, l, r, mx = 2e9;
int a[MX], b[MX], c[MX], q[MX];

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    iota (q, q+n, 0);
    sort (q, q+n, [&] (int i, int j) {
        return c[i] > c[j];
    });

    for (int i = 0; i < n; i++) {
        int u = q[i];

        if (r - a[u] <= mx) {
            b[u] = r;
            mx = r - a[u] - 1;
        } else if (a[u] + mx >= l) {
            b[u] = a[u] + mx;
            mx--;
        } else {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++)
        cout << b[i] << " ";
    cout << endl;

    return 0;
}