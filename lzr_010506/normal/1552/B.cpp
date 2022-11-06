#include <bits/stdc++.h>
#define ull unsigned long long
#define ll long long
#define il inline
#define db double
#define ls rt << 1
#define rs rt << 1 | 1
#define pb emplace_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
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

const int N = 1e6 + 10;
int n,m;
struct node
{
    int a[5];
}s[N];

bool check(int x, int now)
{
	int re = 0;
	rep0(i, 5) re += (s[x].a[i] < s[now].a[i]);
	return re > 2;
}

int main()
{
	int T = read();
	while(T --)
	{
		//printf("TTTTTTTTTT%d\n", T);
		n = read();
		rep(i, 1, n)
			rep0(j, 5) 
				s[i].a[j] = read();
		int now = 1;
		rep(i, 2, n)
		{
			if(check(i, now)) now = i;
		}
		rep(i, 1, n)
		{
	        if(i == now)continue;
	        if(check(i, now))
	        {
	        	puts("-1");
	            goto L1;
	        }
	    }
	    printf("%d\n",now);
	    L1:;
	}
	
    return 0;
}