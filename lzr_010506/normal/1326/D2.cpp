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
#define pcc pair<sum2r, sum2r>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define ept 1e-9
#define INF 0x3f3f3f3f
#define sz(x) (x).size()
#define sti set<int>::iterator
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
const int N = 3e6 + 10, MOD = 998244353;
int T, n, nn, ans, ansl, ansr, p[N], lp[N], rp[N];
char str[N], s[N];
bool Vl[N], Vr[N];

void manacher() 
{
	int mx = 0, ans = 0, po = 0;
	rep(i, 1, n)
	{
		if(mx > i) p[i] = min(mx - i,p[2 * po - i]);
        else p[i] = 1;
        while(str[i - p[i]] == str[i + p[i]]) p[i] ++;
        if(p[i] + i > mx)
        {
            mx = p[i] + i;
            po = i;
        }
	}
}

int main() 
{
	int T = read();
	while(T --)
	{
        scanf("%s", s); 
        nn = strlen(s);
        str[n] = str[n + 1] = str[n + 2] = ' '; n = 0;
        str[++ n] = '~';
        rep0(i, nn)
        {
            str[++ n] = s[i];
            str[++ n] = '#';
        }
        str[n] = '!';
        manacher();
        rep0(i, nn + 1) Vl[i] = Vr[i] = false; 
        bool flag = false;
        int par = 0;
        int i = 0, j = nn - 1;
        while(1) 
        {
            if (s[i] == s[j]) 
            {
                Vl[i] = Vr[j] = 1;
                i ++; j --;
                par ++;
                if (i > j) { flag = 1; break; }
            } 
            else break;
        }
        ans = 1; ansl = 1; ansr = n - 1;
        rep(i, 2, n)
        {
            p[i] --;
            if (str[i + p[i]] == '#') 
            {
                if (p[i] == 0) continue; 
                p[i]--;
            }
            int l = (i - p[i]) / 2 - 1, r = (i + p[i]) / 2 - 1;
            int len = min(l, nn - 1 - r);
            if (len <= par) 
            {
                int det = r - l + 1;
                if (ans < det + len + len) 
                {
                    ans = det + len + len;
                    if (len == l) ansl = r + 1, ansr = nn - 1 - len;
                    else ansl = len, ansr = l - 1;
                }
            }
        }
        rep0(i, ansl) printf("%c", s[i]);
        rep(i, ansr + 1, nn - 1) printf("%c", s[i]);
        puts("");
    }
    return 0;
}