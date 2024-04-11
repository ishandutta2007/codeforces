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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
int n, m, a[MX];
vvi mem;

struct ST {
	ii mx[4 * MX];
	
	void build (int i, int j, int pos, int a[]) {
		if (i == j) {
			mx[pos] = {a[i], -i};
			return;
		}
		
		int m = (i + j) / 2;
		build(i, m, pos * 2, a);
		build(m + 1, j, pos * 2 + 1, a);
		
		mx[pos] = max(mx[pos * 2], mx[pos * 2 + 1]);
	}
	
	ii query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a) return {-1e9, 1e9};
		
		if (a <= i && j <= b) return mx[pos];
		
		int m = (i + j) / 2;
		ii x = query(i, m, pos * 2, a, b);
		ii y = query(m + 1, j, pos * 2 + 1, a, b);
		
		return max(x, y);
	}
}st;

ll dp (int a, int b, int j) {
	if (a > b) return 1; 
	if (j <= 0) return 0;
	
	int i = -st.query(1, n, 1, a, b).se;
	
	ll &res = mem[i][j];
	if (res != -1) return res;
	
	return res = (dp(a, b, j - 1) + dp(a, i - 1, j - 1) * dp(i + 1, b, j)) % mod;
}

void main_() {
	cin >> n >> m;
	forr (i, 1, n)
		cin >> a[i];
	
	st.build(1, n, 1, a);
	mem = vvi(n + 1, vi(m + 1, -1));
	cout << dp(1, n, m) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}