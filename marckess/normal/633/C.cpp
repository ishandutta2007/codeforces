#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1000100;
int sig[MX][26], f[MX], sz = 1;

int n, m, dp[10005], rec[10005];
string s, w[100005];

void insert (string &s, int ind) {
	int i = 0;

	for (char c : s) {
		if ('A' <= c && c <= 'Z') c -= 'A';
		else c -= 'a';

		if (!sig[i][c]) sig[i][c] = sz++;
		i = sig[i][c];
	}

	f[i] = ind;
}

void find (int j, int go) {
	int i = 0;

	while (j >= 0) {
		int c = s[j] - 'a';

		if (!sig[i][c]) break;
		i = sig[i][c];
	
		if (f[i] != -1) {
			dp[j] = go;
			rec[j] = f[i];
		}
		j--;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	for (int i = 0; i < MX; i++) f[i] = -1;
	for (int i = 0; i < 10005; i++) dp[i] = -1;

	cin >> n >> s >> m;
	for (int i = 0; i < m; i++) {
		cin >> w[i];
		insert(w[i], i);
	}

	for (int i = n-1; i >= 0; i--)
		if (dp[i+1] != -1 || i + 1 == n)
			find(i, i+1);

	for (int i = 0; dp[i] != -1; i = dp[i])
		cout << w[rec[i]] << " ";
	cout << endl;

	return 0;
}