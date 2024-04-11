#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace mf
{
	const int N=1e5+5,M=1e5+5,inf=0x3f3f3f3f3f3f3f3f;
	int n,s,t,tot=2;
	int v[M],w[M],first[N],next[M];
	int iter[N],level[N];
	inline void add_edge(int x,int y,int f)
	{
		v[tot+1]=x;v[tot]=y;w[tot]=f;w[tot+1]=0;
		next[tot]=first[x];first[x]=tot;
		next[tot+1]=first[y];first[y]=tot+1;
		tot+=2;
		return;
	}
	queue<int> Q;
	inline bool bfs()
	{
		int x;
		register int i;
		memset(level+1,0x3f,sizeof(int)*n);
		level[s]=0;Q.push(s);
		while(!Q.empty())
		{
			x=Q.front();Q.pop();
			for(i=first[x];i;i=next[i])
				if(w[i]&&level[v[i]]==inf)
					level[v[i]]=level[x]+1,Q.push(v[i]);
		}
		return level[t]<inf;
	}
	int dfs(int x,int f)
	{
		if(x==t)
			return f;
		int tot=0,d;
		for(int &i=iter[x];i;i=next[i])
			if(w[i]&&level[v[i]]==level[x]+1)
				if(d=dfs(v[i],min(f-tot,w[i])))
				{
					w[i]-=d;w[i^1]+=d;
					if((tot+=d)==f)
						break;
				}
		return tot;
	}
	inline int run()
	{
		int res=0;
		while(bfs())
			memcpy(iter+1,first+1,sizeof(int)*n),res+=dfs(s,inf);
		return res;
	}
}
const int N=1005;
int n,m;
int xl[N],xr[N],yl[N],yr[N];
vector<int> Vx,Vy;
signed main()
{
	register int i,j;
	ios::sync_with_stdio(0);
	cin>>n>>m;
	Vx.push_back(n);Vx.push_back(0);
	Vy.push_back(n);Vy.push_back(0);
	for(i=1;i<=m;i++)
	{
		cin>>xl[i]>>yl[i]>>xr[i]>>yr[i];
		Vx.push_back(xr[i]);Vx.push_back(xl[i]-1);
		Vy.push_back(yr[i]);Vy.push_back(yl[i]-1);
	}
	sort(Vx.begin(),Vx.end());
	Vx.erase(unique(Vx.begin(),Vx.end()),Vx.end());
	sort(Vy.begin(),Vy.end());
	Vy.erase(unique(Vy.begin(),Vy.end()),Vy.end());
	mf::n=(int)(Vx.size()-1)+(int)(Vy.size()-1)+m+2;
	mf::s=(int)(Vx.size()-1)+(int)(Vy.size()-1)+m+1;
	mf::t=(int)(Vx.size()-1)+(int)(Vy.size()-1)+m+2;
	for(i=1;i<(int)Vx.size();i++)
		mf::add_edge(mf::s,i,Vx[i]-Vx[i-1]);
	for(i=1;i<(int)Vy.size();i++)
		mf::add_edge((int)(Vx.size()-1)+i,mf::t,Vy[i]-Vy[i-1]);
	for(i=1;i<=m;i++)
	{
		xl[i]=lower_bound(Vx.begin(),Vx.end(),xl[i]-1)-Vx.begin()+1;
		xr[i]=lower_bound(Vx.begin(),Vx.end(),xr[i])-Vx.begin();
		yl[i]=lower_bound(Vy.begin(),Vy.end(),yl[i]-1)-Vy.begin()+1;
		yr[i]=lower_bound(Vy.begin(),Vy.end(),yr[i])-Vy.begin();
		for(j=xl[i];j<=xr[i];j++)
			mf::add_edge(j,(int)(Vx.size()-1)+(int)(Vy.size()-1)+i,mf::inf);
		for(j=yl[i];j<=yr[i];j++)
			mf::add_edge((int)(Vx.size()-1)+(int)(Vy.size()-1)+i,(int)(Vx.size()-1)+j,mf::inf);
	}
	cout<<mf::run()<<endl;
	return 0;
}