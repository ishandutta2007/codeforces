#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 10000 + 10;
const int maxk = 5000 + 1;
const int mod = 1000000007;

void add(int &a, int b){
	a += b;
	if (a >= mod)
		a -= mod;
}

void sub(int &a, int b){
	a -= b;
	if (a < 0)
		a += mod;
}

int modpow(int a, int n){
	int ans = 1;

	while (n){
		if (n & 1)
			ans = 1LL * ans * a % mod;

		a = 1LL * a * a % mod;
		n >>= 1;
	}

	return ans;
}

int fak[maxn];
int inv[maxn];

int comb(int n, int k){
	return 1LL * fak[n] * inv[k] % mod * inv[n - k] % mod;
}

int dp[maxk][maxk];
int go[27];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	fak[0] = inv[0] = 1;

	for (int i = 1; i < maxn; ++i){
		fak[i] = 1LL * fak[i - 1] * i % mod;
		inv[i] = modpow(fak[i], mod - 2);
	}

	int n; cin >> n;
	string s; cin >> s;

	string w = "";
	char prev = '*';

	for (auto c : s){
		if (c != prev){
			w += c;
			prev = c;
		}
	}

	int l = (int)w.length();

	go[26] = l;
	for (int i = 0; i < 26; ++i)
		go[i] = -1;

	dp[l][0] = 1;

	for (int i = l - 1; i >= 0; --i){
		int v = w[i] - 'a';

		for (int c = 0; c < 27; ++c){
			if (go[c] == -1 || c == v) continue;
			int p = go[c];

			for (int j = 1; j <= l; ++j)
				add(dp[i][j], dp[p][j - 1]);
		}

		go[v] = i;
	}

	int ans = 0;

	for (int i = 0; i < 26; ++i){
		if (go[i] == -1) continue;
		int pos = go[i];

		for (int j = 1; j <= l; ++j)
			add(ans, 1LL * comb(n - 1, j - 1) * dp[pos][j] % mod );
	}

	cout << ans << endl;

	return 0;
}