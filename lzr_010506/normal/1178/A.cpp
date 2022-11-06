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
int n, sum;
pii a[110];
vi ans;
int main()
{
	n = read();
	rep(i, 1, n) a[i].X = read(), sum += a[i].X, a[i].Y = i;
	sort(a + 2, a + n + 1);
	reverse(a + 2, a + n + 1);
	int k = n + 1;
	rep(i, 2, n)
		if(a[i].X * 2 <= a[1].X) {k = i; break;}
	int sum1 = 0;
	rep(i, k, n) 
		sum1 += a[i].X;
	sum1 += a[1].X;
	if(sum1 * 2 > sum)
	{
		printf("%d\n", n - k + 2);
		ans.pb(1);
		rep(i, k, n) ans.pb(a[i].Y);
		sort(All(ans));
		for(auto A : ans) cout << A << " ";
	}
	else puts("0");

	return 0;
}