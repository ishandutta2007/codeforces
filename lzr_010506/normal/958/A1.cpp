#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll long long
//#define X fisrt
#define Y second
#define pb push_back
//#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
using namespace std;
const int N = 20;
int n;
bool flag;
char s1[N][N],s2[N][N],s3[N][N];

bool pd(char a[N][N],char b[N][N])
{
	rep(i, 1, n)
		rep(j, 1, n)
			if (a[i][j] != b[i][j]) return 0;
	return 1;
}

void rev(char s[N][N])
{
	char c[N][N];
	rep(i, 1, n)
		rep(j, 1, n)
			c[j][n - i + 1] = s[i][j];
	rep(i, 1, n)
		rep(j, 1, n)
			s[i][j] = c[i][j];
}

void xz()
{
	if (pd(s2, s3)) flag = 1;
	rev(s3);
	if (pd(s2, s3)) flag = 1;
	rev(s3);
	if (pd(s2, s3)) flag = 1;
	rev(s3);
	if (pd(s2, s3)) flag = 1;
}

void work0()
{
	rep(i, 1, n)
		rep(j, 1, n)
			s3[i][j] = s1[i][j];
}

void work1()
{
	rep(i, 1, n)
		rep(j, 1, n)
			s3[i][j] = s1[i][j];
	rep(i, 1, n) reverse(s3[i] + 1, s3[i] + 1 + n);
}

void work2()
{
	rep(i, 1, n)
		rep(j, 1, n)
			s3[i][j] = s1[i][j];
	rep(i, 1, n / 2)
		rep(j, 1, n)
			swap(s3[i][j], s3[n - i + 1][j]);
}

int main()
{
	n = read();
	rep(i, 1, n) scanf("%s", s1[i] + 1);
	rep(i, 1, n) scanf("%s", s2[i] + 1);
	if (pd(s1, s2))
	{
		puts("Yes");
		return 0;
	}
	work0(); xz();
	work1(); xz();
	work2(); xz();
	work1(); work2(); xz();
	if (flag) puts("Yes");
	else puts("No");
	return 0;
}