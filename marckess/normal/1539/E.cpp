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
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k[MX], al[MX], ar[MX], bl[MX], br[MX], ato[MX], bto[MX], res[MX], aini, bini;

void pre (int l[], int r[], int to[], int &inito, int ini) {
	set<ii> mn, mx;
	
	mn.emplace(-1, n);
	mx.emplace(m + 1, n);
	
	for (int i = n - 1; i >= 0; i--) {
		while (mn.rbegin()->fi >= r[i])
			mn.erase(*mn.rbegin());
		mn.emplace(r[i], i);
		
		while (mx.begin()->fi <= l[i])
			mx.erase(mx.begin());
		mx.emplace(l[i], i);
		
		auto lo = mx.upper_bound({k[i], n + 1});
		auto hi = mn.lower_bound({k[i], -1}); hi--;
		
		to[i] = min(lo->se, hi->se) - 1;
	}
	
	auto lo = mx.upper_bound({ini, n + 1});
	auto hi = mn.lower_bound({ini, -1}); hi--;
	inito = min(lo->se, hi->se) - 1;
}

set<ii> aex, bex;
int dp[MX][2];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> n >> m;
	
	forn (i, n) {
		cin >> k[i];
		cin >> al[i] >> ar[i];
		cin >> bl[i] >> br[i];
	}
	
	pre(al, ar, ato, aini, 0);
	pre(bl, br, bto, bini, 0);
	
	aex.emplace(-1, aini);
	bex.emplace(-1, bini);
	
	forn (i, MX) dp[i][0] = dp[i][1] = -2; 
	
	forn (i, n) {
		if (ato[i] < i) bex.clear();
		if (bto[i] < i) aex.clear();
		
		while (aex.size() && aex.rbegin()->se < i) aex.erase(*aex.rbegin());
		while (bex.size() && bex.rbegin()->se < i) bex.erase(*bex.rbegin());
		
		if (aex.size()) dp[i][0] = aex.rbegin()->fi;
		if (bex.size()) dp[i][1] = bex.rbegin()->fi;
		
		if (ato[i] >= i && dp[i][1] != -2) aex.emplace(i, ato[i]);
		if (bto[i] >= i && dp[i][0] != -2) bex.emplace(i, bto[i]);
	}
	
	int f = -1;
	if (dp[n - 1][0] != -2) f = 0;
	if (dp[n - 1][1] != -2) f = 1;
	
	if (f == -1) cout << "No" << endl;
	else {
		int i = n - 1;
		
		while (i >= 0) {
			for (int j = dp[i][f] + 1; j <= i; j++)
				res[j] = 1 - f;
				
			i = dp[i][f];
			f = 1 - f;
		}
		
		cout << "Yes" << endl;
		forn (i, n)
			cout << res[i] << " ";
		cout << endl;
	}
	
	return 0;
}