#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define Rep(i,x) for(int i=head[x];i+1;i=nxt[i])
#define rep2(i,a,b) for(int i=(a);i<(b);i++)
#define ff first
#define ss second
using namespace std;
const int N=100005;
const int inf=1e9+7;
typedef long long ll;
struct node
{
	int id;
	int type;
	int x,y;
	int k;
}q[N*10],tmp[N*10];
int cur,n;
ll ans[N];
ll c[N];
int tag[N],xjt;
inline int lowbit(int x){return x&(-x);}
inline void modify(int x,int y)
{
	while(x)
	{
		if(tag[x]!=cur){tag[x]=cur;c[x]=0;}
		c[x]+=y;
		x-=lowbit(x);
	}return ;
}
inline ll query(int x)
{
	ll res=0;
	while(x<=n)
	{
		if(tag[x]!=cur){tag[x]=cur;c[x]=0;}
		res+=c[x];
		x+=lowbit(x);
	}return res;
}
void solve(int l,int r)
{
	if(l==r)return;
	int mid=(l+r)>>1;solve(l,mid);solve(mid+1,r);
	++cur;int l1=l,r1=mid+1;
	rep(i,l,r)
	{
		if((l1>mid)||(r1<=r && q[r1].y<q[l1].y))
		{
			tmp[i]=q[r1++];
			if(tmp[i].type==1)
			{
				ans[tmp[i].id]+=query(tmp[i].x);
			}
		}
		else
		{
			tmp[i]=q[l1++];
			if(!tmp[i].type) modify(tmp[i].x,tmp[i].k);
		}
	}
	rep(i,l,r)q[i]=tmp[i];
	return;
}
int a[N],pre[N],la[N];
set<int> s[N];
int chk[N];
void New_node(int x,int y,int z)
{
	++xjt;q[xjt].x=x;q[xjt].y=y;
	q[xjt].k=z;q[xjt].type=0;
}
void Modify(int x,int y)
{
	int c1=a[x];
	set<int>::iterator it=s[a[x]].find(x);
	int p1=-1,n1=-1;
	if(it!=s[a[x]].begin())
	{
		it--;p1=*it;
		it++;New_node(p1,x,p1-x);
	}
	if(it!=s[a[x]].end())
	{
		it++;
		if(it!=s[a[x]].end())
		{
			n1=*it;
			New_node(x,n1,x-n1);
		}it--;
		if(n1!=-1 && p1!=-1) New_node(p1,n1,n1-p1);
	}
	s[a[x]].erase(x);
	
	a[x]=y;s[a[x]].insert(x);p1=-1,n1=-1;
	it=s[a[x]].find(x);
	if(it!=s[a[x]].begin())
	{
		it--;p1=*it;
		it++;New_node(p1,x,x-p1);
	}it++;
	if(it!=s[a[x]].end())
	{
		n1=*it;
		New_node(x,n1,n1-x);
	}it--;
	if(n1!=-1 && p1!=-1) New_node(p1,n1,p1-n1);
}
int main()
{
	int m;scanf("%d%d",&n,&m);
	rep(i,1,n)
	{
		scanf("%d",&a[i]);
		pre[i]=la[a[i]];la[a[i]]=i;if(pre[i])New_node(pre[i],i,i-pre[i]);
		s[a[i]].insert(i);
	}
	rep(i,1,m)
	{
		int type,x,y;scanf("%d%d%d",&type,&x,&y);
		if(type==1) Modify(x,y);
		else
		{
			chk[i]=1;
			xjt++;q[xjt].x=x;q[xjt].y=y;q[xjt].id=i;q[xjt].type=1;
		}
	}
	solve(1,xjt);
	rep(i,1,m)if(chk[i])printf("%lld\n",ans[i]);
	return 0;
	
}