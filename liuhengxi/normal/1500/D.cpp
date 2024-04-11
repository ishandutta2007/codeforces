#include<cstdio>
#include<cstring>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1505,INF=0x3fffffff;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,q,c[N][N],a[N][N],s[N],o[N*N],tm;
int x[N][N][12][2],y[2][12][2],z[N][N][12][2];
constexpr int& len(int r[12][2]){return r[11][0];}
int main()
{
	read(n,q);
	F(i,0,n)F(j,0,n)--read(c[i][j]);
	++q;
	for(int i=n;~--i;)for(int j=n;~--j;++s[a[i][j]])
	{
		x[i][j][0][0]=c[i][j];x[i][j][0][1]=0;++len(x[i][j]);
		memset(y[0],0,24*sizeof(int));
		y[0][0][0]=c[i][j];y[0][0][1]=0;++len(y[0]);
		z[i][j][0][0]=c[i][j];z[i][j][0][1]=0;++len(z[i][j]);
		if(i!=n-1)
		{
			o[c[i][j]]=++tm;
			int *top=x[i][j][1],&le=len(x[i][j]);
			F(k,0,len(x[i+1][j]))
			{
				if(o[x[i+1][j][k][0]]==tm)continue;
				o[top[0]=x[i+1][j][k][0]]=tm;
				top[1]=x[i+1][j][k][1]+1;
				top+=2;
				if(++le==q)break;
			}
		}
		if(j!=n-1)
		{
			o[c[i][j]]=++tm;
			int *top=y[0][1],&le=len(y[0]);
			F(k,0,len(y[1]))
			{
				if(o[y[1][k][0]]==tm)continue;
				o[top[0]=y[1][k][0]]=tm;
				top[1]=y[1][k][1]+1;
				top+=2;
				if(++le==q)break;
			}
		}
		if(i!=n-1&&j!=n-1)
		{
			o[c[i][j]]=++tm;
			int *top=z[i][j][1],&le=len(z[i][j]);
			auto uu=x[i+1][j],vv=y[1],ww=z[i+1][j+1];
			int ul=len(uu),vl=len(vv),wl=len(ww);
			for(int u=0,v=0,w=0;;)
			{
				int cc=-1,mn=INF;
				while(u!=ul&&o[uu[u][0]]==tm)++u;
				while(v!=vl&&o[vv[v][0]]==tm)++v;
				while(w!=wl&&o[ww[w][0]]==tm)++w;
				if(u!=ul&&uu[u][1]<mn)mn=uu[u][1],cc=uu[u][0];
				if(v!=vl&&vv[v][1]<mn)mn=vv[v][1],cc=vv[v][0];
				if(w!=wl&&ww[w][1]<mn)mn=ww[w][1],cc=ww[w][0];
				if(!~cc)break;
				o[top[0]=cc]=tm;
				top[1]=mn+1;
				top+=2;
				if(u!=ul&&uu[u][1]==mn)mn=-1,++u;
				if(v!=vl&&vv[v][1]==mn)mn=-1,++v;
				if(w!=wl&&ww[w][1]==mn)mn=-1,++w;
				if(++le==q)break;
			}
		}
		else memcpy(z[i][j],i!=n-1?x[i][j]:y[0],24*sizeof(int));
		a[i][j]=min(n-i,n-j);
		if(len(z[i][j])==q)a[i][j]=min(a[i][j],z[i][j][q-1][1]);
		memcpy(y[1],y[0],24*sizeof(int));
	}
	for(int i=n;i;--i)s[i-1]+=s[i];
	F(i,1,n+1)printf("%d\n",s[i]);
	return 0;
}