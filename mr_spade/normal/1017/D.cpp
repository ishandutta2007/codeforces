#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline") 
#include<cstdio>
#include<algorithm>
using std::sort;
const int N=1e7+5,M=5e5+5;
int n,m,q,tot;
int w[M],cc[M];
char s[M];
int cnt[M],co[M];
struct cell
{
	int x,y,s;
}c[N];
int wo[M],cp[N];
struct query
{
	int id,x,k;
}e[M];
int ans[M];
inline bool cmp(cell a,cell b)
{
	return a.s<b.s;
}
inline bool cmp2(query a,query b)
{
	return a.k<b.k;
}
signed main()
{
	//freopen("test.in","r",stdin);
	register int i,j;
	scanf("%d%d%d",&n,&m,&q);
	for(i=0;i<n;i++)
		scanf("%d",&w[n-i-1]);
	for(i=0;i<1<<n;i++)
		for(j=0;j<n;j++)
			if(i>>j&1)
				cc[i]+=w[j];
	for(i=0;i<1<<n;i++)
		for(j=i;j<1<<n;j++)
		{
			tot++;c[tot].x=i;c[tot].y=j;
			c[tot].s=cc[((1<<n)-1)^i^j];
			wo[c[tot].s]++;
		}
	for(i=1;i<=1200;i++)
		wo[i]+=wo[i-1];
	for(i=1;i<=tot;i++)
		cp[wo[c[i].s]--]=i;
	for(i=1;i<=m;i++)
	{
		int x=0;
		scanf("%s",s);
		for(j=0;j<n;j++)
			x=x*2+s[j]-'0';
		cnt[x]++;
	}
	for(i=1;i<=q;i++)
	{
		int x=0;
		scanf("%s",s);
		for(j=0;j<n;j++)
			x=x*2+s[j]-'0';
		e[i].id=i;e[i].x=x;
		scanf("%d",&e[i].k);
	}
	sort(e+1,e+q+1,cmp2);
	i=1;j=1;
	while(i<=tot&&j<=q)
		if(c[cp[i]].s<=e[j].k)
		{
			co[c[cp[i]].x]+=cnt[c[cp[i]].y];
			if(c[cp[i]].x!=c[cp[i]].y)
				co[c[cp[i]].y]+=cnt[c[cp[i]].x];
			i++;
		}
		else
			ans[e[j].id]=co[e[j].x],j++;
	while(j<=q)
		ans[e[j].id]=co[e[j].x],j++;
	for(i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}