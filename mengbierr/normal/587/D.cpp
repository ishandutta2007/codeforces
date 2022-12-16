#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
const int N=1e6+5,M=1e7+5;
struct E{int to,next;};
struct TwoSAT
{
	E edge[M];
	bool mark[N];
	int n,head[N],tot,stk[N],top;
	inline void init(int n)
	{
		this->n=n;tot=0;
		memset(head,-1,sizeof(head));
		memset(mark,0,sizeof(mark));
	}
	bool dfs(int x)
	{
		if(mark[x^1])return false;
		if(mark[x])return true;
		mark[x]=true;
		stk[++top]=x;
		for(int i=head[x];i!=-1;i=edge[i].next)if(!dfs(edge[i].to))return false;
		return true;
	}
	inline void add(int x,int xval,int y,int yval)
	{
		//printf("%d %d %d %d\n",x,xval,y,yval);
		x=x*2+xval;y=y*2+yval;
		edge[++tot]=(E){y,head[x^1]};head[x^1]=tot;
		edge[++tot]=(E){x,head[y^1]};head[y^1]=tot;
	}
	inline bool solve()
	{
		for(int i=0;i<2*n;i+=2)if(!mark[i]&&!mark[i^1])
		{
			top=0;
			if(!dfs(i))
			{
				while(top)mark[stk[top--]]=false;
				if(!dfs(i+1))return false;
			}
		}
		return true;
	}
}solver;
int n,m,u[N],v[N],c[N],t[N],a[N],num[N];
vector<int> vec[N],link[N];
map<int,int> mp;
inline bool check(int x)
{
	bool flag=true;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<link[i].size();j++)if(t[link[i][j]]>x)
		{
			num[c[link[i][j]]]++;
			if(num[c[link[i][j]]]>1)flag=false;
		}
		for(int j=0;j<link[i].size();j++)if(t[link[i][j]]>x)num[c[link[i][j]]]--;
	}
	if(!flag)return false;
	solver.init(3*m);
	int now=0;
	vector<int> tmp;tmp.clear();
	for(int i=1;i<=n;i++)
	{
		int sz=(int)link[i].size(),flag=0,pos=-1;
		//if(i==2)for(int j=0;j<sz;j++)printf("%d %d\n",link[i][j],c[link[i][j]]);
		for(int j=1;j<sz;j++)if(c[link[i][j]]==c[link[i][j-1]])
		{
			if(t[link[i][j]]<=x&&t[link[i][j-1]]<=x)solver.add(link[i][j]-1,1,link[i][j-1]-1,1);
			else if(t[link[i][j]]<=x)flag=1,pos=j;else flag=1,pos=j-1;
		}
		//if(i==2)printf("%d %d\n",flag,link[i][pos]);
		//for(int j=1;j<sz;j++)if(t[link[i][j]]<=x&&t[link[i][j-1]]<=x&&c[link[i][j]]==c[link[i][j-1]])solver.add(link[i][j]-1,1,link[i][j-1]-1,1);
		if(flag)tmp.push_back(link[i][pos]);
		for(int j=0;j<sz;j++)if(t[link[i][j]]<=x)solver.add(link[i][j]-1,0,now+m+j,1);
		for(int j=1;j<sz;j++)solver.add(now+m+j-1,0,now+m+j,1);
		for(int j=0;j<sz-1;j++)if(t[link[i][j+1]]<=x)solver.add(now+m+j,0,link[i][j+1]-1,0);
		now+=sz;
	}
	for(int i=0;i<tmp.size();i++)if(!solver.dfs(2*(tmp[i]-1)+1))return false;
	if(solver.solve())return true;
	return false;
}
inline bool cmp(int a,int b){return c[a]<c[b];}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)scanf("%d%d%d%d",&u[i],&v[i],&c[i],&t[i]),a[i]=c[i],link[u[i]].push_back(i),link[v[i]].push_back(i);
	for(int i=1;i<=n;i++)sort(link[i].begin(),link[i].end(),cmp);
	sort(a+1,a+m+1);
	for(int i=1;i<=m;i++)mp[a[i]]=i;
	for(int i=1;i<=m;i++)c[i]=mp[c[i]],vec[c[i]].push_back(i);
	bool flag=true;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<vec[i].size();j++)
		{
			num[u[vec[i][j]]]++,num[v[vec[i][j]]]++;
			if(num[u[vec[i][j]]]>2)flag=false;
			if(num[v[vec[i][j]]]>2)flag=false;
		}
		for(int j=0;j<vec[i].size();j++)num[u[vec[i][j]]]--,num[v[vec[i][j]]]--;
	}
	if(!flag)return puts("No"),0;
	//check(3);
	//for(int i=1;i<=m;i++)printf("%d %d\n",solver.mark[2*i-2],solver.mark[2*i-1]);
	int L=0,R=1e9;
	while(L<R)
	{
		int mid=(L+R)>>1;
		if(check(mid))R=mid;
		else L=mid+1;
	}
	if(check(R))
	{
		puts("Yes");
		int cnt=0;
		for(int i=1;i<=m;i++)if(solver.mark[2*i-1])cnt++;
		printf("%d %d\n",R,cnt);
		for(int i=1;i<=m;i++)if(solver.mark[2*i-1])printf("%d ",i);
	}
	else puts("No");
	return 0;
}