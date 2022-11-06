#include <bits/stdc++.h>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define ll long long
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
const int N = 1e5 + 10;
char s[N], t[N];
int fa[30];
int findf(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = findf(fa[x]);
}
void mergef(int x, int y)
{
	fa[findf(x)] = findf(y);
}
vector<pair<char, char> >ans;
int main()
{
	int n;
	n = read();
	scanf("%s%s", s + 1, t + 1);
	rep(i, 0, 25) fa[i] = i;
	rep(i, 1, n)
		mergef(s[i] - 'a', t[i] - 'a');
	rep(i, 0, 25)
		if (findf(i) == i)
		{
			rep(j, 0, 25)
				if (i != j && findf(i) == findf(j))
					ans.pb(mp(i + 'a', j + 'a'));
		}
	int nn = sz(ans);
	printf("%d\n", nn);
	rep(i, 0, nn - 1)
		printf("%c %c\n", ans[i].X, ans[i].Y);
}