#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], f[MX];
ll res = 0;

int st[MX][18];

int query (int i, int j) {
	int k = log2(j - i + 1);
	if (p[st[i][k]] > p[st[j-(1<<k)+1][k]])
		return st[i][k];
	else
		return st[j-(1<<k)+1][k];
}

void solve (int i, int j) {
	if (j - i + 1 < 3) return;
	int m = query(i, j);

	if (m - i < j - m) {
		for (int k = i; k < m; k++)
			if (m < f[p[m] - p[k]] && f[p[m] - p[k]] <= j)
				res++;
	} else {
		for (int k = m + 1; k <= j; k++)
			if (i <= f[p[m] - p[k]] && f[p[m] - p[k]] < m)
				res++;
	}

	solve(i, m - 1);
	solve(m + 1, j);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
		f[p[i]] = i;
		st[i][0] = i;
	}

	for (int j = 1; (1 << j) <= n; j++)
		for (int i = 1; i + (1 << j) - 1 <= n; i++)
			if (p[st[i][j-1]] > p[st[i+(1<<(j-1))][j-1]])
				st[i][j] = st[i][j-1];
			else 
				st[i][j] = st[i+(1<<(j-1))][j-1];

	solve(1, n);
	cout << res << endl;

	return 0;
}