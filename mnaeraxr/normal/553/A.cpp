#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout << #x << " = " << x << endl << flush;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const int64 MOD = (int64)1e9 + 7;

int64 dp[1010][1010];
int64 fact[1010];

int64 modexp(int64 a, int64 p){
	if (!p) return 1LL;
	int64 ans = modexp(a * a % MOD, p / 2);
	if (p & 1) ans = ans * a % MOD;
	return ans;
}

int64 comb(int a, int b){
	return fact[a] * modexp(fact[b], MOD - 2) % MOD * modexp(fact[a - b], MOD - 2) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int k; cin >> k;
	vector<int> V(k + 1);
	vector<int> S(k + 1);
	for (int i = 1; i <= k; ++i){
		cin >> V[i];
		S[i] = S[i - 1] + V[i];
	}
	int n = S[k];
	fact[0] = 1;
	for (int i = 1; i <= n; ++i)
		fact[i] = fact[i - 1] * i % MOD;

	dp[0][0] = 1;

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= k; ++j){
			if (S[j] > i) break;
			dp[i][j] = (j ? (dp[i - 1][j - 1] * comb(i - 1 - S[j - 1], V[j] - 1)) : 0);
			dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
		}
	}

	cout << dp[n][k] << endl;

	return 0;
}