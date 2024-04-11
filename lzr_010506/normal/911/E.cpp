#include <bits/stdc++.h>
#define rep(i,  x,  y) for(int i = x; i <= y; i ++)
#define rrep(i, x,  y) for(int i = x; i >= y; i --)
#define ll unsigned long long
#define X firStk
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
int a[200010], n, k, d = 1, e, f;
stack<int> Stk;
int main()
{
	n = read();
	k = read();
	rep(i, 1, k)
	{
    	a[i] = read();
    	if (!Stk.empty() && a[i] > Stk.top())
    	{
    		printf("-1");
    		return 0;
		}
		Stk.push(a[i]);
		while (!Stk.empty() && Stk.top() == d) Stk.pop(), d ++;
	}
	rep(i, 1, k) printf("%d ", a[i]);
	if (Stk.empty()) rrep(i, n, k + 1) printf("%d ",i);
	else
	{
		while (!Stk.empty())
		{
			rrep(i, Stk.top() - 1, d) printf("%d ", i);
			d = Stk.top() + 1;
			Stk.pop();
		}
		rrep(i, n, d) printf("%d ",i);
	}
	return 0;
}