#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define mod 1000000007
using namespace std;
int h;
const int N = 200010;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n,a[205],b[205],c[205];
int main()
{
	scanf("%d", &n);
	a[1] = b[0] = 1;
	rep(i, 2, n)
	{
		memcpy(c, b, sizeof(c));
		memcpy(b, a, sizeof(a));
		for(int j = i; j; j --) a[j] = a[j - 1];
		a[0] = 0;
		bool f = 1;
		rep(j, 0, i)
			if(abs(a[j] + c[j]) > 1) { f = 0; break; }
		if(f) rep(j, 0, i) a[j] += c[j];
		else rep(j, 0, i) a[j] -= c[j];
	}
	printf("%d\n", n);
	rep(i, 0, n) printf("%d ",a[i]); printf("\n");
	printf("%d\n", n - 1);
	rep(i, 0, n - 1) printf("%d ",b[i]);
	return 0;
}