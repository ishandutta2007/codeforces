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
#define pcc pair<char, char>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define eps 1e-9
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
int n, k, x, ans;
int a[100010];
int main()
{
	n = read();
	k = read();
	x = read();
	rep(i, 1, n)
		a[i] = read();
    sort(a + 1, a + n + 1);
	rep(i, 0, k - 1)
		a[n - i] = x;
	rep(i, 1, n)
		ans += a[i];
	cout << ans;
	return 0;
}