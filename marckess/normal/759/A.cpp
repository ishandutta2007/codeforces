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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005;
int n, p[MX], b[MX], vis[MX], res;

void dfs (int u) {
	if (vis[u]) return;
	vis[u] = 1;
	dfs(p[u]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> p[i];

	for (int i = 1; i <= n; i++)
		if (!vis[i]) {
			res++;
			dfs(i);
		}

	if (res < 2) res = 0;

	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		b[i] ^= b[i-1];
	}

	if (!b[n]) res++;

	cout << res << endl;

	return 0;
}