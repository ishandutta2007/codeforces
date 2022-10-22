#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=105;
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
int tt,n,f[N][N],u[N],v[N],e,ffa[N],q[N],qf,qr,dc[N],mxd,dep[N];
vector<int> adj[N];
char str[N];
bool s[N][N][N],in[N];
int find(int x,int y){return f[x][y]==y?y:f[x][y]=find(x,f[x][y]);}
void dfs(int x,int fa)
{
	if(dep[x]>mxd)mxd=dep[x];
	for(int y:adj[x])if(y!=fa)dep[y]=dep[x]+1,dfs(y,x);
}
int main()
{
	read(tt);
	while(tt--)
	{
		bool bad=false;
		read(n);
		F(i,0,n)F(j,i+1,n)
		{
			scanf("%s",str);
			F(k,0,n)s[k][j][i]=s[k][i][j]=str[k]-'0';
		}
		F(i,0,n)F(k,0,n)s[k][i][i]=true;
		F(i,0,n)
		{
			F(j,0,n)f[i][j]=j;
			F(j,0,n)F(k,0,j)if(s[i][j][k])f[i][find(i,j)]=find(i,k);
			F(j,0,n)F(k,0,n)if(!s[i][j][k]&&find(i,j)==find(i,k))bad=true;
			dc[i]=0;
			F(j,0,n)if(find(i,j)==j)++dc[i];
		}
		F(i,0,n)F(j,0,n)if(i!=j&&s[i][i][j])bad=true;
		if(bad){puts("No");continue;}
		F(i,1,n)if(find(0,i)==i)
		{
			bad=true;
			F(j,0,n)in[j]=false;
			in[0]=true;
			qf=qr=0;
			e=1;u[0]=0;ffa[v[0]=i]=0;in[q[qr++]=i]=true;
			F(j,i+1,n)if(s[0][i][j])ffa[v[e]=j]=u[e]=0,++e,in[q[qr++]=j]=true;
			while(qf<qr)
			{
				int x=q[qf++];
				F(y,0,n)if(!in[y]&&s[x][ffa[x]][y])ffa[q[qr++]=y]=u[e]=x,in[v[e++]=y]=true;
			}
			if(e!=n-1)continue;
			F(j,0,e)
			{
				adj[u[j]].emplace_back(v[j]);
				adj[v[j]].emplace_back(u[j]);
			}
			bad=false;
			F(j,0,n)
			{
				dep[j]=1;mxd=0;
				dfs(j,j);
				if(mxd!=dc[j]&&(bad=true))break;
				F(k,0,n)if(dep[find(j,k)]!=dep[k])bad=true;
				if(bad)break;
			}
			F(j,0,n)adj[j].clear();
			if(!bad)
			{
				puts("Yes");
				F(j,0,e)printf("%d %d\n",u[j]+1,v[j]+1);
				break;
			}
		}
		if(bad)puts("No");
	}
	return 0;
}