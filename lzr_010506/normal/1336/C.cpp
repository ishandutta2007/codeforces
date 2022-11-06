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
#define dep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (int)(x).size()
#define All(x) (x).begin(), (x).end()
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
const int N = 2e5 + 10;
const int mod = 998244353;
char s[N], t[N];
ll f[3010][3010];
void add(ll &a, ll b)
{
	a += b;
	if(a >= mod) a -= mod;
}
int main()
{
    scanf("%s", s + 1); 
    int n = strlen(s + 1);
    scanf("%s", t + 1); 
    int m = strlen(t + 1);
    ll ans = 0;
    rep(i, 1, n + 1) f[0][i] = 1;
    rep(i, 1, n)
    {
        rep(j, 1, n + 1)
        {
            if (j > m) add(f[i][j + 1], f[i - 1][j]);
            else if (s[i] == t[j]) add(f[i][j + 1], f[i - 1][j]);
            if (j - i > 0)
            {
                if (j - i > m) add(f[i][j],f[i - 1][j]);
                else if (s[i] == t[j - i]) add(f[i][j],f[i - 1][j]);
            }
        }
        if (i >= m) add(ans, f[i][i + 1]);
    }
    cout << ans << endl;
    return 0;
}