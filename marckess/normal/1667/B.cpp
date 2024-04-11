// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 500005;
int n;
ll a[MX], acu[MX], dp[MX];

struct ST {
	ll mx[4 * MX];
	
	void build (int i, int j, int pos) {
		mx[pos] = -1e18;
		
		if (i < j) {
			int m = (i + j) / 2;
			build(i, m, pos * 2);
			build(m + 1, j, pos * 2 + 1);
		}
	}
	
	void update (int i, int j, int pos, int a, ll k) {
		if (a < i || j < a) return;
		
		if (i == j) {
			mx[pos] = max(k, mx[pos]);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, k);
		update(m + 1, j, pos * 2 + 1, a, k);
		
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ll query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return -1e18;
		
		if (a <= i && j <= b) return mx[pos];
		
		int m = (i + j) / 2;
		ll x = query(i, m, pos * 2, a, b);
		ll y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return max(x, y);
	}
}neg, cer, pos;

vi st;

void main_() {
	cin >> n;
	forr (i, 1, n)
		cin >> a[i];
	
	st = {0};
	forr (i, 1, n) {
		acu[i] = acu[i - 1] + a[i];
		st.pb(acu[i]);
	}
	
	sort(all(st));
	neg.build(1, n + 1, 1);
	cer.build(1, n + 1, 1);
	pos.build(1, n + 1, 1);
	
	dp[n + 1] = 0;
	for (int i = n; i >= 1; i--) {
		dp[i] = -1e18;
		int j = upper_bound(all(st), acu[i]) - st.begin();
		
		pos.update(1, n + 1, 1, j, i + 1 + dp[i + 1]);
		cer.update(1, n + 1, 1, j, dp[i + 1]);
		neg.update(1, n + 1, 1, j, -i - 1 + dp[i + 1]);
		
		j = upper_bound(all(st), acu[i - 1]) - st.begin();
		
		if (j <= n)
			dp[i] = max(dp[i], pos.query(1, n + 1, 1, j + 1, n + 1) - i);
		
		dp[i] = max(dp[i], cer.query(1, n + 1, 1, j, j));
		
		if (1 < j)
			dp[i] = max(dp[i], neg.query(1, n + 1, 1, 1, j - 1) + i);
	}
	
	cout << dp[1] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}