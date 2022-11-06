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
const int N = 2e5 + 10;

int n;
namespace BIT 
{
    long long c[N];
    
    int lowbit(int x) 
    {
        return x & -x;
    }
    
    void add(int a, int x) 
    {
    	int nw = a;
    	while(nw <= n)
    	{
    		c[nw] += x;
    		nw += lowbit(nw);
    	}
    }
    
    ll query(int a) 
    {
        ll res = 0;
        int nw = a;
        while(nw > 0)
        {
        	res += c[nw];
        	nw -= lowbit(nw);
        }
        return res;
    }
};
using namespace BIT;

ll a[N];

int ans[N];

int main() 
{
	n = read();
	rep(i, 1, n) a[i] = read1();
    rep(i, 1, n) add(i, i);
    rrep(i, n, 1)
    {
        int l = 1, r = n;
        while (l <= r) 
        {
            int mid = (l + r) >> 1;
            if (query(mid - 1) <= a[i]) ans[i] = mid, l = mid + 1;
            else r = mid - 1;
        }
        add(ans[i], -ans[i]);
    }
    rep(i, 1, n)
    	printf("%d ", ans[i]);
    
    return 0;
}