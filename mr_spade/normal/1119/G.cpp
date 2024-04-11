#include<cstdio>
#include<algorithm>
#include<utility>
#include<vector>
#define mp make_pair
#define fi first
#define se second
using std::lower_bound;
using std::sort;
using std::pair;
using std::mp;
using std::vector;
const int N=1e6+5;
int n,m,sum;
int a[N],b[N];
int d[N],f[N];
int tot;
vector<pair<int,int> > V[N];
signed main()
{
	int x,ptr;
	register int i,j,k;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		scanf("%d",&x),sum+=x,a[i]+=x/n,b[i]+=x%n;
	ptr=1;
	while(ptr<=m)
	{
		while(ptr<=m&&b[ptr]==0)
			ptr++;
		if(ptr>m)
			break;
		tot++;
		for(i=ptr-1,x=0;i<m&&x+b[i+1]<=n;i++,x+=b[i])
			V[tot].push_back(mp(x+b[i+1],i+1)),d[i+1]=x+b[i+1];
		if(i!=m&&n-x!=0)
			V[tot].push_back(mp(n,i+1));
		if(i==m)
			break;
		b[i+1]-=n-x;ptr=i+1;
	}
	d[m]=n;sort(d+1,d+m+1);
	for(i=1;i<=m;i++)
		f[i]=d[i]-d[i-1];
	printf("%d\n",(sum+n-1)/n);
	for(i=1;i<=m;i++)
		printf("%d ",f[i]);
	putchar('\n');
	for(i=1;i<=n;i++)
		for(j=1;j<=a[i];j++)
		{
			for(k=1;k<=m;k++)
				printf("%d ",i);
			putchar('\n');
		}
	for(i=1;i<=tot;i++)
	{
		x=0;
		for(j=0;j<(int)V[i].size();j++)
		{
			ptr=lower_bound(d+1,d+m+1,V[i][j].fi)-d;
			for(k=x+1;k<=ptr;k++)
				printf("%d ",V[i][j].se);
			x=ptr;
		}
		for(k=x+1;k<=m;k++)
			printf("1 ");
		putchar('\n');
	}
	return 0;
}