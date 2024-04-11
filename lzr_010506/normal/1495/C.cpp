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
#define pll pair<ll, ll>
#define X first
#define Y second
#define py pair<char, char>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#define lowbit(x) ((x) & -(x))
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
const int N = 510;
char ch[N][N];
int main()
{
	int T = read();
	while(T --)
	{
		int n = read();
		int m = read();
		rep(i, 1, n)
			scanf("%s", ch[i] + 1);
		rep(i, 1, n)
			if(i % 3 == 1) rep(j, 1, m) ch[i][j] = 'X';
		for(int i = 1; i <= n; i += 3)
			if(i + 3 <= n)
			{
				int f1 = -1, f2 = -1;
				rep(j, 1, m)
				{
                    if(ch[i + 1][j] == 'X') f1 = j;
                    if(ch[i + 2][j] == 'X') f2 = j;
                }
                if(f1 == -1 && f2 == -1) ch[i + 1][1] = ch[i + 2][1] = 'X';
                else if(f1 != -1) ch[i + 2][f1] = 'X';
                else ch[i + 1][f2] = 'X';
			}
		if(n % 3 == 0)
			rep(j, 1, m)
				if(ch[n][j] == 'X') ch[n - 1][j] = 'X';
        
        rep(i, 1, n) 
        {
        	rep(j, 1, m)
        		printf("%c", ch[i][j]);
        	puts("");
        }
	}
    return 0;
}