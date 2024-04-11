#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=2e5+5,S=54,P[S]={100000007,100000037,100000039,100000049,100000073,100000081,100000123,100000127,100000193,100000213,100000217,100000223,100000231,100000237,100000259,100000267,100000279,100000357,100000379,100000393,100000399,100000421,100000429,100000463,100000469,100000471,100000493,100000541,100000543,100000561,100000567,100000577,100000609,100000627,100000643,100000651,100000661,100000669,100000673,100000687,100000717,100000721,100000793,100000799,100000801,100000837,100000841,100000853,100000891,100000921,100000937,100000939,100000963,100000969};
template<typename T>void read(T &x)
{
    bool neg=false;
    unsigned char c=getchar();
    for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
    for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
    if(neg)x=-x;
}
struct line
{
    int u,v,w;
    bool operator<(line b)const{return w<b.w;}
}e[M];
int n,m,k,f[N][S],out[N],cnt[N],val[9][9][S],now[S],c[S],ans;
void dfs(int p)
{
	if(p==k)
	{
		F(j,0,S)if(c[j]!=now[j])return;
		++ans;
		return;
	}
	F(i,0,p+1)
	{
		F(j,0,S)(now[j]+=val[p][i][j])%=P[j];
		dfs(p+1);
		F(j,0,S)(now[j]+=P[j]-val[p][i][j])%=P[j];
	}
}
int main()
{
    read(n);read(m);read(k);
    F(i,0,m)
    {
    	read(e[i].u);read(e[i].v);read(e[i].w);
		++out[--e[i].u];--e[i].v;
    }
    sort(e,e+m);
    srand(time(NULL)^clock()^3727327);
	F(i,0,n)F(j,0,S)(c[j]+=f[i][j]=rand()%P[j])%=P[j];
    F(i,0,m)
    {
    	const int &u=e[i].u,&v=e[i].v;
		F(j,0,S)val[out[u]-1][cnt[u]][j]=(val[out[u]-1][cnt[u]][j]+f[v][j])%P[j];
    	++cnt[u];
    }
	dfs(0);
	printf("%d\n",ans);
    return 0;
}