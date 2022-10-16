#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define DB(x) cout<<#x<<"="<<x<<endl;
#define SZ(x) (int)((x).size())
#define MP make_pair

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double EPS = 1e-9;
const int MAXN = (int)1e5 + 10;
const int64 MOD = (int64)1e9 + 7;

int64 TEN_POW[MAXN];
int64 MOD_INV[MAXN];
int64 FACT[MAXN];
int64 INV_FACT[MAXN];
int64 ACC[MAXN];

int64 comb(int n, int p){
	if (p > n) return 0;
	return (((FACT[n] * INV_FACT[p]) % MOD) * INV_FACT[n - p]) % MOD;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	MOD_INV[1] = 1;
	for (int i = 2; i < MAXN; i++)
		MOD_INV[i] = (MOD - (MOD / i) * MOD_INV[MOD % i] % MOD) % MOD;

	TEN_POW[0] = FACT[0] = INV_FACT[0] = 1;

	for (int i = 1; i < MAXN; ++i){
		FACT[i] = (FACT[i - 1] * i) % MOD;
		INV_FACT[i] = (INV_FACT[i - 1] * MOD_INV[i]) % MOD;
		TEN_POW[i] = (TEN_POW[i - 1] * 10) % MOD;
	}

	int n, t;
	string s;

	cin >> n >> t;
	cin >> s;

	ACC[0] = comb(n - 2, t - 1);

	for (int i = 1; t - 1 <= n - i - 2; ++i){
		ACC[i] = (ACC[i - 1] + (TEN_POW[i] * comb(n - i - 2, t - 1)) % MOD) % MOD;
	}

	int64 ans = 0;
	for (int k = 0; k < n; ++k){
		int64 cur = 0;
		cur = ((s[k] - '0') * ((ACC[ min(n - k - 2, n - t - 1)] + (comb(k, t) * TEN_POW[n - k - 1]) % MOD)) % MOD) % MOD;
		ans = (ans + cur) % MOD;
	}

	cout << ans << endl;

	return 0;
}