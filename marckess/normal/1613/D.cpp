
// Problem : D. MEX Sequences
// Contest : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1613/problem/D
// Memory Limit : 256 MB
// Time Limit : 2000 ms
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

const int MX = 500010, mod = 998244353;
int n, a[MX], mem[MX][3][2];
vi pos[MX];

void sum (int &a, int b) {
	a += b;
	if (a >= mod)
		a -= mod;
}

int dp(int i, int j, int k);
void tran (int &res, int i, int x, int y) {
	if (x < 0) return;
	
	auto it = upper_bound(all(pos[x]), i);
	if (it != pos[x].end())
		sum(res, dp(*it, y, 1)); 
} 

int dp (int i, int j, int k) {
	int &res = mem[i][j][k];
	if (res != -1) return res;
	
	if (k) {
		res = dp(i, j, 0);
		tran(res, i, a[i], j);
		return res;
	}
	
	res = 1;
	
	if (j == 0) {
		tran(res, i, a[i], 0);
		tran(res, i, a[i] + 1, 0);
		tran(res, i, a[i] + 2, 2);
	} else if (j == 1) {
		tran(res, i, a[i], 1);
		tran(res, i, a[i] + 2, 2);
	} else {
		tran(res, i, a[i], 2);
		tran(res, i, a[i] - 2, 1);
	}
	
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n + 5) {
		pos[i].clear();
		memset(mem[i], -1, sizeof(mem[i]));
	}
	
	forn (i, n) {
		cin >> a[i];
		pos[a[i]].pb(i);
	}
	
	int res = 0;
	forn (i, n) {
		if (a[i] == 0) sum(res, dp(i, 0, 0));
		if (a[i] == 1) sum(res, dp(i, 2, 0));
	}
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}