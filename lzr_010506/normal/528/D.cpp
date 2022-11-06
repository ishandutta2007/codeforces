#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
#define ls rt << 1
#define rs rt << 1 | 1
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
typedef complex<double> E;
const int mod = 1e9 + 7;
const int Mn = 8e5 + 10;
const db Pi = acos(-1.0);
int n, m,N,M,K,L;
int ans[Mn],rev[Mn],id[Mn],cnt[5],vis[Mn][5];
char a[Mn],b[Mn];
E A[Mn],B[Mn];

void FFT(E *a,int f)
{
	rep(i, 0, N - 1) if (rev[i] > i) swap(a[i], a[rev[i]]);

    for (int i = 1; i < N; i <<= 1)
    {
        E wn(cos(Pi / i), sin(Pi / i));
        for (int p = i << 1, j = 0; j < N; j += p)
        {
            E w(1, 0);
            for (int k = 0; k < i; k ++, w *= wn)
            {
                E x = a[k + j], y = w * a[k + j + i];
                a[k + j] = x + y;
                a[k + j + i] = x - y;
            }
        }
    }
    if (f == -1) reverse(a + 1, a + N);
}
int main()
{
    scanf("%d%d%d",&n,&m,&K);
    scanf("%s%s", a + 1, b + 1);
    id['A'] = 1;
    id['T'] = 2;
    id['G'] = 3;
    id['C'] = 4;
    int l = 0, r = 0;
    rep(i, 1, n)
    {
        while (l < n && l < i - K) cnt[id[(int)a[l ++]]] --;
        while (r < n && r < i + K) cnt[id[(int)a[++ r]]] ++;
        rep(j, 1, 4)
        	if (cnt[j])
        		vis[i][j] = 1;
    }
    M = n + m;
    for (N = 1; N <= M; N <<= 1) L ++;
   	rep(i, 0, N - 1) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (L - 1));
    rep(k, 1, 4)
    {
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        rep(i, 1, n)
        {
            if (vis[i][k]) A[i - 1] = 1;
            else A[i - 1] = 0;
        }

        rep(i, 1, m)
        {
            if (id[(int)b[i]] == k) B[m - i] = 1;
            else B[m - i] = 0;
        }
        FFT(A, 1);
        FFT(B, 1);
        rep(i, 0, N - 1) A[i] *= B[i];
        FFT(A, -1);
        rep(i, 0, N - 1) ans[i] += (A[i].real() + 0.5) / N;
    }
    int res = 0;
    rep(i, 0, N - 1) if (ans[i] == m) res ++;
    printf("%d", res);
    return 0;
}