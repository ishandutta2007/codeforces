#include <bits/stdc++.h>
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
int n;
int a[110], b[110];
int main()
{
	n = read();
	n *= 2;
	int ans = 1e9;
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
		rep(j, i + 1, n)
		{
			memcpy(b, a, sizeof(b));
			b[i] = 0;
			b[j] = 0;
			sort(b + 1, b + n + 1);
			int now = 0;
			for(int k = 1; k <= n; k += 2)
				now += b[k + 1] - b[k];
			ans = min(now, ans);
		}
    cout << ans;
	return 0;
}