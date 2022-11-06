#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
//#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2020;
const int mod = 998244353;
int p[N];

int main()
{
	p[0] = p[1] = 0;
	rep(i, 2, N - 1) p[i] = 1;
	rep(i, 2, N - 1)
		if (p[i])
			for (int j = (i << 1); j < 1033; j += i) p[j] = 0;
	int n = read();
	if (p[n])
	{
		printf("%d\n",n);
		rep(i, 1, n - 1) printf("%d %d\n", i, i + 1);
		printf("%d %d\n", 1, n);
		return 0;
	}
	for (int i = n; ; i ++)
		if (p[i])
		{
			printf("%d\n",i);
			rep(i, 1, n - 1)
				printf("%d %d\n", i, i + 1);
			printf("%d %d\n",1,n);
			int t = i - n;
			rep0(j, (t >> 1))
			{
				int v1 = j * 4 + 1;
				printf("%d %d\n", v1, v1 + 2);
				printf("%d %d\n", v1 + 1, v1 + 3);
			}
			if (t & 1)
			{
				int vv = t / 2 * 4 + 1;
				printf("%d %d\n", vv, vv + 2);
			}
			return 0;
		}
	return 0;
}