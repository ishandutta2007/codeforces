#include <bits/stdc++.h>
using namespace std;
const int N = 200010;
int la[N], lb[N], a[N], b[N], f[N], s[N], n, ff[N], sum[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int lowbit(int x)
{
	return x & (-x);
}

void Add(int x, int d)
{
	x ++;
	while(x <= n)
	{
		sum[x] += d;
		x += lowbit(x);
	}
}

int Que(int x)
{
	x ++;
	int ans = 0;
	while(x)
	{
		ans += sum[x];
		x -= lowbit(x);
	}
	return ans;
}
int main()
{
	n = read();
	for(int i = 0; i < n; i ++) la[i] = read();
	for(int i = 0; i < n; i ++) lb[i] = read();
	for(int i = 0; i < n; i ++) Add(i, 1);
	for(int i = 0; i < n; i ++)
	{
		a[i] = Que(la[i] - 1);
		Add(la[i], -1);
	}
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i ++) Add(i, 1);
	for(int i = 0; i < n; i ++)
	{
		b[i] = Que(lb[i] - 1);
		Add(lb[i], -1);
		s[i] = a[i] + b[i];
	}
    //for(int i = 0; i < n; i ++)
    //    cout << s[i] << " ";
	memset(sum, 0, sizeof(sum));
	for(int i = 0; i < n; i ++)
	{
		Add(i, 1);
		ff[i] = 1;
	}
	for(int i = n - 1; i > 0; i --)
	{
		s[i - 1] += s[i] / (n - i);
		s[i] %= (n - i);
	}
	s[0] %= n;
	int rr = n - 1;
	for(int i = 0; i < n; i ++)
	{
		int r = rr;
		int l = 0;
		while(l < r)
		{
			int mid = l + (r - l + 1) / 2;
			int t = Que(mid - 1);
			if(t <= s[i]) l = mid;
			else r = mid - 1;
		}
		Add(l, -1);
		ff[l] = 0;
		printf("%d ", l);
		while(!ff[rr]) rr --;
	}
	return 0;
}