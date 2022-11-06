#include <bits/stdc++.h>
#define ll long long
#define uint unsigned long long
#define ls x << 1
#define rs x << 1 | 1
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
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
char ch[2510][2510];
int n, m, a[2510][2510], ans;

void Doit(int k)
{
	int sum = 0;
	for(int i = 1; i <= n; i += k)
		for(int j = 1; j <= m; j += k)
		{
			int x = i + k - 1;
			int y = j + k - 1;
			if(x > n) x = n;
			if(y > m) y = m;
			int num = a[x][y] - a[i - 1][y] - a[x][j - 1] + a[i - 1][j - 1];
			sum += min(num, k * k - num);
		}
	ans = min(ans, sum);
}

int main()
{
    ans = 0x7f7f7f7f;
	n = read();
	m = read();
	rep(i, 1, n)
		scanf("%s", ch[i] + 1);

	rep(i, 1, n)
		rep(j, 1, m)
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + ch[i][j] - '0';

	int nn = max(n, m);
	rep(i, 2, nn) Doit(i);
	cout << ans;
	return 0;
}