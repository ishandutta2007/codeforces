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

const int MX = 5005, mod = 998244353;
int n, k, c[MX][MX];
string s;

int comb (int n, int k) {
	if (n < 0 || k < 0 || n < k) return 0;
	if (k == 0 || n == k) return 1;
	
	int &res = c[n][k];
	if (res != -1) return res;
	
	return res = (comb(n - 1, k) + comb(n - 1, k - 1)) % mod;
}

void sum (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
	if (a < 0)
		a += mod;
}

void main_() {
	cin >> n >> k >> s;
	
	int res = 1;
	
	vi pos;
	forn (i, n)
		if (s[i] == '1')
			pos.pb(i);
	
	if (pos.size() < k) {
		cout << 1 << endl;
		return;
	}
		
	for (int i = (int)pos.size() - 1; i >= 0; i--) {
		for (int j = i; j < (int)pos.size(); j++) {
			int dp = 0;
			
			if (j - i + 1 <= k) {
				int l = i ? pos[i - 1] + 1 : 0;
				int r = j + 1 < pos.size() ? pos[j + 1] - 1 : n - 1;
				
				sum(dp, comb(r - l + 1, j - i + 1) - 1);
				
				if (i < j) {
					sum(dp, -comb(r - pos[i], j - i) + 1);
					sum(dp, -comb(pos[j] - l, j - i) + 1);
				}
				
				if (i + 1 < j) {
					sum(dp, comb(pos[j] - pos[i] - 1, j - i - 1) - 1);
				}
			}
			
			sum(res, dp);
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	memset(c, -1, sizeof(c));
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}