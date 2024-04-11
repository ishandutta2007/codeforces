#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
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
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
#define MN 300000
#define K 100
int a[MN + 10],f[MN + 10][K + 10];
inline void mx(int&a, int b)
{
	if(b < a) a = b;
}
int main()
{
	int n=read();
	rep(i, 1, n) a[i] = read();
	memset(f, 40, sizeof(f));
	f[0][0] = 0;
	rep(i, 1, n)
		rep(j, 0, K)
		{
			if(j + a[i] / 1000 <= K) mx(f[i][j + a[i] / 1000],f[i - 1][j] + a[i]);
			if(j * 100 < a[i]) mx(f[i][0], f[i - 1][j] + a[i] - j * 100);
			else mx(f[i][j - a[i] / 100], f[i - 1][j]);
		}
	rep(i, 0, K) mx(f[0][1], f[n][i]);
	printf("%d",f[0][1]);
}