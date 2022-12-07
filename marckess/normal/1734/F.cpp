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

ll mem[66][2][2][2], n, m;

ll dp (int i, int a, int f, int g) {
	if (i == -1) return g;
	
	ll &res = mem[i][a][f][g];
	if (res != -1) return res;
	
	return res = dp(i - 1, ((n >> i) & 1) ? a ^ 1 : 1, f || ((m - 1) & (1ll << i)), g ^ ((n >> i) & 1))
			   + (f || (((m - 1) >> i) & 1)) * dp(i - 1, ((n >> i) & 1) ? 1 : a ^ 1, f, ((n >> i) & 1) ? g ^ ((a + 1) & 1) : g);
}

void main_() {
	cin >> n >> m;
	memset(mem, -1, sizeof(mem));
	cout << dp(60, 1, 0, 0) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}