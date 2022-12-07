#include <bits/stdc++.h>
#define N 10001
#define FOR(i, n) for(int (i) = 1; (i) <= (n); (i) ++)
#define SRT(i, N) sort((i) + 1, (i) + (N) + 1, cmp)
using namespace std;
int n, m, k, l, top;
int a1[N], a2[N], st[N];
bool a[N][N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

bool cmp(int a, int b)
{
	return a < b;
}

void Init()
{
	n = read();
	m = read();
	k = read();
	FOR(i, k)
		a1[i] = read();
}

void Work()
{
	SRT(a1, k);
	FOR(i, k)
	{
		if(a1[i] < 2) {printf("NO"); goto L1;}
		int flag = 1;
		for(int j = n; j >= 1; j --)
		{
			FOR(t, m)
			{
				if(j + t > a1[i]) goto L2;
				if(!a[j][t]) {a[j][t] = 1; flag = 0; goto L2;}
			}
			L2:;
			if(!flag) break;
		}
		if(flag != 0) {printf("NO"); goto L1;}
	}
	FOR(i, n)
		FOR(j, m)
			if(!a[i][j])
				st[++ top] = i + m + 1 - j;
	SRT(st, top);
	l = read();
	FOR(i, l)
		a2[i] = read();
	SRT(a2, l);
	FOR(i, l)
		if(a2[i] < st[i]) 
			{printf("NO"); goto L1;}
	printf("YES");
	L1:;
}

int main()
{
	Init();
	Work();
	return 0;
}