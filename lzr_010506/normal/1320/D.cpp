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
#define int long long
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
const int N = 1e6 + 10;

const int base1 = 443;
const int base2 = 33;

int mod1, mod2, p1[N], p2[N];
struct Node 
{
	int hash1, hash2, len, L, R;
	Node() {hash1 = hash2 = len = L = R = 0;}
};
Node merge(Node a, Node b) 
{
	Node ret;
	if (!a.len && !b.len) 
	{
		ret.L = ret.R = a.L ^ b.R;
		return ret;
	}
	if (!b.len) 
	{
		ret = a;
		ret.R ^= b.R;
		return ret;
	}
	if (!a.len) 
	{
		ret = b;
		ret.L ^= a.L;
		return ret;
	}
	
	ret.len = a.len + b.len;
	ret.L = a.L;
	ret.R = b.R;
	int mid = a.R ^ b.L;
	ret.hash1 = (a.hash1 + 1ll * p1[a.len - 1] * mid + 1ll * p1[a.len] * b.hash1) % mod1;
	ret.hash2 = (a.hash2 + 1ll * p2[a.len - 1] * mid + 1ll * p2[a.len] * b.hash2) % mod2;
	return ret;
}
char s[N];
int n, m;
Node T[N];
void build(int l, int r, int rt) 
{
	if (l == r) 
	{
		if (s[l] == '1') T[rt].L = T[rt].R = 1;
		else T[rt].len = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, ls);
	build(mid + 1, r, rs);
	T[rt] = merge(T[ls], T[rs]);
}
Node query(int l, int r, int rt, int x, int y) 
{
	if (l == x && y == r) return T[rt];
	int mid = (l + r) >> 1;
	if (y <= mid) return query(l, mid, ls, x, y);
	else if (x > mid)return query(mid + 1, r, rs, x, y);
	else return merge(query(l, mid, ls, x, mid), query(mid + 1, r, rs, mid + 1, y));
}
signed main() 
{
	mod1 = 998244353;
	mod2 = 1e9 + 7;
	p1[0] = p2[0] = 1;
	rep(i, 1, N - 1)
	{
		p1[i] = 1ll * p1[i - 1] * base1 % mod1;
		p2[i] = 1ll * p2[i - 1] * base2 % mod2;
	}
	n = read();
	scanf("%s", s + 1);
	m = read();
	build(1, n, 1);
	while(m --)
	{
		int t1 = read();
		int t2 = read();
		int l = read();
		Node a = query(1, n, 1, t1, t1 + l - 1);
		Node b = query(1, n, 1, t2, t2 + l - 1);
		puts(((a.hash1 == b.hash1 && a.hash2 == b.hash2 && a.len == b.len && a.L == b.L && a.R == b.R)) ? "YES" : "NO");
	}
	return 0;
}