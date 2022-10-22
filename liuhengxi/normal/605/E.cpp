#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e3+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n;
double p[N][N],dis[N],prob[N]/*no path*/;
bool vis[N];
inline double rdis(int u){return dis[u]/(1.0-prob[u])+prob[u]/(1.0-prob[u]);}
int main()
{
	read(n);
	F(i,0,n)F(j,0,n)
	{
		int a;read(a);
		p[j][i]=a/100.0;
	}
	F(i,0,n-1)dis[i]=1e-300;
	F(i,0,n-1)prob[i]=1.0;
	F(k,0,n)
	{
		int u=-1;
		F(i,0,n)if(!vis[i]&&(!~u||rdis(i)<rdis(u)))u=i;
		dis[u]=rdis(u);
		vis[u]=true;
		F(v,0,n)if(!vis[v])
		{
			dis[v]+=prob[v]*p[u][v]*(dis[u]+1);
			prob[v]*=(1.0-p[u][v]);
		}
	}
	printf("%.10lf\n",dis[0]);
	return 0;
}