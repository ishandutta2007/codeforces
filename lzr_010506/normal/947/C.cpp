#include <bits/stdc++.h>
#include <math.h>
#define uint unsigned long long
#define ll long long
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
#define ept 1e-9

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
}using namespace std;

const int N = 300010;
int n;
const int M = N * 31;

int a[N], P[N];
int ch[M][2], cnt[M];
int tot = 1;
void update(int x, int v)
{
    int rt = 1;
    cnt[1] += v;
    rrep(i, 29, 0)
    {
        int t = (x >> i) & 1;
        if (!ch[rt][t]) ch[rt][t] = ++ tot;
        rt = ch[rt][t];
        cnt[rt] += v;
    }
}

int query(int x)
{
    int ret = 0, rt = 1;
 	rrep(i, 29, 0)
 	{
        int t = (x >> i) & 1;
        if (cnt[ch[rt][t]])
        {
            ret |= (t << i);
            rt = ch[rt][t];
        }
        else
        {
            ret |= ((t ^ 1) << i);
            rt = ch[rt][t ^ 1];
        }
    }
    return ret;
}

int main()
{
	n = read();
	rep(i, 1, n) a[i] = read();
	rep(i, 1, n)
	{
        P[i] = read();
        update(P[i], 1);
    }
    rep(i, 1, n)
    {
        int t = query(a[i]);
        a[i] ^= t;
        update(t, -1);
        printf("%d ", a[i]);
    }
    return 0;
}