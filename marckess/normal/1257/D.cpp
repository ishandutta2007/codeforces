#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, LG = 20;

struct ST {
	int M[MX][LG];
	int n;
	int logTable[MX];

	void pre (int A[], int n) {
		logTable[0] = logTable[1] = 0; 
		for(int i = 2; i <= n; i++)
			logTable[i] = logTable[i >> 1] + 1;
		
		for(int i = 0; i < n; i++)
			M[i][0] = A[i];
	
		for(int j = 1; (1 << j) <= n; j++)
			for(int i = 0; i + (1 << j) - 1 < n;i++)
				M[i][j] = max(M[i][j-1], M[i+(1<<(j-1))][j-1]);
	}

	int query (int i, int j){
		if (i > j) return 0;
		int k = logTable[j-i+1];
		return max(M[i][k], M[j-(1<<k)+1][k]);
	}
}pw, h;

int n, a[MX], m, p[MX], s[MX], x[MX];

int sig (int ini) {
	int i = ini, j = n - 1, rep = 20;
	while (rep--) {
		int m = (i + j + 1) / 2;
		if (h.query(m - ini + 1, n) >= pw.query(ini, m))
			i = m;
		else
			j = m;
	}
	return i;
}

void solve () {
	cin >> n;
	for (int i = 0; i <= n; i++)
		x[i] = 0;

	for (int i = 0; i < n; i++)
		cin >> a[i];
	pw.pre(a, n);

	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> p[i] >> s[i];
		x[s[i]] = max(x[s[i]], p[i]);
	}
	h.pre(x, n + 1);

	int res = 0;
	for (int i = 0; i < n; res++) {
		int j = sig(i);
		if (h.query(j - i + 1, n) < pw.query(i, j)) {
			cout << -1 << endl;
			return;
		}
		i = j + 1;
	}
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}