#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;

const int64 MOD = 1000000007LL;
const int MAXN = 400100;

int64 modexp(int64 v, int64 p){
	if (!p) return 1LL;
	int64 ans = modexp(v * v % MOD, p / 2);
	if (p & 1) ans = ans * v % MOD;
	return ans;
}

int64 F[MAXN];
int64 iF[MAXN];
pii LST[MAXN];

int64 tot(int n, int m){
	return F[n + m] * iF[n] % MOD * iF[m] % MOD;
}

int64 dp[MAXN];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	F[0] = iF[0] = 1;
	for (int i = 1; i < MAXN; ++i){
		F[i] = F[i - 1] * i % MOD;
		iF[i] = modexp(F[i], MOD - 2);
	}

	int w, h;
	int n; cin >> w >> h >> n;
	for (int i = 0; i < n; ++i){
		cin >> LST[i].first >> LST[i].second;		
	}
	LST[n++] = make_pair(w, h);
	sort(LST, LST + n);

	for (int i = 0; i < n; ++i){
		int x = LST[i].first, y = LST[i].second;
		dp[i] = tot(x - 1, y - 1);
		for (int j = 0; j < i; ++j){
			if (LST[j].first <= x && LST[j].second <= y){
				int64 tmp = dp[j] * tot(x - LST[j].first, y - LST[j].second) % MOD;
				dp[i] = (dp[i] - tmp + MOD) % MOD;
			}
		}
		// cout << x << " " << y << " " << dp[i] << endl;
	}

	cout << dp[n - 1] << endl;

	return 0;
}