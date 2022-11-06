#include <bits/stdc++.h>
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
#define eps 1e-9
using namespace std;
const db pi = acos(-1.0);
inline int read()
{
    int x = 0, f = 1; char ch = getchar();
    while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
    while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
    return x * f;
}
const int XX = 1000031, XN = 205, P = 1000000007;

int n = 0, l = 0, m = 0;

struct Node
{
    ll x[XN];

    Node() : x() {}

    Node mul(const Node &a) const
    {
        Node z;
        rep(i, 0, m - 1)
        	rep(j, 0, m - 1)
        		z.x[(i + j) % m] += x[i] * a.x[j] % P;
        rep(i, 0, m - 1) z.x[i] %= P;
        return z;
    }
};

Node qpow(Node &x, int times)
{
    Node z;
    z.x[0] = 1;
    while(times)
    {
        if (times & 1) z = z.mul(x);
        x = x.mul(x);
        times >>= 1;
    }
    return z;
}
int t[XX];
int main()
{
	n = read();
	l = read();
	m = read();
    Node a, b, c;
    rep(i, 0, n - 1) {int x = read(); a.x[x % m] ++;}
    rep(i, 0, n - 1) t[i] = read(), b.x[t[i] % m] ++;
    rep(i, 0, n - 1) {int x = read(); c.x[(x + t[i]) % m] ++;}
    printf("%lld\n", a.mul(qpow(b, l - 2)).mul(c).x[0]);
    return 0;
}