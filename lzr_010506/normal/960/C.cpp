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
const int P = 1e9 + 1;
int X,d;
int gs(int x)
{ 
	int s = 1; 
	while ((1ll << (s + 1)) - 1 <= x) s ++; 
	return s; 
}
ll s[10010], ans = 0;
int main()
{
	cin >> X >> d;
	ll cnt = 1;
	while (X)
	{
		int p = gs(X); 
		X -= (1 << p) - 1;
		rep(i, 1, p) s[++ ans] = cnt;
		cnt += P;
	}
	cout << ans << endl;
	rep(i, 1, ans) cout << s[i] << " ";
	return 0;
}