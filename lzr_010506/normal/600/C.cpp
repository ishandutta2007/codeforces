#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
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
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
inline ll read1()
{
	ll x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 2000010;
int sum[30];
char ch[N];
int main()
{
	scanf("%s", ch);
	int len = strlen(ch);
	rep0(i, len) sum[ch[i] - 'a'] ++;
	int i = 0, j = 25;
	while(i < j)
	{
		while(i < j && sum[i] % 2 == 0) i ++;
		while(i < j && sum[j] % 2 == 0) j --;
		sum[i] ++;
		sum[j] --;
	}
	rep0(i, 26)
		rep(j, 1, sum[i] / 2)
			putchar(i + 'a');
	rep0(i, 26)
		if(sum[i] % 2 == 1)
			putchar(i + 'a');
	rrep(i, 25, 0)
		rep(j, 1, sum[i] / 2)
			putchar(i + 'a');
	return 0; 
}