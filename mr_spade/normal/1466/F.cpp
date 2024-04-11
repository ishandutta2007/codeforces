#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=5e5+5;
int n,m,ans;
int x[N][2];
int dis[N];
vector<int> V;
inline int find(int x)
{
	return dis[x]==x?dis[x]:(dis[x]=find(dis[x]));
}
inline void merge(int x,int y)
{
	dis[find(x)]=find(y);
	return;
}
signed main()
{
	int k;
	register int i,j;
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;i++)
		dis[i]=i;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&k);
		if(k==1)
			scanf("%d",&x[i][0]),x[i][1]=0;
		else
			scanf("%d%d",&x[i][0],&x[i][1]);
		sort(x[i],x[i]+2,[](int x,int y)->bool
		{
			return x>y;
		});
	}
	for(i=1;i<=n;i++)
	{
		x[i][0]=find(x[i][0]);x[i][1]=find(x[i][1]);
		if(x[i][0]==x[i][1])
			continue;
		ans++;
		if(x[i][0]<x[i][1])
			swap(x[i][0],x[i][1]);
		dis[x[i][0]]=x[i][1];
		V.push_back(i);
	}
	printf("%d %d\n",qpow(2,ans),ans);
	for(int x:V)
		printf("%d ",x);
	putchar('\n');
	return 0;
}