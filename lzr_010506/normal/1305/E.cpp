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
#define pNF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
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

const int N = 100010;
int cnt[N];
int main()
{
	int n = read();
	int m = read();
	int sum = 0;
	for (int i = n - 2; i >= 0; i -= 2) sum += i;
	if (m > sum) 
	{
		puts("-1");
		return 0;
	}
	if (n == 1) 
	{
		puts("1"); 
		return 0;
	}
	if (n == 2) 
	{
		puts("1 2"); 
		return 0;
	}
	int tot = 0, p;
	rep(i, 3, n) 
	{
		if (tot + (i - 1) / 2 >= m) 
		{
			p = i - 1;
			break;
		}
		tot += (i - 1) / 2;
	}
	rep(i, 1, p) printf("%d ", i);
	int left = p / 2 - (m - tot);
	printf("%d ", p + 1 + left * 2);
	rep(i, p + 2, n) printf("%d ", 200000000 + 20000 * i);
	return 0;
}