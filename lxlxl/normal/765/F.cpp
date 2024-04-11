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
#define inf 1e9
using namespace std;

inline void down(int &a,const int &b){if(a>b)a=b;}
inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
int ch[10],chn;
inline void Output(int x)
{
	if(!x) { puts("0");return; }
	while(x) ch[++chn]=x%10,x/=10;
	while(chn) putchar('0'+ch[chn--]);
	putchar('\n');
}
const int maxn = 210000;
const int maxm = 1100000;

int n,m;
int a[maxn];
struct ct{int x;int *i;}s[maxn];
inline bool cmp(const ct x,const ct y){return x.x<y.x;}
int To[maxn],id;
void Trans()
{
	for(int i=1;i<=n;i++) s[i].x=a[i],s[i].i=&a[i];
	sort(s+1,s+n+1,cmp);
	for(int i=1,la=s[1].x-1;i<=n;la=s[i].x,i++)
	{
		if(la!=s[i].x) To[++id]=s[i].x;
		(*s[i].i)=id;
	}
}

struct segment
{
	int mx[maxn<<2];
	void init() { memset(mx,-1,sizeof mx); }
	void pushup(int x) { mx[x]=max(mx[x<<1],mx[x<<1|1]); }
	int loc,c;
	void upd(int x,const int l,const int r)
	{
		if(l==r) { mx[x]=c;return; }
		int mid=(l+r)>>1;
		if(loc<=mid) upd(x<<1,l,mid);
		else upd(x<<1|1,mid+1,r);
		pushup(x);
	}
	int lx,rx;
	int querymx(int x,const int l,const int r)
	{
		if(!x||rx<l||r<lx) return -1;
		if(lx<=l&&r<=rx) return mx[x];
		int mid=(l+r)>>1;
		return max(querymx(x<<1,l,mid),querymx(x<<1|1,mid+1,r));
	}
}seg;

struct segment2
{
	int seg[maxn<<2];
	int loc,lx,rx,c;
	void init() { memset(seg,63,sizeof seg); }
	void upd(int x,const int l,const int r)
	{
		if(rx<l||r<lx) return;
		if(lx<=l&&r<=rx) { down(seg[x],c);return; }
		int mid=l+r>>1;
		upd(x<<1,l,mid); upd(x<<1|1,mid+1,r);
	}
	int query(int x,const int l,const int r,int c)
	{
		down(c,seg[x]);
		if(l==r) return c;
		int mid=l+r>>1;
		if(loc<=mid) return query(x<<1,l,mid,c);
		else return query(x<<1|1,mid+1,r,c);
	}
}seg2;

int op[maxm],ans[maxm];
vector<int>V[maxn];

int main()
{
	read(n);
	for(int i=1;i<=n;i++) read(a[i]); Trans();
	read(m);
	for(int i=1;i<=m;i++) 
	{
		int l,r; read(l); read(r);
		op[i]=l;
		V[r].push_back(i);
	}
	
	seg.init(); seg2.init();
	for(int i=1;i<=n;i++)
	{
		int las,l,r;
		
		las=0; r=1;
		while(1)
		{
			l=r,r=a[i];
			while(l<=r)
			{
				int mid=l+r>>1;
				if(To[mid]>=las) r=mid-1;
				else l=mid+1;
			}++r;
			seg.lx=r,seg.rx=a[i];
			int k=seg.querymx(1,1,n); if(k==-1) break;
			seg2.lx=1,seg2.rx=k,seg2.c=To[a[i]]-To[a[k]]; seg2.upd(1,1,n);
			if(las==To[a[i]]) break;
			las=To[a[k]]+(To[a[i]]-To[a[k]]+1)/2;
			if(las>To[a[i]]) break;
		}
		
		las=To[id]; l=id;
		while(1)
		{
			r=l,l=a[i];
			while(l<=r)
			{
				int mid=l+r>>1;
				if(To[mid]<=las) l=mid+1;
				else r=mid-1;
			}--l;
			seg.lx=a[i],seg.rx=l;
			int k=seg.querymx(1,1,n); if(k==-1) break;
			seg2.lx=1,seg2.rx=k,seg2.c=To[a[k]]-To[a[i]]; seg2.upd(1,1,n);
			if(las==To[a[i]]) break;
			las=To[a[k]]-(To[a[k]]-To[a[i]]+1)/2;
			if(las<To[a[i]]) break;
		}
		
		seg.loc=a[i],seg.c=i; seg.upd(1,1,n);
		
		for(int j=0;j<(int)V[i].size();j++)
		{
			int ii=V[i][j];
			seg2.loc=op[ii];
			ans[ii]=seg2.query(1,1,n,inf);
		}
	}
	for(int i=1;i<=m;i++) Output(ans[i]);
	
	return 0;
}