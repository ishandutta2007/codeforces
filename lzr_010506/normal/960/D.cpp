#include <bits/stdc++.h>
#define uint unsigned long long
#define ll long long
#define db long double
//#define ls rt << 1
//#define rs rt << 1 | 1
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
const int N = 2e5 + 10;
const int P = 1e9 + 7;

ll s1[100010], s2[100010];
int gt(ll x)
{
    int tms = 0;
    ll now = 1;
    while(now < x) now = now << 1, tms ++;
    if(now == x) return tms;
    else return tms - 1;
}
int main()
{
	int T = read();
	while(T --)
	{
		int op = read();
		if(op == 1 || op == 2)
		{
			ll x = read1();
			ll k = read1();
			int py = gt(x);
			ll tp = 1ll << py;
			if(op == 1) s1[py] = ((s1[py] + k) % tp + tp) % tp;
			else s2[py] = ((s2[py] + k) % tp + tp) % tp;
		}
		else
		{
			ll x = read1();
			int py = gt(x);
			for(ll fa; x; x = fa, py --)
			{
				cout << x << " ";
				ll st = 1ll << py;
				ll del = x - st;
				del = (del + s1[py] + s2[py] - s1[py - 1] * 2 + st) % st;
				//cout << st << " " << del << endl;
				fa = (st + del) / 2;
			}
			puts("");
		}
	}
    return 0;
}