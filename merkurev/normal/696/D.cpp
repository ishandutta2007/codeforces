#define _CRT_SECURE_NO_WARNINGS

#ifndef ONLINE_JUDGE
#pragma comment(linker, "/STACK:100500500")
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


#ifndef ONLINE_JUDGE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define epritnf(...) 42;
#endif

const int K = 205;
const long long INF = (long long) 1e18;

struct Matr
{
	long long a[K][K];
	Matr() : a() {}

	static Matr ONE()
	{
		Matr ans = Matr();
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				if (i != j)
					ans.a[i][j] = -INF;
		return ans;
	}

	Matr operator * (const Matr &A) const
	{
		Matr ans = ONE();
		for (int i = 0; i < K; i++)
			for (int j = 0; j < K; j++)
				for (int h = 0; h < K; h++)
					ans.a[i][j] = max(ans.a[i][j], a[i][h] + A.a[h][j] );
		return ans;
	}

	Matr fpow(long long n)
	{
		Matr ans = ONE();
		Matr cur = *this;
		for (int i = 0; (1LL << i) <= n; i++)
		{
			if (n & (1LL << i))
				ans = ans * cur;
			cur = cur * cur;
		}
		return ans;
	}
};

const int ALP = 26;
int goTo[K][ALP];
int sz = 1;
int term[K];
int suffLink[K];
int par[K], parCh[K];

int a[K];
char str[K];

void addWord(int cost)
{
	int v = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		int cur = str[i] - 'a';
		if (goTo[v][cur] == 0)
		{
			par[sz] = v;
			parCh[sz] = cur;
			goTo[v][cur] = sz++;
		}
		v = goTo[v][cur];
	}
	term[v] += cost;
}

int qu[K];
void setLinks()
{
	memset(suffLink, -1, sizeof suffLink);
	int r = 0;
	qu[r++] = 0;
	for (int i = 0; i < r; i++)
	{
		int v = qu[i];
		int p = par[v];
		int need = parCh[v];
		p = suffLink[p];
		while (p != -1 && goTo[p][need] == -1)
			p = suffLink[p];
		suffLink[v] = (p == -1) ? 0 : goTo[p][need];
		suffLink[0] = -1;
		for (int j = 0; j < ALP; j++)
			if (goTo[v][j] == 0)
				goTo[v][j] = goTo[max(0, suffLink[v] ) ][j];
			else
				qu[r++] = goTo[v][j];
		if (v != 0)
			term[v] += term[suffLink[v]];
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
//	freopen("errput.txt", "w", stderr);
#endif
	par[0] = -1;

	int n;
	long long l;
	scanf("%d%lld", &n, &l);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i] );
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		addWord(a[i]);
	}
	setLinks();
	Matr A = Matr::ONE();
	for (int i = 0; i < sz; i++)
		for (int j = 0; j < ALP; j++)
		{
			A.a[i][goTo[i][j]] = term[goTo[i][j]];
//			eprintf("%d -> %d : %d\n", i, goTo[i][j], term[goTo[i][j] ] );
		}
	A = A.fpow(l);
	long long ans = 0;
	for (int i = 0; i < sz; i++)
	{
//		eprintf("%lld ", A.a[0][i] );
		ans = max(ans, A.a[0][i]);
	}
	printf("%lld\n", ans);

	return 0;
}