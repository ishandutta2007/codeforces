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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 5005;
int n, a[MX], pos[MX][MX], dp[MX], cn[MX];

void main_() {
	cin >> n;
	forr (i, 1, n)
		cin >> a[i];
	
	forr (i, 1, n) {
		int mx = 0;
		
		forr (j, i, n) {
			mx = max(mx, ++cn[a[j]]);
			pos[i][j] = 2 * mx <= j - i + 1;
		}
		
		forr (j, i, n)
			cn[a[j]] = 0;
	}
	
	int res = 0;
	
	forr (i, 1, n) {
		dp[n + 1] = 0;
		
		for (int j = n; j >= 1; j--) {
			int &act = dp[j];
			act = -1e9;
			if (a[j] != i && j > 1 && a[j - 1] != i)
				continue;
			
			if (a[j] == i)
				act = max(act, 1 + dp[j + 1]);
			
			for (int k = j + 1; k <= n; k += 2)
				if (pos[j][k])
					act = max(act, dp[k + 1]);
		}
		
		res = max(res, dp[1]);
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