#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=5005;
const long long LLINF=0x3fffffffffffffffll;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T min(T x,T y){return x<y?x:y;}
struct line
{
	int next,to;
}e[N];
int n,b,c[N],d[N],hd[N],cnt,s[N],ans;
long long f[N][N][2],t[N][2];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u)
{
	s[u]=1;
	f[u][1][1]=c[u]-d[u];
	f[u][1][0]=c[u];
	f[u][0][0]=0;
	for(int ii=hd[u];~ii;ii=e[ii].next)
	{
		int v=e[ii].to;
		dfs(v);
		F(i,0,s[u]+s[v]+1)t[i][0]=t[i][1]=LLINF;
		F(i,0,s[u]+1)F(j,0,s[v]+1)
		{
			t[i+j][0]=min(t[i+j][0],f[u][i][0]+f[v][j][0]);
			t[i+j][1]=min(t[i+j][1],f[u][i][1]+min(f[v][j][0],f[v][j][1]));
		}
		F(i,0,(s[u]+=s[v])+1)f[u][i][0]=t[i][0],f[u][i][1]=t[i][1];
	}
}
int main()
{
	read(n);read(b);
	F(i,0,n)
	{
		int x;
		hd[i]=-1;
		read(c[i]);read(d[i]);
		if(i)
		{
			read(x);--x;
			adline(x,i);
		}
	}
	F(i,0,n)F(j,0,n+2)f[i][j][0]=f[i][j][1]=LLINF;
	dfs(0);
	while(min(f[0][ans+1][0],f[0][ans+1][1])<=b)++ans;
	printf("%d\n",ans);
	return 0;
}