#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005,K=10,k=7;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N],b[N],f[N][N],g[N][K],h[N][N],s[N],v[2*N],m,ans,s1[N],a1[N];
int main()
{
	F(i,1,read(n)+1)v[m++]=read(a[i]);
	m=(sort(v,v+m),unique(v,v+m))-v;
	F(i,1,n+1)b[i]=lower_bound(v,v+m,a[i])-v;
	F(i,1,n+1)if(v[s1[i]=lower_bound(v,v+m,a[i]-1)-v]!=a[i]-1)s1[i]=-1;
	F(i,1,n+1)if(v[a1[i]=lower_bound(v,v+m,a[i]+1)-v]!=a[i]+1)a1[i]=-1;
	F(i,1,n+1)F(j,0,i)
	{
		ans=max(ans,f[i][j]=max(s[j],max(g[j][a[i]%7],h[j][b[i]]))+1);
		if(j)
		{
			g[i][a[j]%7]=max(g[i][a[j]%7],f[i][j]);
			h[i][b[j]]=max(h[i][b[j]],f[i][j]);
			if(~s1[j])h[i][s1[j]]=max(h[i][s1[j]],f[i][j]);
			if(~a1[j])h[i][a1[j]]=max(h[i][a1[j]],f[i][j]);
		}
		else s[i]=max(s[i],f[i][j]);
		g[j][a[i]%7]=max(g[j][a[i]%7],f[i][j]);
		h[j][b[i]]=max(h[j][b[i]],f[i][j]);
		if(~s1[i])h[j][s1[i]]=max(h[j][s1[i]],f[i][j]);
		if(~a1[i])h[j][a1[i]]=max(h[j][a1[i]],f[i][j]);
	}
	printf("%d\n",ans);
	return 0;
}