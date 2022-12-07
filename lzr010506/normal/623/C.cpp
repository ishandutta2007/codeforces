#include <bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define X first
#define Y second
#define inf 100000000000
using namespace std;
#define N 100010
pll a[N];
pll lft[N], rht[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline int min(int a, int b)
{
	if(a < b) return a;
	return b;
}

inline int max(int a, int b)
{
	if(a < b) return b;
	return a;
}

inline ll min(ll a, ll b)
{
	if(a < b) return a;
	return b;
}

inline ll max(ll a, ll b)
{
	if(a < b) return b;
	return a;
}


bool f (int n, ll mid) 
{
    for (int i = 1; i <= n; i++) 
    {
        int dir = (a[i].X < 0)? 1: -1;
        int lo = 0;
        int hi = n;
        int j;
        while (lo <= hi) 
        {
            int m = (lo + hi) >> 1;
            int tmp = i + dir * m;
            if (tmp < 1 || tmp > n) hi = m - 1;
            else if ((abs(a[tmp].X) <= abs(a[i].X)) && ((a[tmp].X - a[i].X) * (a[tmp].X - a[i].X) <= mid))  lo = m + 1, j = tmp;
            else hi = m - 1;
        }
        int b = min(i, j), e = max(i, j);
        if (b == 1 && e == n) return true;
        ll mny = min(lft[b - 1].X, rht[e + 1].X);
        ll mxy = max(lft[b - 1].Y, rht[e + 1].Y);
        if (((mxy - mny) * (mxy - mny) <= mid) && (((a[i].X * a[i].X) + (mny * mny)) <= mid) && (((a[i].X * a[i].X) + (mxy * mxy))) <= mid) return true;
    }
    return false;
}

int main() 
{
    int n;
    while (cin >> n) 
    {
        for (int i = 1; i <= n; i ++) 
            a[i].X = read(), a[i].Y = read();
        sort(a + 1, a + n + 1);
        lft[0] = {inf, -inf};
        for (int i = 1; i <= n; i ++) 
        {
            lft[i].X = min(lft[i - 1].X, a[i].Y);
            lft[i].Y = max(lft[i - 1].Y, a[i].Y);
        }

        rht[n+1] = {inf, -inf};
        for (int i = n; i >= 1; i --) 
        {
            rht[i].X = min(rht[i+1].X, a[i].Y);
            rht[i].Y = max(rht[i+1].Y, a[i].Y);
        }

        ll ans = min((lft[n].X - lft[n].Y) * (lft[n].X - lft[n].Y), (a[1].X - a[n].X) * (a[1].X - a[n].X));
        ll lo = 0, hi = ans;
        while (lo <= hi) 
        {
            ll mid = (lo + hi) >> 1LL;
            if (f(n, mid)) 
            {
                hi = mid - 1LL;
                ans = mid;
            } 
            else lo = mid + 1LL;
        }

        cout << ans << endl;
    }
}