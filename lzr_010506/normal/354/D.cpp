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
using namespace std;


int n, h, r, c;
int i, j, k, x, y;
int f[2][N], s[N], *F = f[0], *G = f[1];

pii V[N];

inline void minn(int &x, const int y) {x > y ? x = y : 0;}

int main()
{
	n = read();
	k = read();
    h = min(n, (int)sqrt(6 * k));
    rep0(i, k)
    {
    	int r = read();
    	int c = read();
        x = n - r + c; y = n - r + 1;
        V[i] = mp(x, y);
    }
    sort(V, V + k);
    memset(f, 127, sizeof f);
    F[0] = x = 0;
    rep(i, 1, n)
    {
        y = min(i, h);
        memset(G, 127, y + 2 << 2);
        memset(s, 0, y + 2 << 2);
        for(; x < k && V[x].X == i; x ++) s[V[x].Y > y ? y + 1 : V[x].Y] ++;
        rrep(j, y, 0) s[j] += s[j + 1];
        G[0] = F[0] + s[1] * 3;
        rep(j, 1, y) minn(G[0], F[j - 1] + (j * (j + 1) >> 1) + 2 + s[j + 1] * 3);
        rep(j, 1, y)
        {
            G[j] = G[j - 1];
            minn(G[j], F[j - 1] + s[j + 1] * 3);
        }
        swap(F, G);
    }
    printf("%d\n", F[0]);
    return 0;
}