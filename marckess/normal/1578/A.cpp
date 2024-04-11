
// Problem : A. Portal
// Contest : Codeforces - Codeforces Round #745 (Div. 1)
// URL : https://codeforces.com/contest/1580/problem/A
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

const int MX = 405;
int n, m, acu[MX][MX], sum[MX];
char a[MX][MX];

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n)
		forn (j, m) {
			acu[i][j] = a[i][j] - '0';
			if (i)
				acu[i][j] += acu[i - 1][j];
		}
	
	int res = 1e9;
	forn (i, n) forn (j, n) if (j - i + 1 >= 5) {
		int mn = 1e9;
		
		forn (k, m) {
			sum[k] = acu[j - 1][k] - acu[i][k];
			sum[k] += '1' - a[j][k];
			sum[k] += '1' - a[i][k];
			if (k) sum[k] += sum[k - 1];
			
			res = min(res, mn + (j - i - 1) - (acu[j - 1][k] - acu[i][k]));
			
			if (k >= 2) {
				mn = min(
					mn + sum[k] - sum[k - 1],
					sum[k] - sum[k - 2] + (j - i - 1) - (acu[j - 1][k - 2] - acu[i][k - 2])
				);
			}
		}
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