#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1005;
int tt,n,k,lim,c[N][N];
void add(int x,int y,int z)
{
	for(++y;y<=n;y+=y&-y)c[x][y]+=z;
}
int sum(int x,int y)
{
	int ans=0;
	for(;y;y-=y&-y)ans+=c[x][y];
	return ans;
}
char s[N][N],ans[N][N];
void dfs(int u,int v)
{
	if(ans[u][v]=='0')
	{
		ans[u][v]='1';
		if(s[u][v]=='0')add(u,v,-1);
	}
	if(u==n-1&&v==0)return;
	if(v==0)return dfs(u+1,v);
	if(u==n-1)return dfs(u,v-1);
	if(sum(u,v))return dfs(u,v-1);
	if(u>=n-lim)return dfs(u,v-1);
	dfs(u+1,v);
}
int main()
{
	read(tt);
	while(tt--)
	{
		read(n,k);
		F(i,0,n)scanf("%s",s[i]);
		F(i,0,n)F(j,0,n+1)c[i][j]=0;
		F(i,0,n)F(j,0,n)ans[i][j]='0';
		F(i,0,n)F(j,0,n)if(s[i][j]=='0')add(i,j,1);
		--k;
		lim=k;
		F(i,0,k)dfs(0,n-k+i),--lim;
		bool ok=true;
		F(i,0,n)F(j,0,n)ok=ok&&(s[i][j]=='1'||ans[i][j]=='1');
		if(ok)
		{
			puts("Yes");
			F(i,0,n)
			{
				ans[i][n]='\0';
				puts(ans[i]);
			}
		}
		else puts("No");
	}
	return 0;
}