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
int n, a, b;

int main()
{
	n = read();
	a = read();
	b = read();
	int x = -1, y = -1;
	for(int i = 0; i * a <= n; i ++)
		if((n - i * a) % b == 0)
			x = i,y = (n - i * a) / b;
	if(x == -1) cout << -1 << endl;
	else
	{
		int now = 1;
		rep(i, 1, x)
		{
			rep(j, 1, a)
				printf("%d ",now + j % a);
			now += a;
		}
		rep(i, 1, y)
		{
			rep(j, 1, b)
				printf("%d ",now + j % b);
			now += b;
		}
	}
	return 0;
}