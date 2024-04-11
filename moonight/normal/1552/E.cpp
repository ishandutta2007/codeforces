#include<bits/stdc++.h>
using namespace std;
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
	char c=getchar();int x=0,w=1;
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-')w=-1,c=getchar();
	while(isdigit(c))x=x*10+c-48,c=getchar();
	return x*w;
}
inline void cmx(int&a,int b){a=a>b?a:b;}
inline void cmn(int&a,int b){a=a<b?a:b;}
const int N=10005;
int n,k,m,nn,a[N],b[105],c[105][105],d[105],v[105],ans1[105],ans2[105];
int main()
{
	n=rd();k=rd();m=n*k;
	rep(i,1,m)a[i]=rd();
	rep(i,1,m)b[a[i]]++,c[a[i]][b[a[i]]]=i;
	rep(i,1,n)v[i]=0;
	int t=(n+k-2)/(k-1),tt=n;
	rep(i,1,k-1)
	{
		nn=0;
		rep(j,1,n)if(!v[j])d[++nn]=c[j][i+1];
		sort(d+1,d+nn+1);
		t=min(t,tt);if(!t)break;
		rep(j,1,t)
		{
			int x=a[d[j]];v[x]=1;
			ans1[x]=c[x][i];ans2[x]=d[j];
		}
		tt-=t;
	}
	rep(i,1,n)printf("%d %d\n",ans1[i],ans2[i]);
	return 0;
}