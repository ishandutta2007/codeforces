#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 1005
int T,n,m,sz,a[N],ord[N];
int ans[M*M],st[3][M*M],id[M][M];
bool cmp(int x,int y) {return a[x]<a[y];}
int f(int fl,int x,int w)
{
	int t=min(x,st[fl][0]);
	for(int i=1;i<=t;++i)
		ans[st[fl][st[fl][0]--]]=w;
	return x-t;
}
void slv()
{
	scanf("%d %d",&m,&n);sz=1;
	id[0][0]=st[0][0]=st[1][0]=st[2][0]=0;
	for(int i=1;i<=n;++i)
		ord[i]=i,scanf("%d",&a[i]);
	sort(ord+1,ord+n+1,cmp);
	while((sz+1)/2*sz<a[ord[n]] ||
		  sz*sz-(sz/2)*(sz/2)<m) ++sz;
	for(int i=1,t;i<=sz;++i)
		for(int j=1;j<=sz;++j)
			if(i&1 || j&1)
			{
				t=(i&1)*2+(j&1)-1;
				id[i][j]=++id[0][0];
				st[t][++st[t][0]]=id[i][j];
			}
	for(int i=1;i<=id[0][0];++i) ans[i]=0;
	for(int i=n,t;i;--i)
		if(st[0][0])
		{
			t=f(0,a[ord[i]],ord[i]);
			f(2,t,ord[i]);
		}
		else
		{
			t=f(1,a[ord[i]],ord[i]);
			f(2,t,ord[i]);
		}
	printf("%d\n",sz);
	for(int i=1;i<=sz;++i,puts(""))
		for(int j=1;j<=sz;++j)
			printf("%d ",ans[id[i][j]]);
}
int main()
{
	scanf("%d",&T);
	while(T--) slv();return 0;
}