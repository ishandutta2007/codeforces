#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,m,x,y,ans[N],size[N],dep[N],son[N],now[N],head[N],cnt,tong[N][27],sum[N];
string st;
char ch;
struct 
{
	int to,nx;
}e[N<<1];
struct sxy_no_xm
{
	int p,val;
}pp;
vector<sxy_no_xm>V[N];
void read(int &x) {
	int f = 1;
	x = 0;
	char op = getchar();
	while(((op-'0')|('9'-op))<0) { 
		if(op == '-') f = -1;
		op = getchar();
	}
	while(((op-'0')|('9'-op))>=0) {
		x = x * 10 + op - '0';
		op = getchar();
	}
	x *= f;
}
void ad(int x,int y)
{
	e[++cnt].to=y;
	e[cnt].nx=head[x];
	head[x]=cnt;
}
void dfs(int k,int fa)
{
	size[k]=1;dep[k]=dep[fa]+1;son[k]=0;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	dfs(e[i].to,k);
	  	size[k]+=size[e[i].to];
	  	if (size[e[i].to]>size[son[k]]) son[k]=e[i].to;
	  }
}
void Do(int k,int fa)
{
	tong[dep[k]][st[k]-'a']++;
	if (tong[dep[k]][st[k]-'a']%2==0) now[dep[k]]--; else now[dep[k]]++;
	if (tong[dep[k]][st[k]-'a']==1) sum[dep[k]]++;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	Do(e[i].to,k);
	  }
}
void Back(int k,int fa)
{
	tong[dep[k]][st[k]-'a']--;
	if (tong[dep[k]][st[k]-'a']%2==0) now[dep[k]]--; else now[dep[k]]++;
	if (tong[dep[k]][st[k]-'a']==0) sum[dep[k]]--;
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa)
	  {
	  	Back(e[i].to,k);
      }
}
void Work(int k,int fa)
{
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa&&e[i].to!=son[k])
	  {
	  	Work(e[i].to,k);
	  	Back(e[i].to,k);
	  }
	if (son[k]) Work(son[k],k);
	tong[dep[k]][st[k]-'a']++;
	if (tong[dep[k]][st[k]-'a']%2==0) now[dep[k]]--; else now[dep[k]]++;
	if (tong[dep[k]][st[k]-'a']==1) sum[dep[k]]++;
	
	for (int i=head[k];i;i=e[i].nx)
	  if (e[i].to!=fa&&e[i].to!=son[k])
	  {
	  	Do(e[i].to,k);
	  }
	for (int i=0;i<V[k].size();i++)
	{
		//ans[V[k][i].p]=now[dep[k]+V[k][i].val-1];
		ans[V[k][i].p]=(now[V[k][i].val]<=1);
	}
}
signed main()
{
	read(n);read(m);
	for (int i=2;i<=n;i++)
	{
		read(x);
		ad(x,i);
	}
	cin>>st;st=' '+st;
	for (int i=1;i<=m;i++)
	{
		read(x);read(y);
		pp.p=i;pp.val=y;
		V[x].push_back(pp);
	}
	dfs(1,0);
	Work(1,0);
	for (int i=1;i<=m;i++)
	{
		if (ans[i]) cout<<"Yes"<<endl; else cout<<"No"<<endl;
	}
}