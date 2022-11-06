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
const int N = 1e6 + 10;

ll c[N];
int id[N];
ull hsh[N], val[N];

bool cmp(int x, int y)
{
	return val[x] < val[y];
}

ll gcd(ll a, ll b)
{
	while(a)
	{
		ll c = a;
		a = b % a;
		b = c;
	}
	return b;
}

int main()
{
	srand(time(0));
	rep0(i, N)
	{
		hsh[i] = 1LL * rand() * rand() * rand() * rand();
		if(hsh[i] == 0) hsh[i] = 1;
	}
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		rep(i, 1, n) c[i] = read1();
		memset(val, 0, sizeof(val[0]) * (n + 1));
		rep(i, 1, m)
		{
			int u = read();
			int v = read();
			val[v] ^= hsh[u];
		}
		rep(i, 1, n) id[i] = i;
		sort(id + 1, id + n + 1, cmp);
		ll ans = 0, sum = 0;
		rep(i, 1, n)
		{
			sum += c[id[i]];
			if(i == n || val[id[i]] != val[id[i+1]])
			{
				if(val[id[i]]) ans = gcd(ans, sum);
				sum = 0;
			}
		}
		printf("%lld\n", ans);
	}

	return 0;
}