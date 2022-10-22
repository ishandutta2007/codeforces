#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=20,MOD=1000000007;
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
int n,m,k,t,a[N][N],c[N][N],ans,fac[N];
bool b[N];
void dfs(int x,int y)
{
	if(y==m)++x,y=0;
	if(x==n)return ans+=fac[t],(ans>=MOD)&&(ans-=MOD),void();
	if(n+m-x-y>k-__builtin_popcount((x?c[x-1][y]:0)|(y?c[x][y-1]:0))+1)return;
	if(~a[x][y])c[x][y]=(x?c[x-1][y]:0)|(y?c[x][y-1]:0),(!(c[x][y]>>a[x][y]&1))&&(c[x][y]|=1<<a[x][y])&&(dfs(x,y+1),1);
	else
	{
		F(i,0,t)
		{
			a[x][y]=i;
			c[x][y]=(x?c[x-1][y]:0)|(y?c[x][y-1]:0);
			(!(c[x][y]>>a[x][y]&1))&&(c[x][y]|=1<<a[x][y])&&(dfs(x,y+1),1);
		}
		if(t<k)
		{
			a[x][y]=t++;
			c[x][y]=(x?c[x-1][y]:0)|(y?c[x][y-1]:0);
			(!(c[x][y]>>a[x][y]&1))&&(c[x][y]|=1<<a[x][y])&&(dfs(x,y+1),1);
			--t;
		}
		a[x][y]=-1;
	}
}
int main()
{
	read(n,m,k);
	if(n+m>k+1)return puts("0"),0;
	F(i,0,n)F(j,0,m)if(~--read(a[i][j]))b[a[i][j]]=true;
	F(i,0,k)if(b[i])++t;
	F(i,0,n)F(j,0,m)if(~a[i][j])
	{
		int p=0;
		F(q,0,a[i][j])if(b[q])++p;
		a[i][j]=p;
	}
	F(j,t,k+1)F(i,k-j+(fac[j]=1),k-t+1)fac[j]=(int)(fac[j]*(long long)i%MOD);
	dfs(0,0);
	printf("%d\n",ans);
	return 0;
}