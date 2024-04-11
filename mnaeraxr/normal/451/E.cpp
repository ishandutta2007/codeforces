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

int64 inv[51];
map<int64,int64> my_coeff;
int64 f[50], n, s;

void build(int64 p, int64 coeff, int64 sg)
{
	if (p == n){
		my_coeff[coeff] += sg;
		my_coeff[coeff] %= MOD;
	}
	else{
		build(p + 1, coeff, sg);
		build(p + 1, coeff + f[p] + 1, (sg * -1 % MOD + MOD) % MOD);
	}
}

int64 combinatoric(int64 n, int64 p){
	if (n < p) return 0;
	p = min(p, n - p);
	int64 ans = 1LL;
	for (int i = 0; i < p; ++i){
		ans = (ans * ((n - 1LL * i)%MOD)) % MOD;
		ans = (ans * inv[i + 1]) % MOD;
	}
	return ans;
}

int print;

int64 solve()
{
	int64 ans = 0;
	for (auto &p : my_coeff)
	{
		int64 _power = p.first;
		int64 _coeff = p.second;
		int64 cur_s = s - _power;

		if (cur_s < 0) continue;
		ans += _coeff * combinatoric(n + cur_s - 1, cur_s) % MOD;
		ans %= MOD;
	}
	return ans;
}

int64 modexp(int64 v, int64 p){
	if (p == 0) return 1LL;
	int64 r = modexp(v * v % MOD, p >> 1);
	if (p & 1) r = r * v % MOD;
	return r;
}
/*
20 4385085334307
273634411136 208521328637 450482376435 844118010709 197241285878 472126475472 2414038897 672334205413 809269727018 409013884362 739986692075 953956651947 462216461906 388007176838 245504550965 527140291750 632844435887 550532123833 757200390348 944901802640
 */
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 1; i <= 50; ++i)
		inv[i] = modexp(1LL * i, MOD - 2);

	cin >> n >> s;

	for (int i = 0; i < n; ++i)
		cin >> f[i];

	build(0, 0, 1LL);

	cout << solve() << endl;

	return 0;
}