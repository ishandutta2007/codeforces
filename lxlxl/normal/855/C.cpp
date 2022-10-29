#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;
const ll Mod = 1e9+7;

int n,m,K,X;
struct edge
{
	int y,nex;
	edge(){}
	edge(const int _y,const int _nex){y=_y;nex=_nex;}
}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=edge(y,fir[x]);fir[x]=len;}

ll f[maxn][15][4];
ll g[15][4];
void dfs(const int x,const int fa)
{
	f[x][0][0]=K-1; f[x][1][1]=1; f[x][0][2]=m-K;
	for(int k=fir[x];k;k=a[k].nex)
	{
		const int y=a[k].y;
		if(y!=fa) 
		{
			dfs(y,x);
			for(int i=0;i<=X;i++) for(int j=0;j<3;j++) g[i][j]=0;
			for(int i=0;i<=X;i++) for(int j=0;j<3;j++) if(f[x][i][j])
			{
				ll tmp1=f[x][i][j];
				for(int ti=0;ti<=X-i;ti++) for(int tj=0;tj<3;tj++) if(f[y][ti][tj])
				{
					ll tmp2=f[y][ti][tj];
					if(j==1)
					{
						if(tj==0) g[i+ti][j]+=tmp1*tmp2%Mod;
					}
					else if(tj==1)
					{
						if(j==0) g[i+ti][j]+=tmp1*tmp2%Mod;
					}
					else g[i+ti][j]+=tmp1*tmp2%Mod;
				}
			}
			for(int i=0;i<=X;i++) for(int j=0;j<3;j++) f[x][i][j]=g[i][j]%Mod;
		}
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)
	{
		int x,y; scanf("%d%d",&x,&y);
		ins(x,y); ins(y,x);
	}
	scanf("%d%d",&K,&X);
	dfs(1,0);
	
	ll re=0;
	for(int i=0;i<=X;i++) for(int j=0;j<3;j++) re+=f[1][i][j];
	re%=Mod; if(re<0) re+=Mod;
	printf("%I64d\n",re);
	
    return 0;
}