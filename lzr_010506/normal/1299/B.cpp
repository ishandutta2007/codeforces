#include <bits/stdc++.h>
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
map<pii, int> M;
pii p[N];
int main()
{
	int n = read();
	if(n & 1) {puts("NO"); return 0;}
	rep0(i, n)
	{
		int x = read();
		int y = read();
		p[i] = mp(x, y);
	}
	rep0(i, n)
	{
		int x = p[i].X - p[(i + 1) % n].X;
		int y = p[i].Y - p[(i + 1) % n].Y;
		M[mp(x, y)] ++;
		M[mp(-x, -y)] ++;
		M[mp(x, y)] -= 2;
	}
	for(auto x : M) 
		if(x.Y != 0) 
		{
			puts("NO"); 
			return 0;
		}
	puts("YES");


	return 0;
}