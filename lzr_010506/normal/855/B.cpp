#include <bits/stdc++.h>
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb push_back
#define ll long long
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
#define all(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int a[100010];
ll f[100010][3];
int main()
{
	int n = read();
	a[0] = read();
	a[1] = read();
	a[2] = read();
	rep(i, 0, n) f[i][0] = f[i][1] = f[i][2] = -(1ll << 62);
	for(int i = 1, x; i <= n; i ++)
    {
        x = read();
        f[i][0]= max(f[i-1][0], 1ll * a[0] * x);
		rep(j, 1, 2)
			f[i][j]=max(f[i-1][j],max(f[i][j - 1], f[i-1][j-1])+1ll*a[j]*x);
	}

	printf("%lld\n",f[n][2]);
	return 0;
}