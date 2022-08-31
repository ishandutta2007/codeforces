#include <iostream>
#include <vector>
using namespace std;


vector <int> q[80500];
vector <unsigned long long> cnt1[80500];
unsigned long long cntInSubTree[80500];
int n;

int dfs(int v, int pr = -1)
{
	int len = q[v].size();
	cntInSubTree[v] = 1;
	for (int i = 0; i < len; i++)
	{
		int nx = q[v][i];
		if (nx == pr)
			continue;
		cntInSubTree[v] += dfs(nx, v);
	}
	return cntInSubTree[v];
}

unsigned long long getAns(int v, int pr = -1)
{
	int len = q[v].size();

	unsigned long long ans = 0;
	cnt1[v].resize(len, 0);
	unsigned long long CNT1 = 0;
	unsigned long long x = cntInSubTree[v];
	unsigned long long CNTUP = n - x;

	for (int i = 0; i < len; i++)
	{
		int nx = q[v][i];
		if (nx == pr)
		{
			cnt1[v][i] = CNTUP;
			continue;
		}
		unsigned long long cis = cntInSubTree[nx];
		if (cis > 0)
			cnt1[v][i] = cis * (cis - 1) / 2;
		CNT1 += cnt1[v][i];
	}
	for (int i = 0; i < len; i++)
	{
		int nx = q[v][i];
		if (nx == pr)
			continue;
		ans += CNT1 * cnt1[v][i];
		ans -= cnt1[v][i] * cnt1[v][i];
	}
	CNT1 += CNTUP * (CNTUP - 1) / 2;
	
	for (int i = 0; i < len; i++)
	{
		int nx = q[v][i];
		if (nx == pr)
			continue;
		unsigned long long curcnt = n - cntInSubTree[nx];
		unsigned long long curans = curcnt * (curcnt - 1) / 2;
		curans -= CNT1;
		curans += cnt1[v][i];

		ans += curans * cnt1[v][i] * 2;
	}
	

	for (int i = 0; i < len; i++)
	{
		int nx = q[v][i];
		if (nx == pr)
			continue;
		ans += getAns(nx, v);
	}

	return ans;
}

int main()
{

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		q[a].push_back(b);
		q[b].push_back(a);
	}


	dfs(0);
	unsigned long long ans = getAns(0);

	printf("%I64u", ans);

	return 0;
}