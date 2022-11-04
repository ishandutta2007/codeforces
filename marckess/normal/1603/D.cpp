#include <bits/stdc++.h>

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")

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

const int MX = 100005, LG = 17;

struct ST {
	ll mn[4 * MX], lz[4 * MX];
	
	void init () {
		memset(mn, 0, sizeof(mn));
		memset(lz, 0, sizeof(lz));
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		mn[pos] += lz[pos];
		lz[pos] = 0;
	}
	
	void update (int i, int j, int pos, int a, int b, ll k) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return;
		
		if (a <= i && j <= b) {
			lz[pos] = k;
			push(i, j, pos);
			return;
		}
		
		int m = (i + j) / 2;
		update(i, m, pos * 2, a, b, k);
		update(m + 1, j, pos * 2 + 1, a, b, k);
		
		mn[pos] = min(mn[pos * 2], mn[pos * 2 + 1]);
	}
	
	ll query (int i, int j, int pos, int a, int b) {
		if (lz[pos]) push(i, j, pos);
		
		if (b < i || j < a) return 1e18;
		
		if (a <= i && j <= b) return mn[pos];
		
		int m = (i + j) / 2;
		return min(
			query(i, m, pos * 2, a, b),
			query(m + 1, j, pos * 2 + 1, a, b)
		);
	}
}st;

int phi[MX], bs[MX];
ll dp[LG][MX];
vi divi[MX]; 

void main_() {
	int n, k;
	cin >> n >> k;
	
	if (k >= LG) cout << n << endl;
	else cout << dp[k][n] << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	for (int i = 1; i < MX; i++)
		phi[i] = i;
	
	for (int i = 2; i < MX; i++) {
		if (!bs[i])
			for (int j = i; j < MX; j += i) {
				phi[j] -= phi[j] / i;
				bs[j] = 1;
			}
	}

	for (int i = 1; i < MX; i++) {
		dp[1][i] = dp[1][i - 1] + i;
		
		for (int j = i; j < MX; j += i)
			divi[j].pb(i);
	}
	
	for (int j = 2; j < LG; j++) {
		st.init();
		for (int i = 1; i < MX; i++)
			st.update(1, MX, 1, i, i, i < j - 1 ? 1e18 : dp[j - 1][i]);
		
		for (int i = j; i < MX; i++) {
			for (int k = (int)divi[i].size() - 1; divi[i][k] >= j; k--)
				st.update(1, MX, 1, 1, divi[i][k] - 1, phi[i / divi[i][k]]);
			dp[j][i] = st.query(1, MX, 1, 1, i - 1);
		}
	}
	
	int t = 1;
	cin >> t;
	forn (i, t)
		main_();
	
	return 0;
}