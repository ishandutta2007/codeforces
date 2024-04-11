#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int C[1010][1010], f[1010];
char s[1010][1010];
const int P = 1e9 + 7;
void preset()
{
	int n = 1000; 
	C[0][0] = 1;
	rep(i, 1, n)
	{
		C[i][i] = 1;
		C[i][0] = 1;
		rep(j, 1, i - 1)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	
	f[0] = 1; 
	f[1] = 1;
	rep(i, 1, n)
		rep(j, 0, i)
			f[i + 1] = (f[i + 1] + 1ll * f[j] * C[i][j]) % P;
}
int main()
{
	preset();
	int m = read();
	int n = read();
	rep(i, 1, n) scanf("%s", s[i] + 1);
	map<string, int> mp;
	rep(i, 1, m)
	{
		string S = "";
		rep(j, 1, n) S += s[j][i];
		mp[S] ++;
	}
	int ans = 1;
	for (auto x = mp.begin(); x != mp.end(); x ++) ans = 1ll * ans * f[x -> Y] % P;
	printf("%d\n",ans);
}