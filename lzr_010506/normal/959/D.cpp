#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
//#define ls rt << 1
//#define rs rt << 1 | 1
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define X first
#define Y second
#define pcc pair<char, char>
#define vi totor<int>
#define vl totor<ll>
#define rep(i, x, y) for(register int i = x; i <= y; i ++)
#define rrep(i, x, y) for(register int i = x; i >= y; i --)
#define eps 1e-15
#define lb(x) x & -x
#define sz(x) (x).size()
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
const int N = 2e6 + 10;
const int P = 1e9 + 7;
const int inf = 1e9 + 7;
vector<int> d[N];
int p[N],vis[N];
int ok(int x)
{
    int ret = 1;
    for(auto i:d[x])
    	ret &= !vis[i];
    return ret;
}
int main()
{
    int n;
    cin >> n;
    rep(i, 2, N - 1)
    	if (!p[i])
            for(int x = i; x < N; x += i)
            	d[x].pb(i), p[x] = 1;
    
    int f = 1, cur = 2;
    rep(i, 0, n - 1)
    {
    	int x = read();
        int now = x;
        if(f)
        {
            while(!ok(now))
            now ++;
            if(now != x) f = 0;
        }
        else
        {
            while(!ok(cur)) cur ++;
            now = cur;
        }
        printf("%d ", now);
        for(auto x:d[now])
        	vis[x] = 1;
    }
}