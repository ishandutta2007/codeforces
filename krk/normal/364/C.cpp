#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 1005;
const int Maxp = 31;
const int Maxm = 30005;
const ll Inf = 10000000000000000ll;

bool prime[Maxn];
vector <int> pr;
ll dp[Maxp][Maxm];
int n;

ll Mult(ll a, ll b)
{
	ll res = ll(a) * b;
	return res >= Inf? Inf: res;
}

bool Ok(int n, ll num)
{
	int tk = 0;
	for (ll i = 1; i * i <= num && i <= 2 * n * n; i++)
		if (num % i == 0)
			if (++tk == n) return true;
	return false;
}

void Print(int n, ll num)
{
	vector <ll> seq;
	int tk = 0;
	for (ll i = 1; i * i <= num; i++)
		if (num % i == 0) {
			seq.push_back(i);
			if (++tk == n) break;
		}
	for (int i = 0; i < n; i++)
		printf("%I64d%c", seq[i], i + 1 < n? ' ': '\n');
}

int main()
{
	fill(prime + 2, prime + Maxn, true);
	for (int i = 2; i < Maxn; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxn; j += i) 
			prime[j] = false;
	}
	fill((ll*)dp, (ll*)dp + Maxp * Maxm, Inf);
	dp[0][1] = 1;
	for (int i = 0; i + 1 < Maxp; i++)
		for (int j = 0; j < Maxm; j++) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			for (ll pw = 4, mink = Mult(Mult(Mult(dp[i][j], pr[i]), pr[i]), pr[i]); j * pw < Maxm && mink < Inf; pw++, mink = Mult(mink, pr[i]))
				dp[i + 1][j * pw] = min(dp[i + 1][j * pw], mink);
		}
	scanf("%d", &n);
	for (int j = 2 * n - 1; j < Maxm; j++)
		if (dp[Maxp - 1][j] < Inf && Ok(n, dp[Maxp - 1][j])) {
			Print(n, dp[Maxp - 1][j]); break;
		}
	return 0;
}