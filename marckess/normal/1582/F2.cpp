
// Problem : F2. Korney Korneevich and XOR (hard version)
// Contest : Codeforces - Codeforces Round #750 (Div. 2)
// URL : https://codeforces.com/contest/1582/problem/F2
// Memory Limit : 512 MB
// Time Limit : 1500 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

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

const int MX = 1000005, lim = 1 << 13;
int n, a[MX], sig[MX], cn[MX], dp[lim], nex[lim];
set<int> st;
vi pos[lim];

void main_() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	forn (i, lim)
		dp[i] = MX;
		
	dp[0] = 0;
	st.insert(0);
	cn[0]++;
	
	forn (j, lim) {
		if (!j || !pos[j].size()) continue;
		
		forn (i, lim)
			nex[i] = dp[i];
		
		int i = 0;
		for (int x : st) {
			while (i < pos[j].size() && pos[j][i] <= x)
				i++;
			
			if (i == pos[j].size()) sig[x] = MX;
			else sig[x] = pos[j][i];
		}
		
		forn (i, lim) {
			if (dp[i] == MX) continue;
			if (nex[i ^ j] <= sig[dp[i]]) continue;
			
			if (nex[i ^ j] < MX) {
				if (!(--cn[nex[i ^ j]]))
					st.erase(nex[i ^ j]);
			}
			
			nex[i ^ j] = sig[dp[i]];
			
			if ((++cn[sig[dp[i]]]) == 1)
				st.insert(sig[dp[i]]);
		}
		
		forn (i, lim)
			dp[i] = nex[i]; 
	}
	
	vi res;
	forn (i, lim)
		if (dp[i] < MX)
			res.pb(i);
	
	cout << res.size() << endl;
	for (int x : res)
		cout << x << " ";
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}