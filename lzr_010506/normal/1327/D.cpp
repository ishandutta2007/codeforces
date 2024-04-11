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
int main() 
{
    int T = read();
    while (T --) 
    {
        int n = read();
        vi p(n), c(n);
        rep0(i, n)
        {
        	p[i] = read();
            p[i] --;
        }
        rep0(i, n) c[i] = read();
        int ans = n;
        rep0(i, n)
        {
            if (p[i] == -1) continue;
            vi a;
            for (int j = i; p[j] != -1; ) 
            {
                a.pb(c[j]);
                int k = p[j];
                p[j] = -1;
                j = k;
            }
            rep(j, 1, sz(a))
                if (a.size() % j == 0) 
                    rep0(s, j)
                	{
                        bool flag = true;
                        for (int k = s; k < int(a.size()); k += j)
                            if (a[k] != a[s])
                                flag = false;
                        if (flag) ans = min(ans, j);
                    }
        }
        cout << ans << "\n";
    }
    return 0;
}