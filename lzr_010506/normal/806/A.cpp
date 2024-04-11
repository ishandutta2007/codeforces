#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int x, y, p, q;
ll Mx = 1e18;
ll check(int i)
{
	ll pp = p;
	ll qq = q;
	pp *= i;
	qq *= i;
	ll xx = x;
	ll yy = y;
	yy += (pp - xx);
	//cout << xx << " " << yy << " " << pp << " " << qq;
	if(pp < x) return 1e18;
	if(yy > qq) return 1e18;
	return (qq - y);
}

int main()
{
	int T;
	T = read();
	while(T --)
	{
		x = read();
		y = read();
		p = read();
		q = read();

		//cout << check(7) << endl;

		int l = 1, r = 1e9;
        Mx = 1e18;
		while(l <= r)
		{
			int mid = (l + r) >> 1;
			if(check(mid) >= Mx) l = mid + 1;
			else r = mid - 1, Mx = check(mid);
		}
		if(Mx == 1e18) cout << -1 << endl;
		else cout << Mx << endl;
	}
	return 0;
}