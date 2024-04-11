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
int n, k, p[6000010];
set<int> vis;
pii a[6000010];
int main()
{
	n = read();
	k = read();
	rep(i, 1, n)
	{
		a[i].X = read();
		a[i].Y = i;
		vis.insert(i + k);
	}
	sort(a + 1, a + 1 + n);
	reverse(a + 1, a + 1 + n);
	ll ans = 0;
	rep(i, 1, n)
	{
		auto w = vis.lower_bound(a[i].Y);
		ans += (*w - a[i].Y) * (ll)a[i].X;
		p[a[i].Y] = *w;
		vis.erase(*w);
	}
	cout << ans << endl;
	rep(i, 1, n)
		cout << p[i] << " ";
	return 0;
}