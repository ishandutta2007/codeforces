
// Problem : C. Paint
// Contest : Codeforces - Codeforces Round #743 (Div. 1)
// URL : https://codeforces.com/contest/1572/problem/C
// Memory Limit : 256 MB
// Time Limit : 1000 ms
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

const int MX = 3005;
int n, a[MX], mem[MX][MX], ind[MX];
vi pos[MX];

int dp (int i, int j) {
	if (i > j) return 0;
	
	int &res = mem[i][j];
	if (res != -1) return res;
	res = dp(i, j - 1);
	
	for (int k = ind[j] - 1, x; k >= 0 && (x = pos[a[j]][k]) >= i; k--)
		res = max(res, dp(i, x) + dp(x + 1, j - 1) + 1);
	
	return res;
}

void main_() {
	cin >> n;
	
	forn (i, n + 1)
		pos[i].clear();
	
	forn (i, n) {
		cin >> a[i];
		
		ind[i] = pos[a[i]].size();
		pos[a[i]].pb(i);
	}
	
	forn (i, n)
		forn (j, n)
			mem[i][j] = -1;
	
	cout << n - 1 - dp(0, n - 1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}