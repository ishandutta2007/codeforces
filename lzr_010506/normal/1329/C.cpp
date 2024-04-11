#include <bits/stdc++.h>
#define int long long 
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
using namespace std;
const ll N = 2e6 + 2e5;

ll a[N];
int M[N], pos[N];
signed main()
{
	int T = read();
	while(T --)
	{
        int h = read();
        int g = read();
        int n = (1 << h);
        int m = (1 << g);
        rep0(i, n * 2 + 1) a[i] = 0;
        rep(i, 1, n - 1)
        {
        	a[i] = read();
            pos[i] = a[i];
        }
        vi ans;
        rep(i, 1, n - 1) M[a[i]] = i;
        sort(pos + 1, pos + n);
        reverse(pos + 1, pos + n);
        int d = 0;
        int times = n - m;
        while(times --)
            while(1)
            {
                int x = pos[d += 1];
                int i = M[x];
                int p = i;
                vi v;
                v.pb(i);
                while(a[p * 2] || a[p * 2 + 1])
                	if(a[p * 2 + 1] > a[p * 2]) v.pb(p = p * 2 + 1);
               		else v.pb(p = p * 2);
                if(p >= m)
                {
                    ans.pb(i);
                    rep0(j, sz(v) - 1)
                    {
                        a[v[j]] = a[v[j + 1]];
                        M[a[v[j]]] = v[j];
                    }
                    a[p] = 0;
                    break;
                }
            }
        
        ll sum = 0;
        rep(i, 1, m - 1) sum += a[i];
        cout << sum << endl;
        rep0(i, sz(ans)) cout << ans[i] << " ";
        puts("");
    }
    return 0;
}