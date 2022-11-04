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

const int MX = 100005;
int n, m, _m;
int x, x2, y;
int v[MX], h[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> _m;
        
        forn(i,n) {
            cin >> x;
            v[i] = x;
        }
        
        m = 0;
        forn(i,_m) {
            cin >> x >> x2 >> y;
            if (x == 1) h[m++] = x2;
        }
        
        sort(v,v+n);
        sort(h,h+m);
        
        v[n++] = 1e9;
        
        int res = 1e9;
        
        for (int i = 0, j = 0; i < n; i++) {
            while (j < m && h[j] < v[i]) j++;
            res = min(res, i + m - j);
        }
        
        cout << res << endl;

	return 0;
}