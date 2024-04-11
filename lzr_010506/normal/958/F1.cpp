#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
//#define X fisrt
#define Y second
#define pb push_back
//#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
int n, m, mb[110], a[110], vis[110];
int main()
{
	n = read();
	m = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, m) mb[i] = read();
	rep(l, 1, n)
		rep(r, l, n)
		{
			memset(vis, 0, sizeof(vis));
			rep(i, l, r)
				vis[a[i]] ++;
			bool flag = 0;
			rep(i, 1, 100)
				if(vis[i] != mb[i])
					flag = 1;
			if(!flag) {puts("YES"); return 0;}
		}
    puts("NO");

	return 0;
}