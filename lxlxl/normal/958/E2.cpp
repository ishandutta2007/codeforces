#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PI;
const LL N=500005;
LL n,k;
LL a[N];
LL next[N],last[N];
priority_queue<PI,vector<PI>,greater<PI> > q,q1;// 
LL L[N],R[N];// 
int main()
{
	scanf("%I64d%I64d",&k,&n);
	for (LL u=1;u<=n;u++)	scanf("%I64d",&a[u]);
	sort(a+1,a+1+n);
	int nn=n;n=1;
	for (int u=2;u<=nn;u++)
		if (a[u]!=a[n])
			a[++n]=a[u];
	/*for (int u=1;u<=n;u++) printf("%I64d ",a[u]);
	printf("\n");*/
	for (LL u=1;u<=n;u++) next[u]=u+1;
	for (LL u=1;u<=n;u++) last[u]=u-1;
	for (LL u=1;u<n;u++)	q.push(make_pair(a[u+1]-a[u],u));
	for (int u=1;u<n;u++)	L[u]=a[u+1]-a[u];
	for (int u=2;u<=n;u++) R[u]=a[u]-a[u-1];
	LL ans=0;
	for (LL u=1;u<=k;u++)
	{
		while (!q1.empty())
		{
			LL x=q.top().first,xx=q1.top().first;
			LL y=q.top().second,yy=q1.top().second;
			if (x!=xx||y!=yy) break;
			q.pop();q1.pop();
		}
		LL x=q.top().first,y=q.top().second,yy=next[y];q.pop();
		ans=ans+x;
	//	printf("%d %d %d\n",x,y,next[y]);
		if (last[y]!=0)//0 
			q1.push(make_pair(R[y],last[y]));
		if (next[yy]!=n+1)
			q1.push(make_pair(L[yy],yy));
		if (last[y]!=0&&next[yy]!=n+1)	
		{
		//	printf("%d %d\n",R[y]+L[yy]-x,last[y]);
			q.push(make_pair(R[y]+L[yy]-x,last[y]));
		}
		last[next[yy]]=last[y];next[last[y]]=next[yy];
		L[last[y]]=R[y]+L[yy]-x;
		R[next[yy]]=R[y]+L[yy]-x;
	}
	printf("%I64d\n",ans);
	return 0;
}