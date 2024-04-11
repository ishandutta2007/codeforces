#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,x[N],s[N],f[N],g[N],l[N];
int main()
{
	read(n);read(m);
	F(i,0,n)
	{
		read(x[i]);read(s[i]);--x[i];
		l[i]=x[i]-s[i]>0?x[i]-s[i]:0;
		g[i]=INF;
	}
	F(i,1,2*m)f[i]=INF;
	F(i,1,2*m)
	{
		F(j,0,n)if(i>x[j])
		{
			int dis=i-x[j]-1;
			if(dis>s[j])l[j]=x[j]-dis>0?x[j]-dis:0,g[j]=g[j]<f[l[j]]?g[j]:f[l[j]];
		}
		F(j,0,n)if(i-1>=l[j])g[j]=g[j]<f[i-1]?g[j]:f[i-1];
		F(j,0,n)if(i>x[j])
		{
			int dis=i-x[j]-1,tmp=0;
			if(dis<=s[j])tmp=g[j];
			else tmp=g[j]+dis-s[j];
			if(tmp<f[i])f[i]=tmp;
		}
	}
	F(i,m+1,2*m)if(f[i]<f[m])f[m]=f[i];
	printf("%d\n",f[m]);
	return 0;
}