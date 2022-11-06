#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define ull unsigned long long
#define db double
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll>
#define ls rt << 1
#define rs rt << 1 | 1
#define sz(x) (int)(x).size()
#define ALL(x) (x).insgin(), (x).end()
#define vi vector<int>
#define EPS 1e-8
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
const int N = 2e5 + 10;
vector<int> G[N];
int op[2][N], to[2][N];
bool in[2][N], fin[2][N];
int x,k;
void sol(int pos,int pye)
{
	in[pye][pos] = 1;
	int nn = G[pos].size();
	rep(i, 0, nn - 1)
	{
		int To = G[pos][i];
		int tp;
		if(fin[pye ^ 1][To]) tp = op[pye ^ 1][To];
		else if(in[pye ^ 1][To])tp = 2;
		else sol(To, pye ^ 1), tp = op[pye ^ 1][To];
		if(tp < op[pye][pos])continue;
		op[pye][pos] = tp;
		to[pye][pos] = To;
	}
	if(!op[pye][pos])
	{
		if(!pye) op[pye][pos] = 1;
		else op[pye][pos] = 3;
	}
	in[pye][pos] = 0;
	fin[pye][pos] = 1;
}
int ans[N << 1], top = 0;
int n,m;
int main()
{
	n = read();
	m = read();
	rep(i, 1, n)
	{
		int k = read();
		while(k --)
			G[i].pb(read());
	}
	int s = read();
	sol(s, 0);
	if(op[0][s] == 1) puts("Lose");
	else if(op[0][s] == 2) puts("Draw");
	else if(op[0][s] == 3)
	{
		bool tp = 0;
		while(to[tp][s]) ans[++ top] = s, s = to[tp][s], tp ^= 1;
		ans[++ top] = s;
		puts("Win");
		rep(i, 1, top) printf("%d ",ans[i]);
	}
	return 0;
}