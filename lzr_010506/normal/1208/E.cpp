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
const int N = 1e6 + 10;

ll ans[N];
int l[N], c[N], q[N], qt[N];
void add(int l,int r,int x)
{
    
}
int ql, qr;
int main() 
{
	int n = read();
	int w = read();
	rep(i, 1, n)
	{
		l[i] = read();
		int mx = -1e9;
		rep(j, 0, l[i - 1]) c[j] = 0;
		rep(j, 1, l[i])
		{
			int x = read();
			c[j] = x;
			mx = max(mx, x);
		}
		if(w - l[i] >= l[i] + 1 && mx > 0) ans[w - l[i] + 1] -= mx, ans[l[i] + 1] += mx;
		int L = 1, R = 0;
		ql = 1, qr = 0;
        rep(j, 1, w)
        {
            if(w - l[i] >= l[i] + 1 && j == l[i] + 1)
            {
                j = w - l[i]; 
                continue;
            }
            while(R < j && R < l[i])
            {
            	R ++;
            	while(ql <= qr && q[qr] <= c[R]) qr --;
    			q[++ qr] = c[R];
    			qt[qr] = R;
            }
            while(L < l[i] - w + j && L <= R) 
			{
                if(qt[ql] == L) ql ++;
				L ++;
            }
            if(q[ql] > 0 || !(j > l[i] || j < w - l[i] + 1)) ans[j + 1] -= q[ql], ans[j] += q[ql];
        }
	}
	ll now = 0;
	rep(i, 1, w)
	{
		now += ans[i];
		cout << now << " ";
	}

    return 0;
}