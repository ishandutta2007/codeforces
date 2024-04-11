#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 20;
const int Maxm = 50005;
const int mod = 998244353;

int n, m;
int B[Maxn][Maxm];

int toPower(int a, int p)
{
	int res = 1;
	while (p) {
		if (p & 1) res = ll(res) * a % mod;
		p >>= 1; a = ll(a) * a % mod;
	}
	return res;
}

int Inv(int a) { return toPower(a, mod - 2); }

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	int all = 1;
	for (int i = 2; i <= n; i++)
		all = ll(all) * i % mod;
	int res = 0;
	for (int j = 0; j < m; j++) {
		vector <int> seq;
		for (int i = 0; i < n; i++)
			seq.push_back(B[i][j]);
		sort(seq.begin(), seq.end());
		int cur = 0;
		int lst = 1;
		int ans = 1;
		for (int i = 0; i < seq.size(); i++) {
			cur += seq[i] - lst; lst = seq[i];
			ans = ll(ans) * cur % mod;
			cur = (cur - 1 + mod) % mod;
		}
		res = (res + all) % mod;
		res = (res - ans + mod) % mod;
	}
	res = ll(res) * Inv(all) % mod;
	printf("%d\n", res);
    return 0;
}