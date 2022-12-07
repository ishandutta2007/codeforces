#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; ++ i)
#define two(x) (1 << (x))
#define lowbit(x) ((x & (-x)))
using namespace std;
typedef long long ll;

const int N=201000;
int a[N],c[N],n,q,ty,l,r,k;
struct guass
{
	int c[32],cnt;
	void clear() 
	{
		cnt = 0;
		rep(i,0,31) c[i] = 0;
	}
	void add(int x, int p = 30)
	{
		for (int i = p; i >= 0 && x; i --)
		{
			x = min(x, x ^ c[i]);
			if (x & two(i)) 
			{
				c[i] = x;
				cnt ++;
				break;
			}
		}
	}
	void print()
	{
		for (int i = 30; i >= 0; i --) printf("%d ",c[i]);
		puts("");
	}
}nd[4*N],ret;
void Modify(int x,int p)
{
	for (; x <= n; x += lowbit(x)) c[x] ^= p;
}
int Query(int x)
{
	int p = 0;
	for (; x; x -= lowbit(x)) p^=c[x];
	return p;
}
void merge(int p)
{
	nd[p].clear();
	for (int i = 30; i >= 0; i --) nd[p].c[i] = nd[p << 1].c[i];
	for (int i = 30; i >= 0; i --) nd[p].add(nd[p << 1 | 1].c[i],i);
}
void build(int p,int l,int r)
{
	if (l == r) 
		nd[p].add(a[l]);
	else
	{
		int mid = (l + r) >> 1;
		build(p << 1, l, mid);
		build(p << 1 | 1, mid + 1, r);
		merge(p);
	}
}
void modify(int p,int l,int r,int x,int v)
{
	if (l == r)
	{
		nd[p].clear();
		a[l] ^= v;
		nd[p].add(a[l]);
	} 
	else
	{
		int mid = (l + r) >> 1;
		if (x <= mid) modify(p << 1, l, mid, x, v);
		else modify(p << 1 | 1, mid + 1, r, x, v);
		merge(p);
	}
}
void query(int p,int l,int r,int tl,int tr)
{
	if(l == tl && r == tr)
		for (int i=30;i>=0;i--) ret.add(nd[p].c[i],i);
	else
	{
		int mid = (l + r) >> 1;
		if (tr <= mid) query(p << 1, l, mid, tl, tr);
		else if (tl > mid) query(p << 1 | 1, mid + 1, r, tl, tr);
		else query(p << 1, l, mid, tl, mid), query(p << 1 | 1, mid + 1, r, mid + 1, tr);
	}
}
int main()
{
	scanf("%d%d",&n,&q);
	rep(i, 1, n + 1) scanf("%d",a + i);
	for (int i = n; i >= 1; i --) a[i] ^= a[i - 1];
	rep(i, 1, n + 1) Modify(i,a[i]);
	build(1, 1, n);
	rep(i,0,q)
	{
		scanf("%d%d%d",&ty,&l,&r);
		if (ty == 1)
		{
			scanf("%d",&k);
			modify(1,1,n,l,k);
			Modify(l,k);
			if(r + 1 <= n)
				modify(1, 1, n, r + 1, k),Modify(r + 1, k);
		} 
		else
		{
			ret.clear();
			if (l + 1 <= r) query(1, 1, n, l + 1, r);
			ret.add(Query(l));
			printf("%d\n", two(ret.cnt));
		}
	}
	return 0;
}