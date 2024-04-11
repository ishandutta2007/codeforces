#include<bits/stdc++.h>
#define ll long long
#define db double
#define X first
#define Y second
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define rep0(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(i,a) for(int i=0;i<a.size();++i)
inline int rd()
{
	char c=getchar();int x=0;
	while(!isdigit(c))c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x;
}
const int N=70005;
int n,nn,m,a[N],b[N],c[N];
std::vector<int>g[N];
int d[N];
void sol()
{
	n=rd();nn=1<<n;m=nn*n/2;
	rep(i,1,m)
	{
		int u,v;u=rd();v=rd();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	rep0(i,0,nn)c[i]=-1;
	a[0]=0;b[0]=0;c[0]=0;
	fore(i,g[0])a[1<<i]=g[0][i],b[g[0][i]]=1<<i,c[g[0][i]]=1;
	rep(i,2,n)
	{
		rep0(j,0,nn)
		{
			int s=0,t=0;
			fore(k,g[j])if(c[g[j][k]]==i-1)s++,t|=b[g[j][k]];
			if(c[j]==-1&&s==i){a[t]=j;b[j]=t;c[j]=i;}
		}
	}
	rep0(i,0,nn)printf("%d ",a[i]);
	puts("");
	rep0(i,0,nn)g[i].clear();
	rep0(i,0,nn)
	{
		int s=0;
		rep0(j,0,n)if(i>>j&1)s^=j;
		d[i]=s;
	}
	if(n==1)puts("0 0");
	else if(n==2)
	{
		rep0(i,0,4)printf("%d ",d[b[i]]);
		puts("");
	}
	else if(n==3)puts("-1");
	else if(n==4)
	{
		rep0(i,0,16)printf("%d ",d[b[i]]);
		puts("");
	}
	else if(n==8)
	{
		rep0(i,0,256)printf("%d ",d[b[i]]);
		puts("");
	}
	else if(n==16)
	{
		rep0(i,0,65536)printf("%d ",d[b[i]]);
		puts("");
	}
	else puts("-1");
}
int main()
{
	int T=rd();
	while(T--)sol();
	return 0;
}