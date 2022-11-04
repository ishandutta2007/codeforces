#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n, a[MX];
map<ll, ll> mp;
ll res, cn, sum, men;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	
	forn (i, n) {
		char c;
		cin >> c;
		a[i] = c - '0';
	}
	
	forn (i, n) {
		if (a[i]) {
			cn++;
			
			while (mp.size() && mp.begin()->fi <= cn) {
				men += mp.begin()->se;
				sum -= mp.begin()->fi * mp.begin()->se;
				mp.erase(mp.begin());
			}
		} else {
			for (int i = 1; i <= cn; i++) {
				sum += i;
				mp[i] = 1;
			}
			
			mp[cn] += men;
			sum += cn * men;
			mp[0]++;
			
			men = 0;
			cn = 0;
		}
		
		res += sum + cn * men + cn * (cn + 1) / 2;
	}
	
	cout << res << endl;
	
	return 0;
}