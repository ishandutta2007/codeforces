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
const int N = 1000010;
const int mod = 998244353;
char ch[N];
string ans;
int main()
{
	scanf("%s", ch);
	int n = strlen(ch);
	rep0(i, n / 4)
	{
		int a = i * 2, b = a + 1, c = n - a - 1, d = c - 1;
		if (ch[a] == ch[c] || ch[a] == ch[d]) ans += ch[a];
		else ans += ch[b];
	}
	if (n % 4 <= 1)
	{
		string fan = ans;
		reverse(All(fan));
		ans = ans + fan;
		cout << ans;
		return 0;
	}
	string fan = ans;
	reverse(All(fan));
	ans = ans + ch[n / 2] + fan;
	cout << ans;
	return 0;
}