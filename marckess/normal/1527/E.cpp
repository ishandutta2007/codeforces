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

const int MX = 35005;

struct ST {
	ll st[4 * MX], lz[4 * MX];
	
	void init () {
		memset(st, 0, sizeof(st));
		memset(lz, 0, sizeof(lz));
	}
	
	void push (int i, int j, int pos) {
		if (i < j) {
			lz[pos * 2] += lz[pos];
			lz[pos * 2 + 1] += lz[pos];
		}
		
		st[pos] += lz[pos];
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
		
		st[pos] = min(st[pos * 2], st[pos * 2 + 1]);
	}
}st;

int n, k, a[MX], ini[MX], last[MX], acu[MX];
ll dp[105][MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	memset(ini, -1, sizeof(ini));
	
	for (int i = 1; i <= n; i++) {
		dp[1][i] = dp[1][i - 1] - acu[a[i]];
		
		if (ini[a[i]] == -1)
			ini[a[i]] = i;
		
		dp[1][i] += i - ini[a[i]];
		acu[a[i]] = i - ini[a[i]];
	}
	
	for (int j = 2; j <= k; j++) {
		memset(last, -1, sizeof(last));
		dp[j][0] = 1e18;
		
		st.init();
		st.update(1, n, 1, 1, n, 1e18);
		
		for (int i = 1; i <= n; i++) {
			st.update(1, n, 1, i, i, -1e18 + dp[j - 1][i - 1]);
			
			if (last[a[i]] != -1) {
				st.update(1, n, 1, last[a[i]] + 1, i, -i);
				
				st.update(1, n, 1, 1, last[a[i]], -last[a[i]]);
				st.update(1, n, 1, 1, i, i);
			}
			
			last[a[i]] = i;
			
			dp[j][i] = st.st[1];
		}
	}
	
	cout << dp[k][n] << endl;
	
	return 0;
}