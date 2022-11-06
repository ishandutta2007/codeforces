#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ls rt << 1
#define rs rt << 1 | 1
#define mod 1000000007
#define sz(x) (int)(x).size()
#define vi vector<int>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int fa[1010];
bool vis[1010];
int main()
{
	int n = read();
	rep(i, 2, n)
	 	fa[i] = read();
	rep(i, 2, n)
		vis[fa[i]] = 1;
	rep(i, 1, n)
	{
		bool flag = 1;
		if(vis[i] == 0) continue;
		int cnt = 0;
		rep(j, 2, n)
			if(fa[j] == i && vis[j] == 0)
				cnt ++; 
		if(cnt < 3)
		{
			puts("No");
			return 0;
		}
	}
	puts("Yes");

	return 0;
}