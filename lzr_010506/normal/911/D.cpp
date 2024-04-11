#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define ll unsigned long long
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define ls rt << 1
#define rs rt << 1 | 1
#define INF 0x3f3f3f3f
#define pll pair<ll, ll>
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

const int N = 1510;

int a[N];
int n = 0, m = 0;
ll ans = 0;

int main() 
{
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
		rep(j, i + 1, n)
			if (a[i] > a[j]) ans ++;
    
    ans &= 1;
    m = read();
    rep(i, 1, m)
    {
        int l = read();
        int r = read();
        if (((r - l + 1) >> 1) & 1) ans ^= 1;
        if (ans) printf("odd\n");
        else printf("even\n");
    }
    return 0;
}