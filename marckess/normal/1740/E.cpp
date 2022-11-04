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

const int MX = 100005;
int n, p[MX], mem[MX][2];
vi adj[MX];

int dp (int u, int f) {
	int &res = mem[u][f];
	if (res != -1) return res;
	res = 0;
	
	if (!f) {
		res = 0;
		
		for (int v : adj[u])
			res += dp(v, 0);
		
		res = max(res, dp(u, 1));
	} else {
		res = 0;
		
		for (int v : adj[u])
			res = max(res, dp(v, 1));
		
		res++;
	}
	
	return res;
}

void main_() {
	cin >> n;
	forr (i, 2, n) {
		cin >> p[i];
		adj[p[i]].pb(i);
	}
	
	memset(mem, -1, sizeof(mem));
	cout << dp(1, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}