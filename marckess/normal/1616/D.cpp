// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX], to[MX], sig[MX], x, dp[MX];

void main_() {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	cin >> x;
	
	forn (i, n) {
		a[i] -= x;
		sig[i] = n;
	}
	
	map<ll, int> mp;
	
	ll acu = 0, ant = 0;
	forn (i, n) {
		acu += a[i];
		
		auto it = mp.upper_bound(acu);
		if (it != mp.end())
			to[i] = it->se;
		else
			to[i] = -2;
			
		it = mp.upper_bound(ant);
		while (it != mp.begin()) {
			auto jt = it;
			jt--;
			mp.erase(jt);
		}
		
		mp.emplace(ant, i - 1);
		ant = acu;
		
		if (to[i] >= -1)
			sig[to[i] + 1] = min(sig[to[i] + 1], i);
	}
	
	
	dp[n] = dp[n + 1] = 0;
	sig[n] = n;
	for (int i = n - 1; i >= 0; i--) {
		sig[i] = min(sig[i], sig[i + 1]);
		
		dp[i] = dp[i + 1];
		dp[i] = max(dp[i], sig[i] - i + dp[sig[i] + 1]);
	}
	
	cout << dp[0] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}