#include <bits/stdc++.h>
#define pcc pair<char, char>
#define pii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define rep(i, x, y) for(int i = x; i <= y; i ++)
#define rrep(i, x, y) for(int i = x; i >= y; i --)
#define rep0(i, n) for(int i = 0; i < (n); i ++)
#define per0(i, n) for(int i = (n) - 1; i >= 0; i --)
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define eps 1e-9
#define inf 0x3f3f3f3f
#define sz(x) (x).size()
#define ALL(x) (x).begin(), (x).end()
#define ll long long
#define db double
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int N = 1e6 + 10;
char s[N], t[N];
vi a, b;
int main() 
{
	int T = read();
	while(T --)
	{
		int n = read();
		scanf("%s", s);
		scanf("%s", t);
		a.clear();
		b.clear();
		int x = 0;
		rrep(i, n - 1, 0)
	        if (s[i] == x + '0') 
	        {
	            a.pb(i + 1);
	            x ^= 1;
	        }
	    x = 0;
	    rrep(i, n - 1, 0)
	        if (t[i] == x + '0') 
	        {
	            b.pb(i + 1);
	            x ^= 1;
	        }
	    
        printf("%d", (int)sz(a) + (int)sz(b));
        reverse(ALL(a));
        rep0(i, sz(a)) printf(" %d", a[i]);
        rep0(i, sz(b)) printf(" %d", b[i]);
        printf("\n");
    }
    return 0;
}