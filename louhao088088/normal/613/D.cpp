#include<bits/stdc++.h>
using namespace std;
static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define re register
const int maxn=2e5+5;
#define int long long
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,m,d[maxn],f[maxn][21],x,y,z,dfn[maxn],idx=0,a[maxn],st[maxn],top,minv[maxn],head[maxn],cnt;
bool flag[maxn],ff[maxn];
struct node{int v,nex;}e2[maxn];
vector<int>e[maxn];
void add(int x,int y){e2[++cnt].v=y,e2[cnt].nex=head[x];head[x]=cnt;}
void dfs(int x,int fa)
{
	d[x]=d[fa]+1;f[x][0]=fa;dfn[x]=++idx;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(auto i:e[x])
	{
		if(i==fa)continue;
		dfs(i,x);
	}
}
int Lca(int x,int y)
{
	if(d[x]<d[y])swap(x,y);
	for(int i=20;i>=0;i--)if(d[f[x][i]]>=d[y])x=f[x][i];
//	cout<<x<<" "<<y<<endl;
	if(x==y)return x;
	for(int i=20;i>=0;i--)if(f[x][i]!=f[y][i])x=f[x][i],y=f[y][i];
	return f[x][0];
}
bool cmp(int x,int y){return dfn[x]<dfn[y];}
void ins(int x)
{
	if(top==0){st[top=1]=x;return;}
	int lca=Lca(st[top],x);//cout<<x<<" "<<lca<<' '<<st[top]<<endl;
	while(top>1&&d[lca]<d[st[top-1]])
		add(st[top-1],st[top]),--top;
	if(d[lca]<d[st[top]])add(lca,st[top--]);
	if((!top)||(st[top]!=lca))st[++top]=lca;st[++top]=x;
}
int dfs1(int x) 
{
	int sum=0,num=0;
	if(!flag[x])
	{
		for(int i=head[x];i;i=e2[i].nex)
		{
			sum+=dfs1(e2[i].v);
			if(ff[e2[i].v])ff[e2[i].v]=0,num++;
		}ff[x]=0;if(num==1)ff[x]=1;else if(num!=0)sum++;
	}	
	else if(flag[x])
	{
		for(int i=head[x];i;i=e2[i].nex)
		{
			sum+=dfs1(e2[i].v);
			if(ff[e2[i].v])sum++,ff[e2[i].v]=0;
			//cout<<e2[i].v<<" "<<ff[e2[i].v]<<endl;
		}
		ff[x]=1;//cout<<x<<" "<<ff[x]<<" "<<endl;		
	}
	//cout<<sum<<" "<<x<<endl;
	head[x]=0;flag[x]=0;return sum;
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	memset(minv,0x3f,sizeof minv);
	n=read();
	for(int i=1;i<n;i++)
		x=read(),y=read(),e[x].push_back(y),e[y].push_back(x);
	dfs(1,0);//cout<<Lca(1,2)<<endl;
	m=read();
	while(m--)
	{
		x=read();top=0;int F=0;
		for(int i=1;i<=x;i++)
		{
			a[i]=read(),flag[a[i]]=1;
		}
		for(int i=1;i<=x;i++)	
		{
			if(flag[f[a[i]][0]])
			{
				puts("-1");F=1;//cout<<a[i]<<" "<<f[a[i]][0]<<endl;
				for(int j=1;j<=x;j++)flag[a[j]]=0;break;
			}
		}if(F)continue;
		sort(a+1,a+x+1,cmp);
		for(int i=1;i<=x;i++)ins(a[i]);
		while(--top)add(st[top],st[top+1]);
		printf("%lld\n",dfs1(st[1]));cnt=0;ff[st[1]]=0;
	}
	return 0;
}