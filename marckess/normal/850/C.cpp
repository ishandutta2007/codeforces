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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, a[MX], res;
set<int> st;
map<int, int> mem;

void fac (int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			st.insert(i);
			while (n % i == 0)
				n /= i;
		}

	if (n > 1) st.insert(n);
}

int dp (int mk) {
	if (!mk) return 0;

	if (mem.count(mk)) return mem[mk];

	int st = 0;

	for (int i = 0; (1ll << i) <= mk; i++) {
		int aux = 0;

		for (int j = 0; (1ll << j) <= mk; j++) {
			if (!(mk & (1ll << j))) continue;

			if (i > j) {
				aux |= (1 << j);
			} else if (i < j) {
				aux |= (1 << (j - i - 1));
			}
		}

		st |= 1 << dp(aux);
	}

	for (int i = 0;; i++)
		if (!(st & (1 << i)))
			return mem[mk] = i;
}

int solve (int p) {
	int mk = 0;
	forn (i, n) {
		int pw = 0;
		while (a[i] % p == 0) {
			a[i] /= p;
			pw++;
		}
		mk |= (1 << pw);
	}
	return dp(mk / 2);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> a[i];
		fac(a[i]);
	}

	for (int x : st)
		res ^= solve(x);

	if (res) cout << "Mojtaba" << endl;
	else cout << "Arpa" << endl;

	return 0;
}