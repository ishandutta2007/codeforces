#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 26;
const int Maxf = 19;

int n, k;
ll S;
ll C[Maxn][Maxn];
int cnt[Maxf];
vector <int> ex;
vector <int> oth;
vector <int> nex;
int sum[Maxf];
ll fac[Maxf];

ll Gen3(int lvl, ll S)
{
	//if (S > sum[lvl]) return 0ll;
	if (lvl == nex.size()) return int(S == 0);
	ll res = 0ll;
	ll remS = 0ll;
	for (int i = 0; i <= cnt[nex[lvl]] && remS <= S; i++) {
		res += C[cnt[nex[lvl]]][i] * Gen3(lvl + 1, S - remS);
		remS += nex[lvl];
	}
	return res;
}

ll Solve(ll S)
{
	/*sum[nex.size()] = 0;
	for (int i = int(nex.size()) - 1; i >= 0; i--)
		sum[i] = sum[i + 1] + nex[i] * cnt[nex[i]];*/
	return Gen3(0, S);
}

ll Gen2(int lvl, int k, ll S)
{
	if (lvl == ex.size()) return S <= 450? Solve(S): 0;
	nex.push_back(ex[lvl]);
	ll res = 0ll;
	ll remS = 0ll;
	int i;
	for (i = 0; i <= k && i <= cnt[ex[lvl]] && remS <= S; i++) {
		if (i == cnt[ex[lvl]]) nex.pop_back();
		cnt[ex[lvl]] -= i;
		res += C[cnt[ex[lvl]] + i][i] * Gen2(lvl + 1, k - i, S - remS);
		cnt[ex[lvl]] += i;
		remS += fac[ex[lvl]];
	}
	if (i <= cnt[ex[lvl]]) nex.pop_back();
	return res;
}

ll Gen1(int lvl, int k, ll S)
{
	if (lvl == oth.size()) return Gen2(0, k, S);
	ll res = Gen1(lvl + 1, k, S);
	if (oth[lvl] <= S) res += Gen1(lvl + 1, k, S - oth[lvl]);
	return res;
}

int main()
{
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
	}
	scanf("%d %d %I64d", &n, &k, &S);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		if (a >= Maxf) oth.push_back(a);
		else cnt[a]++;
	}
	fac[0] = 1;
	for (int i = 1; i < Maxf; i++)
		fac[i] = ll(fac[i - 1]) * i;
	for (int i = Maxf - 1; i >= 1; i--)
		if (cnt[i]) ex.push_back(i);
	printf("%I64d\n", Gen1(0, k, S));
	return 0;
}