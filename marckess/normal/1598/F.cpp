
// Problem : F. RBS
// Contest : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1598/problem/F
// Memory Limit : 512 MB
// Time Limit : 3000 ms
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

const int MX = 20, MA = 400005;
int n, mem[1 << MX], mn[MX], sum[MX], mp[MX][2 * MA];

int dp (int mk) {
	if (__builtin_popcount(mk) == n) return 0;
	
	int &res = mem[mk];
	if (res != -1) return res;
	res = 0;
	
	int s = 0;
	forn (i, n)
		if (mk & (1 << i))
			s += sum[i];
	
	forn (i, n)
		if (~mk & (1 << i)) {
			if (s + mn[i] < 0) {
				res = max(res, mp[i][MA - s]);
			} else {
				res = max(res, dp(mk | (1 << i)) + mp[i][MA - s]);
			}
		}
	
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		string s;
		cin >> s;
		
		for (char c : s) {
			if (c == '(') sum[i]++;
			else sum[i]--;
			
			if (sum[i] <= mn[i]) {
				mp[i][MA + sum[i]]++;
				mn[i] = sum[i];
			}
		}
	}
	
	memset(mem, -1, sizeof(mem));
	cout << dp(0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}