#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 300005;
int n, x[MX], y[MX];
int a = 1e9, b = -1e9, c = 1e9, d = -1e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
        forn (i,n) {
            cin >> x[i] >> y[i];
            a = min(a, x[i]);
            b = max(b, x[i]);
            c = min(c, y[i]);
            d = max(d, y[i]);
        }
        
        int res = 0;
        
        forn (i, n) {
            res = max(res, abs(x[i] - a) + abs(y[i] - c));
            res = max(res, abs(x[i] - b) + abs(y[i] - c));
            res = max(res, abs(x[i] - a) + abs(y[i] - d));
            res = max(res, abs(x[i] - b) + abs(y[i] - d));
        }
        
        cout << 2 * res;
        res = 2 * (abs(a-b) + abs(c-d));
        forn(i,n-3) cout << " " << res;
        cout << endl;

	return 0;
}