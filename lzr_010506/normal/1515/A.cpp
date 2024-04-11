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
#define sz(x) (x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 110;
int a[N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int x = read();
		rep(i, 1, n) a[i] = read();
		sort(a + 1, a + n + 1);
		int sum = 0, flag = 0;
		rep(i, 1, n)
		{
			sum = sum + a[i];
			if(sum == x)
			{
				flag = 1;
				if(i == n) {puts("NO"); break;}
				puts("YES");
				rep(j, 2, n) printf("%d ", a[j]);
				printf("%d\n", a[1]);
				break;
			}
		}
		if(flag == 0) 
		{
			puts("YES");
			rep(i, 1, n) printf("%d ", a[i]);
			puts("");
		}
	}
	return 0;
}