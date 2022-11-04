#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int MX = 200005;
int n, p, m, dp[1 << 15];
ll a[MX];

typedef pair<int, string> Tres;

void solve () {
	cin >> n >> m >> p;
	
	forn (i, n) {
		string s;
		cin >> s;
		a[i] = stoll(s, 0, 2);
	}
	
	Tres res(0, string(m, '0'));
	
	forn (kk, 30) {
		int ind = uniform_int_distribution<int>(0, n - 1)(rng);
		
		vi v;
		forn (i, m)
			if (a[ind] & (1ll << i))
				v.pb(i);
		
		forn (i, 1 << int(v.size()))
			dp[i] = 0;
		
		forn (i, n) {
			int mk = 0;
			forn (j, v.size())
				if (a[i] & (1ll << v[j]))
					mk |= (1 << j);
			dp[mk]++;
		}
		
		forn (j, v.size())
			forn (i, 1 << (int)v.size())
				if (!(i & (1 << j)))
					dp[i] += dp[i | (1 << j)];
		
		int mx = 0;
		forn (i, 1 << (int)v.size())
			if (dp[i] >= (n + 1) / 2)
				if (__builtin_popcount(mx) < __builtin_popcount(i))
					mx = i;
		
		Tres p(__builtin_popcount(mx), string(m, '0'));
		forn (i, v.size())
			if (mx & (1 << i))
				p.se[v[i]] = '1';
		reverse(all(p.se));
		
		res = max(res, p);
	}
	
	cout << res.se << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	//cin >> t;
	while (t--)
		solve();
 
	return 0;
}