#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=1000010;
int n,x[MAXN],L,R,d[MAXN],dis[MAXN];
int q[MAXN],l,r,cur;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	scanf("%d%d",&R,&L);
	sort(x+1,x+n+1);
	n=unique(x+1,x+n+1)-x-1;
	for(int i=1;i<=n;i++)
		for(int j=L/x[i]*x[i];j<=R;j+=x[i])
			if(j>=L&&j<=R) d[j-L]=x[i];
	memset(dis,-1,sizeof(dis));
	q[l=r=1]=L,dis[0]=0,cur=L;
	while(l<=r)
	{
		int x=q[l++],k=x+max(1,d[x-L]-1);
		while(cur+1<=R&&cur+1<=k) cur++,dis[cur-L]=dis[x-L]+1,q[++r]=cur;
	}
	printf("%d\n",dis[R-L]);
	return 0;
}