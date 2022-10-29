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

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline void up(int &x,const int &y){if(x<y)x=y;}
const int maxn = 310000;
const int maxm = 310000;

int n,m,C;
struct cloud
{
	int l,r,c;
}s[maxn];
inline bool cmpc(const cloud x,const cloud y){return x.c<y.c;}
struct Query
{
	int i,need;
}q[maxn];
inline bool cmpq(const Query x,const Query y){return x.need<y.need;}
struct node
{
	int p,v,i;
	node(){}
	node(const int _p,const int _v,const int _i){p=_p;v=_v;i=_i;}
}a[maxn<<1]; int tot;
inline bool cmpn(const node x,const node y){return x.p<y.p;}
int seg[maxn*40],single[maxn];
int loc;
void upd(const int x,const int l,const int r)
{
	if(l==r) { seg[x]=single[l]; return; }
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	if(loc<=mid) upd(lc,l,mid);
	else upd(rc,mid+1,r);
	seg[x]=max(seg[lc],seg[rc]);
}
int lx,rx;
int search(const int x,const int l,const int r)
{
	if(l==r) return l;
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	if(seg[lc]>seg[rc]) return search(lc,l,mid);
	else return search(rc,mid+1,r);
}
int query(const int x,const int l,const int r)
{
	if(rx<l||r<lx) return 0;
	if(lx<=l&&r<=rx) return search(x,l,r);
	int mid=l+r>>1,lc=x<<1,rc=lc|1;
	int t1=query(lc,l,mid),t2=query(rc,mid+1,r);
	return single[t1]>single[t2]?t1:t2;
}
map<int,int>cross[maxn];
set<int>S; int sn;
set<int>::iterator it;

int opt[maxn],Free,Top;

int sum(int x,int y)
{
	if(x>y) swap(x,y);
	return single[x]+single[y]+cross[x][y];
}
int ans[maxm];
void solve()
{
	S.insert(0);
	Free=Top=0;
	int now=0,pos=1;
	for(int i=1;i<=tot;i++)
	{
		int delta=a[i].p-now; now=a[i].p;
		if(!sn) Free+=delta;
		else if(sn==1)
		{
			it=S.upper_bound(0); int x=(*it);
			single[x]+=delta; loc=x; upd(1,1,n);
			opt[x]+=delta;
			
			int oth=C-s[x].c;
			if(oth>=0)
			{
				int u=single[x];
				if(oth>=s[1].c)
				{
					int l=1,r=n;
					while(l<=r)
					{
						int mid=l+r>>1;
						if(s[mid].c<=oth) l=mid+1;
						else r=mid-1;
					}lx=1,rx=l-1;
					if(x==rx) rx--;
					if(x<rx) { lx=x+1; if(lx<=rx) up(u,sum(x,query(1,1,n))); lx=1,rx=x-1; }
					if(lx<=rx) up(u,sum(x,query(1,1,n))); 
				}
				up(opt[x],u);
				up(Top,opt[x]);
			}
		}
		else if(sn==2)
		{
			it=S.upper_bound(0); int x=(*it); 
			it++; int y=(*it);
			if(cross[x].count(y)>0) cross[x][y]+=delta;
			else cross[x][y]=delta;
			if(s[x].c+s[y].c<=C)
			{
				up(opt[x],sum(x,y)); up(opt[y],sum(x,y));
				up(Top,opt[x]);
			}
		}
		while(pos<=m&&Top+Free>=q[pos].need) ans[q[pos].i]=now-(Top+Free-q[pos].need),pos++;
		if(pos>m) break;
		
		if(a[i].v==1) S.insert(a[i].i),sn++;
		else S.erase(a[i].i),sn--;
	}
}

int main()
{
	read(n); read(C);
	for(int i=1;i<=n;i++)
	{
		read(s[i].l); read(s[i].r); read(s[i].c);
	}sort(s+1,s+n+1,cmpc);
	for(int i=1;i<=n;i++)
	{
		a[++tot]=node(s[i].l,1,i);
		a[++tot]=node(s[i].r,-1,i);
	}sort(a+1,a+tot+1,cmpn);
	a[++tot]=node(2e9+10,1,n+1);
	
	read(m);
	for(int i=1;i<=m;i++)
	{
		q[i].i=i; read(q[i].need);
	}sort(q+1,q+m+1,cmpq);
	
	solve();
	for(int i=1;i<=m;i++) printf("%d\n",ans[i]);
	
	return 0;
}