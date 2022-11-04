// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 105;
int n, k[MX], h[MX];
ll mem[MX];

ll dp (int i) {
	if (i == n + 1) return 0;
	
	ll &res = mem[i];
	if (res != -1) return res;
	res = 1e18;
	
	ll act = 0;
	for (int j = i; j <= n; j++) {
		if (k[j] - k[i - 1] < h[j]) break;
		act = max(act + (j > i ? k[j] - k[j - 1] : 0), 1ll * h[j]);
		
		res = min(res, act * (act + 1) / 2 + dp(j + 1));
	}
	
	return res;
}

void main_() {
	cin >> n;
	forn (i, n) cin >> k[i + 1];
	forn (i, n) cin >> h[i + 1];
	
	memset(mem, -1, sizeof(mem));
	cout << dp(1) << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}