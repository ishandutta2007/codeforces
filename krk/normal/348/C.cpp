#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxp = 318;

int n, m, q;
ll a[Maxn];
vector <int> S[Maxn];
vector <int> insets[Maxn];
int spec[Maxn], rl[Maxp], slen;
ll sum[Maxn], got[Maxn], gives[Maxn];
int tims[Maxn][Maxp];

ll getRes(int ind)
{
	if (spec[ind]) return sum[ind] + got[ind] + ll(S[ind].size()) * gives[ind];
	else {
		ll res = 0ll;
		for (int i = 0; i < S[ind].size(); i++)
			res += a[S[ind][i]];
		for (int i = 1; i <= slen; i++)
			res += ll(tims[ind][i]) * gives[rl[i]];
		return res;
	}
}

void Update(int ind, int x)
{
	if (spec[ind]) gives[ind] += x;
	else for (int i = 0; i < S[ind].size(); i++)
			a[S[ind][i]] += x;
	for (int i = 1; i <= slen; i++)
		got[rl[i]] += ll(tims[ind][i]) * x;
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		scanf("%I64d", &a[i]);
	for (int i = 1; i <= m; i++) {
		int k; scanf("%d", &k);
		S[i].resize(k);
		for (int j = 0; j < k; j++) {
			scanf("%d", &S[i][j]);
			insets[S[i][j]].push_back(i);
			sum[i] += a[S[i][j]];
		}
		if (k >= Maxp) { slen++; spec[i] = slen; rl[slen] = i; }
	}
	for (int j = 1; j <= slen; j++)
		for (int l = 0; l < S[rl[j]].size(); l++) {
			int ind = S[rl[j]][l];
			for (int k = 0; k < insets[ind].size(); k++) {
				int i = insets[ind][k];
				if (i != rl[j]) tims[i][j]++;
			}
		}
	for (int i = 1; i <= q; i++) {
		char op; int k, x;
		scanf(" %c %d", &op, &k);
		if (op == '?') printf("%I64d\n", getRes(k));
		else { scanf("%d", &x); Update(k, x); }
	}
	return 0;
}