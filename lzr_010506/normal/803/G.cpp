#include <bits/stdc++.h>
using namespace std;
inline int read()
{
	int x = 0,  f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
#define N 10000010
int ntot = 0;
int b[100010];
int n, k;
int ST[100010][20], lg[N], bin[N];

inline int stq(int l, int r)
{
	int t = lg[r - l + 1], m = r - bin[t] + 1;
	return min(ST[l][t], ST[m][t]);
}
int ls[N], rs[N], mn[N], tag[N];
inline int newnode(int x) 
{
	int i = ++ ntot; 
	mn[i] = tag[i] = x; 
	return i;
} 

inline int get(int l, int r)
{
	int res; 
	if(r - l >= n) res = stq(1, n);
	else 
	{
		l = l % n; 
		if(!l)  l = n;
		r = r % n; 
		if(!r) r = n;
		if(r < l) res = min(stq(1,  r),  stq(l,  n));
		else res = stq(l,  r);
	}
return res;
}
inline int val(int i, int l, int r) 
{
	if(i) return mn[i];
	else return get(l, r);
}
inline void pushup(int i, int l, int r)
{
	int mid = (l + r) >> 1;
	mn[i] = min(val(ls[i], l, mid), val(rs[i], mid + 1, r));
}
inline void mdf(int &i, int x)
{
	if(i)
	{ 
		mn[i] = tag[i] = x; 
		return; 
	}
	i = newnode(x);
}
inline void pushdown(int i)
{
	int x=tag[i];
	if(x) 
	{
		mdf(ls[i], x);  
		mdf(rs[i], x); 
		tag[i] = 0;
	}
}
int query(int i, int l, int r, int fl, int fr)
{
	if(r < fl || fr < l) return 1e9+1;
	if(fl <= l && r <= fr) return val(i, l, r);
	pushdown(i); 
	int mid = (l + r) >> 1;
	return min( query(ls[i], l, mid, fl, fr), query(rs[i], mid + 1, r, fl, fr));
}
void modify(int &i, int l, int r, int fl, int fr, int x)
{
	if(r<fl||fr<l) return ;
	if(fl <= l && r <= fr) 
	{
		mdf(i, x); 
		return ;
	}
	if(!i) i = ++ ntot;
	pushdown(i); 
	int mid = (l + r) >> 1;
	modify(ls[i], l, mid, fl, fr, x);
	modify(rs[i], mid + 1, r, fl, fr, x);
	pushup(i, l, r);
}
int root=0;
int main()
{
	n = read(); 
	k = read();
	lg[0] = -1; 
	for(int i = 1; i < N; i ++) lg[i] = lg[i >> 1] + 1;
	bin[0] = 1; 
	for(int i = 1; i <= 20; i ++) bin[i] = bin[i - 1] << 1;
	for(int i = 1; i <= n; i ++) ST[i][0] = b[i] = read();
	for(int j = 1; j < 20; j ++) 
		for(int i = 1; i + bin[j] - 1 <= n; i ++) 
			ST[i][j] = min(ST[i][j - 1], ST[i + bin[j - 1]][j - 1]);
	int qq = read();
	while(qq --)
	{
		int op = read(), fl = read(), fr = read();
		if(op == 1) modify(root, 1, n * k, fl, fr, read());
		else
		{
			int res = query(root, 1, n * k, fl, fr);
			printf("%d\n", res);
		}
		
	}
	return 0;
}