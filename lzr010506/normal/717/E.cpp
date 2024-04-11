#include <bits/stdc++.h>
using namespace std;
#define N 666666
int n,col[N];
int M = 0, fst[N],vb[N],nxt[N];
void ins(int a,int b)
{
	++ M;
	nxt[M] = fst[a];
	fst[a] = M;
	vb[M] = b;
}
void insert(int a,int b)
{
	ins(a,b);
	ins(b,a);
}
int a[23333333], ss;
void dfs(int x,int f)
{
	a[++ ss] = x; 
	col[x] ^= 1;
	bool down = 0;
	for (int e=fst[x];e;e=nxt[e])
	{
		int b = vb[e]; 
		if(b == f) continue;
		dfs(b, x); 
		a[++ ss] = x;
		col[x] ^= 1;
	}
	if(col[x] && x != 1)
	{
		a[++ ss] = f;
		col[f] ^= 1;
		a[++ ss] = x; 
		col[x] ^= 1;
	}
}
int main()
{
	scanf("%d",&n);
	int cc=0,p;
	for(int i=1;i<=n;i++)
		scanf("%d",col+i), col[i]=col[i]<0, cc+=col[i];
	for(int i=1;i<n;i++)
	{ 
		int a,b; scanf("%d%d",&a,&b);
		if(a>b) swap(a,b);
		if(a==1) p=b;
		insert(a,b);
	}
	if(cc == 1 && col[1])
	{
		printf("1 %d 1 %d\n",p,p);
		return 0;
	}
	col[1] ^= 1;
	dfs(1, 0);
	if(col[1])
	{
		if(a[ss] == 1) ss --;
		else a[++ ss] = 1;
	}
	for(int i = 1; i <= ss; i ++)
		printf("%d ", a[i]);
	return 0;
}