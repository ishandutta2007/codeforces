#include <bits/stdc++.h>
using namespace std;
int n, l, r;

inline int min(int l, int r)
{
	if(l < r) return l;
	return r;
}

inline int max(int l, int r)
{
	if(l < r) return r;
	return l;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

bool Do(int x,int p,int mx)
{
	int ans = 1, ok = 1;
	for(; p; p >>= 1)
	{
		if(p & 1)
			if(1ll * ans * x > mx || !ok)
				return 0;
			else ans *= x;
		if(1ll * x * x > mx) ok = 0;
		else x *= x;
	}
	return 1;
}

int Q_pow(int x, int p)
{
	int ans = 1;
	while(p)
	{
		if(p & 1) ans *= x;
		x *= x;
		p >>= 1;
	}
	return ans;
}

int calc(int y, int x)
{
	bool ok = Do(y, n - 1, r);
	if(!ok) return 0;
	int Y = Q_pow(y, n - 1);
	int St = (l - 1) / Y + 1, End = r / Y;
	ok = Do(x, n - 1, r);
	if(!ok) return 0;
	int X = Q_pow(x, n - 1);
	int St2 = (l - 1) / X + 1, End2 = r / X;
	return max(0, min(End2, End) - max(St2, St) + 1);
}

int gcd(int x, int y)
{
	while(x)
	{
		int z = x;
		x = y % x;
		y = z;
	}
	return y;
}

int main()
{
	n = read();
	l = read();
	r = read();
	if(n == 1)
	{
		cout << (r - l + 1);
		return 0;
	}
	if(n == 2)
	{
		cout << 1ll * (r - l + 1) * (r - l + 1) - (r - l + 1);
		return 0;
	}
	long long ans = 0;
	calc(2, 3);
	for(int i = 1; 1ll * i * i <= r; i ++)
		for(int j = 1; 1ll * j * j <= r; j ++)
			if(gcd(i, j) == 1)
			{
				int t = calc(i, j);
				ans += t;
			}
	cout << ans - (r - l + 1) << endl;
	return 0;
}