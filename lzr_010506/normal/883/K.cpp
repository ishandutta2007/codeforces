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
int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n, l[200100], r[200100], L[200100], R[200100];
int main()
{
	n = read();
	rep(i, 1, n)
	{
		l[i] = read();
		r[i] = read();
		r[i] += l[i];
	}
	L[0] = R[n + 1] = 1e9 + 10;
	rep(i, 1, n) L[i] = min(r[i], L[i - 1] + 1);
	rrep(i, n, 1) R[i] = min(r[i], R[i + 1] + 1);
	ll ans = 0, f = 0;
	rep(i, 1, n)
	{
		if(min(L[i], R[i]) < l[i]) f = 1;
		ans += min(L[i], R[i]) - l[i];
	}
	if(f)
	{
		puts("-1");
		return 0;
	}
	printf("%I64d\n", ans);
	rep(i, 1, n) printf("%d ", min(L[i], R[i]));
	return 0;
}