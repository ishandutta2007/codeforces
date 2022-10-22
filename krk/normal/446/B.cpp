#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 1005;
const int Maxk = 1000005;

int n, m, k, p;
int a[Maxn][Maxn];
ll rows[Maxn], cols[Maxn];
ll tkr[Maxk], tkc[Maxk];
ll res;

void Phase1()
{
	priority_queue <lli> Q;
	for (int i = 0; i < n; i++)
		Q.push(lli(rows[i], i));
	for (int i = 1; i <= k; i++) {
		lli tp = Q.top(); Q.pop();
		tkr[i] = tkr[i - 1] + tp.first;
		tp.first -= ll(m) * p;
		Q.push(tp);
	}
}

void Phase2()
{
	priority_queue <lli> Q;
	for (int j = 0; j < m; j++)
		Q.push(lli(cols[j], j));
	res = tkr[k];
	for (int i = 1; i <= k; i++) {
		lli tp = Q.top(); Q.pop();
		tkc[i] = tkc[i - 1] + tp.first;
		tp.first -= ll(n) * p;
		Q.push(tp);
		int j = k - i;
		res = max(res, tkc[i] + tkr[j] - ll(i) * j * p);
	}
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &p);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &a[i][j]);
			rows[i] += a[i][j];
			cols[j] += a[i][j];
		}
	Phase1();
	Phase2();
	printf("%I64d\n", res);
	return 0;
}