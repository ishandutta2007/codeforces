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

const int lim = 1 << 20, MX = (1 << 20) + 5;
int n, _n, k, res[MX], cont[MX], mem[40][MX];
ll b[MX], a[MX];

int comb (int n, int k) {
	int cn = cont[n] - cont[k] - cont[n - k];
	return cn == 0;
}

int dp (int n, int k) {
	k = max(k, 0);
	if (n < k) return 0;
	
	int &res = mem[_n - n][k];
	if (res != -1) return res;
	
	res = dp(n, k + 1) ^ comb(n, k);
	
	return res;
}

void main_() {
	cin >> n >> k;
	_n = n;
	
	forn (i, n) {
		cin >> b[i];
		
		if (b[i] > 20) a[i] = lim;
		else a[i] = 1 << b[i];
	}
	
	memset(mem, -1, sizeof(mem));
	forn (i, n) {
		ll p = b[i];
		
		for (int j = i; j < n; j++) {
			if (i < j) (p *= a[j]);
			if (p >= lim)
				break;
			
			int kk = k;
			int nn = n - 1 - (j - i);
			
			if (i) kk--, nn--;
			if (j + 1 < n) kk--, nn--;
			
			if (dp(nn, kk))
				res[p] ^= 1;
		}
	}
	
	int f = 0;
	for (int i = lim - 1; i >= 0; i--)
		if (f) {
			cout << res[i];
		} else if (res[i]) {
			f = 1;
			cout << res[i];
		}
	
	if (!f) cout << 0;
	cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	forn (i, MX) {
		int x = i;
		while (x >= 2) {
			cont[i] += x / 2;
			x /= 2;
		}
	}
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}