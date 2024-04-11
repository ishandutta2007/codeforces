#include <bits/stdc++.h>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <fstream>
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
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
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
const int N = 5010;
int n, m, l[N], s[N], c[N];

int dp[N][N], cnt[N];
int main()
{
	n = read(); 
	m = read();
	rep(i, 1, n) l[i] = read();
	rep(i, 1, n) s[i] = read();
	rep(i, 1, n + m) c[i] = read();
	memset(dp, -INF, sizeof(dp));
	rep(i, 1, m + n) dp[i][0] = 0;
	rrep(i, n, 1)
	{
		rrep(k, cnt[l[i]], 0) 
			if(dp[l[i]][k] - s[i] + c[l[i]] > dp[l[i]][k + 1]) dp[l[i]][k + 1] = dp[l[i]][k] - s[i] + c[l[i]];
		cnt[l[i]] ++;
		rep0(j, n + m + 1)
			rrep(k, cnt[j], 0)
			if(dp[j][k] != -INF)
			{
				if(dp[j][k] + c[j + 1] * (k >> 1) > dp[j + 1][k >> 1]) dp[j + 1][k >> 1] = dp[j][k] + c[j + 1] * (k >> 1);
				if(k / 2 > cnt[j + 1]) cnt[j + 1] = (k >> 1);
			}
	}
	printf("%d\n", dp[n + m][0]);
	return 0;
}