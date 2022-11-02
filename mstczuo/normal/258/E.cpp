# include <iostream>
# include <cstdio>
# include <vector>
#define fe(i,n) for(__typeof(n.begin())i=n.begin();i!=n.end();i++)
using namespace std;
const int N=100010;
struct Node{
	int l,r,w,s;
}t[N<<2];

vector<int>a[N],c[N];
int p[N],q[N],L[N],R[N],s[N],z[N];
int cnt,n,m,x,y;

void update(int x)
{
	if(t[x].w)
		t[x].s=t[x].r-t[x].l+1;
	else if(t[x].r!=t[x].l)
		t[x].s=t[x<<1].s+t[x<<1|1].s;
	else t[x].s=0;
}
void build(int x,int l,int r)
{
	t[x].l=l,t[x].r=r;
	if(l==r)return;
	int m=(l+r)>>1;
	build(x<<1,l,m);
	build(x<<1|1,m+1,r);
	update(x);
}
void change(int x,int l,int r,int d)
{
	if(t[x].l>r||t[x].r<l)return ;
	else
		if(l<=t[x].l&&t[x].r<=r)t[x].w+=d;
	else
		change(x<<1,l,r,d),change(x<<1|1,l,r,d);
	update(x);
}
void dfs(int x,int y)
{
	L[x]=++cnt;
	fe(i,a[x])if(*i!=y)dfs(*i,x);
	R[x]=cnt;
}
inline void tcg(int k,int d){change(1,L[k],R[k],d);}
void DFS(int x,int y)
{
	fe(i,c[x])tcg(p[*i],1),tcg(q[*i],1);
	z[x]=t[1].s;
	fe(i,a[x])if(*i!=y)DFS(*i,x);
	fe(i,c[x])tcg(p[*i],-1),tcg(q[*i],-1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++){
		scanf("%d%d",&x,&y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1,0);
	build(1,1,n);
	for(int i=0;i<m;i++){
		scanf("%d%d",p+i,q+i);
		c[p[i]].push_back(i);
		c[q[i]].push_back(i);
	}
	DFS(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",max(z[i]-1,0));
	return 0;
}