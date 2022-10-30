#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;
const int maxp = maxn*30;

int n,m;
char str[maxn],sq[maxn];

struct SAM
{
	int root,last,tot;
	int son[maxn][26],par[maxn],c[maxn];
	void init()
	{
		root=last=tot=1;
	}
	int newnode(int l)
	{
		c[++tot]=l;
		memset(son[tot],0,sizeof son[tot]);
		par[tot]=0;
		return tot;
	}
	void extend(const int w)
	{
		int p=last,np=newnode(c[p]+1);
		while(!son[p][w]&&p) son[p][w]=np,p=par[p];
		if(p)
		{
			int q=son[p][w];
			if(c[q]==c[p]+1) par[np]=q;
			else
			{
				int nq=newnode(c[p]+1);
				memcpy(son[nq],son[q],sizeof son[nq]);
				par[nq]=par[q];
				par[q]=par[np]=nq;
				while(p&&son[p][w]==q) son[p][w]=nq,p=par[p];
			}
		}
		else par[np]=root;
		last=np;
	}
}sam;

int t[maxn],tp;
struct Segment
{
	int cnt;
	int seg[maxp],lc[maxp],rc[maxp];
	int loc;
	int newnode() 
	{
		++cnt;
		seg[cnt]=lc[cnt]=rc[cnt]=0;
		return cnt;
	}
	void upd(int &x,const int l,const int r)
	{
		seg[x=newnode()]=1;
		if(l==r) return;
		int mid=l+r>>1;
		if(loc<=mid) upd(lc[x],l,mid);
		else upd(rc[x],mid+1,r);
	}
	void merge(int &x,const int y)
	{
		if(!y) return;
		if(!x) { x=y;return; }
		int k=x;
		x=newnode();
		seg[x]=seg[k]+seg[y];
		lc[x]=lc[k],rc[x]=rc[k];
		merge(lc[x],lc[y]);
		merge(rc[x],rc[y]);
	}
	void query(int x,const int l,const int r)
	{
		if(!x) return;
		if(l==r) { t[++tp]=l;return; }
		int mid=l+r>>1;
		query(lc[x],l,mid); query(rc[x],mid+1,r);
	}
}seg; int root[maxn];

vector<int>V[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	scanf("%s",str+1); n=strlen(str+1);
	sam.init();
	for(int i=1;i<=n;i++) 
	{
		sam.extend(str[i]-'a');
		seg.loc=i; seg.upd(root[sam.last],1,n);
	}
	for(int i=1;i<=sam.tot;i++) V[sam.c[i]].push_back(i);
	for(int i=n;i>=1;i--)
	{
		for(int j=0;j<(int)V[i].size();j++)
		{
			int x=V[i][j]; if(sam.par[x])
			{
				int ff=sam.par[x];
				seg.merge(root[ff],root[x]);
			}
		}
	}
	
	scanf("%d",&m);
	while(m--)
	{
		int ki; scanf("%d",&ki);
		scanf("%s",sq+1); int len=strlen(sq+1);
		int x=sam.root;
		for(int j=1;j<=len;j++)
		{
			int w=sq[j]-'a';
			x=sam.son[x][w];
		}
		if(!x||seg.seg[root[x]]<ki) { puts("-1");continue; }
		
		tp=0; seg.query(root[x],1,n);
		int ans=n;
		for(int i=ki;i<=tp;i++) ans=min(ans,t[i]-t[i-ki+1]+1);
		printf("%d\n",ans+len-1);
	}
	
	return 0;
}