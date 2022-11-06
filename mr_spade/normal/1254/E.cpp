#include<cstdio>
#include<cstdlib>
#include<vector>
using std::vector;
const int mod=1e9+7;
inline int add(int a,int b)
{
	return (a+=b)>=mod?a-mod:a;
}
inline int sub(int a,int b)
{
	return (a-=b)<0?a+mod:a;
}
inline int mul(int a,int b)
{
	return (long long)a*b%mod;
}
inline int qpow(int a,int b)
{
	int res=1;
	for(;b;a=mul(a,a),b>>=1)
		if(b&1)
			res=mul(res,a);
	return res;
}
const int N=5e5+5;
int n,ans=1;
int a[N];
vector<int> e[N],f1[N],f2[N];
int deep[N],p[N][25];
int id[N],od[N];
int dis[N],size[N];
int up[N],down[N],fi[N],la[N];
void dfs(int x,int father)
{
	register int i;
	p[x][0]=father;deep[x]=deep[father]+1;
	for(i=1;p[x][i-1];i++)
		p[x][i]=p[p[x][i-1]][i-1];
	for(int y:e[x])
		if(y!=father)
			dfs(y,x);
	return;
}
int dx,dy;
inline int lca(int x,int y)
{
	register int i;
	for(i=22;i>=0;i--)
		if(deep[p[x][i]]>=deep[y])
			x=p[x][i];
	for(i=22;i>=0;i--)
		if(deep[p[y][i]]>=deep[x])
			y=p[y][i];
	if(x==y)
		return dx=dy=0,x;
	for(i=22;i>=0;i--)
		if(p[x][i]!=p[y][i])
			x=p[x][i],y=p[y][i];
	dx=x;dy=y;return p[x][0];
}
inline int anc(int x,int k)
{
	register int i;
	for(i=22;i>=0;i--)
		if(k>>i&1)
			x=p[x][i];
	return x;
}
inline int find(int x)
{
	return dis[x]==x?x:(dis[x]=find(dis[x]));
}
inline void add_edge(int x,int y,int &d)
{
	if(find(x)==find(y))
		puts("0"),exit(0);
	int fx=find(x),fy=find(y);
	dis[fx]=fy;size[fy]+=size[fx];
	od[x]++;id[y]++;d--;
	return;
}
void dfs2(int x,int father)
{
	int d=(int)e[x].size();
	int uu=0,dd=0,uux=0,ddx=0;
	register int i;
	for(int y:e[x])
		if(y!=father)
		{
			dfs2(y,x);
			if(up[y])
			{
				uu+=up[y];uux=y;
			}
			if(down[y])
			{
				dd+=down[y];ddx=y;
			}
		}
	if(uu>1||dd>1)
		puts("0"),exit(0);
	for(int y:e[x])
		dis[y]=y,size[y]=1,id[y]=od[y]=0;
	if(uux)
		add_edge(uux,father,d);
	if(ddx)
		add_edge(father,ddx,d);
	for(i=0;i<(int)f1[x].size();i++)
		add_edge(f1[x][i],f2[x][i],d);
	for(int y:e[x])
		if(id[y]>=2||od[y]>=2)
			puts("0"),exit(0);
	if(fi[x]&&id[fi[x]])
		puts("0"),exit(0);
	if(la[x]&&od[la[x]])
		puts("0"),exit(0);
	if(fi[x])
		d--;
	if(la[x])
		d--;
	if(fi[x]&&la[x]&&find(fi[x])==find(la[x])&&size[find(fi[x])]<(int)e[x].size())
		puts("0"),exit(0);
	for(i=1;i<=d;i++)
		ans=mul(ans,i);
	up[x]+=uu;down[x]+=dd;
	return;
}
signed main()
{
	int x,y,z;
	register int i;
	scanf("%d",&n);
	for(i=1;i<=n-1;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);e[y].push_back(x);
	}
	dfs(1,0);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		if(a[i]==i)
			return puts("0"),0;
		if(a[i])
		{
			z=lca(a[i],i);
			if(dx==0)
			{
				if(deep[a[i]]<deep[i])
				{
					x=p[i][0];
					y=anc(i,deep[i]-deep[a[i]]-1);
					la[i]=x;fi[a[i]]=y;
					down[i]++,down[y]--;
				}
				else
				{
					x=anc(a[i],deep[a[i]]-deep[i]-1);
					y=p[a[i]][0];
					la[i]=x;fi[a[i]]=y;
					up[a[i]]++,up[x]--;
				}
			}
			else
			{
				up[a[i]]++;up[dx]--;
				down[i]++;down[dy]--;
				la[i]=p[i][0];fi[a[i]]=p[a[i]][0];
				f1[z].push_back(dx);
				f2[z].push_back(dy);
			}
		}
	}
	dfs2(1,0);
	printf("%d\n",ans);
	return 0;
}