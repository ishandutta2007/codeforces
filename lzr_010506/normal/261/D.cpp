#include <bits/stdc++.h>
#define ll long long
#define ls rt << 1
#define rs rt << 1 | 1
#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define X first
#define Y second
using namespace std;
const int N = 1e6 + 10;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
int n, t;
int k, mxb;
int a[N], b[N], g[N << 1], tot = 1, bit[N << 1];

inline int lowbit(int x)
{
	return x & (-x);
}

int query(int x)
{
	int ret = 0;
	while(x)
	{
		ret = max(ret, bit[x]);
		x -= lowbit(x);
	}
	return ret;
}

void add(int x, int add)
{
	while(x <= tot) 
	{
		bit[x] = max(add, bit[x]);
		x += lowbit(x);
	}
}

int main()
{
	k = read();
	n = read();
	mxb = read();
	t = min(read(), n);
	t = min(t, mxb);
	while(tot < mxb) tot <<= 1;
	while(k --)
	{
		memset(bit, 0, sizeof(bit));
		memset(g, 0, sizeof(g));
		for(int i = 0; i < n; i ++) b[i] = read();
		for(int i = 1; i <= t; i ++)
			for(int j = 0; j < n; j ++)
			{
				int tmp = query(b[j] - 1);
				if(tmp >= g[j])
				{
					add(b[j], tmp + 1);
					g[j] = tmp + 1;
				}
			}
		cout << query(tot) << endl;
	}
	return 0;
}