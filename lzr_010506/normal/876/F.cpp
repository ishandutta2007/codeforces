#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
#define pii pair<int, int>
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 300010;
int a[N],s[N],Net[32],p[N],n;
map<int, int> f;
int main()
{
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
	{
		rep(j, 0, 30)
			if((a[i] >> j) & 1) Net[j] = i;
			else p[i] = max(p[i], Net[j] + 1);
		p[i] = max(p[i], f[a[i]] + 1);
		f[a[i]] = i;
	}
	rep(i, 0, 30) Net[i] = n + 1;
	rep(i, 1, n) s[i] = n;
	ll ans = 0;
	rrep(i, n, 1)
	{
		rep(j, 0, 30)
			if((a[i] >> j) & 1) Net[j] = i;
			else  s[i] = min(s[i], Net[j] - 1);
		ans += 1ll * (s[i] - i + 1) * (i - p[i] + 1);
	}
	cout << (1ll*n*(n+1)/2-ans)<<endl;
	return 0;
}