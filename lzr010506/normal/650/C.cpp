#include<bits/stdc++.h>
#define N 1000010
using namespace std;
int A[N],fa[N],v[N<<1],ne[N<<1],l,head[N],ds[N],n,m,i,j,a[N],b[N],c[N],q[N],r;
struct Node
{
	int x,y;
}d[N];
bool cmp(Node x,Node y)
{
	return x.x < y.x;
}
int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}
void add(int x,int y)
{
	v[++l]=y;
	ne[l]=head[x];
	head[x]=l;
	ds[y]++;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(i = 0; i < n; i ++)
		for(j = 0; j < m; j ++)
		{
			scanf("%d", &a[i * m + j]);
			b[i * m + j] = a[i * m + j];
			c[i + j * n] = a[i * m + j];
			fa[i * m+ j ] = i * m + j;
		}
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++)
			d[j].x = b[i * m + j], d[j].y = i * m + j;
		sort(d, d + m, cmp);
		for(j = 1; j < m; j ++)
			if(d[j].x == d[j - 1].x)
				fa[find(d[j].y)] = find(d[j - 1].y);
	}
	for(i = 0; i < m; i ++)
	{
		for(j = 0; j < n; j ++)d[j].x = c[i * n + j], d[j].y = j * m + i;
		sort(d, d + n, cmp);
		for(j = 1; j < n; j ++)
			if(d[j].x == d[j - 1].x)
				fa[find(d[j].y)] = find(d[j - 1].y);
	}
	for(i = 0; i < n; i ++)
	{
		for(j = 0; j < m; j ++) d[j].x = b[i * m + j], d[j].y = i * m + j;
		sort(d, d + m, cmp);
		for(j = 1; j < m; j ++)
			if(d[j].x != d[j - 1].x)
				add(find(d[j - 1].y), find(d[j].y));
	}
	for(i = 0; i < m; i ++)
	{
		for(j = 0; j < n; j ++)d[j].x=c[i*n+j],d[j].y=j*m+i;
		sort(d, d + n, cmp);
		for(j = 1; j < n; j ++)
			if(d[j].x != d[j - 1].x)
				add(find(d[j - 1].y), find(d[j].y));
	}
	for(i = 0;i < n *m ; i++)
		if(find(i) == i && ds[i] == 0)
			q[++r ] = i, A[i] = 1;
	for(l = 1; l <= r; l ++)
		for(i = head[q[l]]; i; i = ne[i])
		{
			ds[v[i]] --;
			if(ds[v[i]] == 0)q[++ r] = v[i], A[v[i]] = A[q[l]] + 1;
		}
	for(i = 0; i < n; i ++, puts(""))
		for(j = 0; j < m; j ++)
			printf("%d ",A[find(i*m+j)]);
	return 0;
}