#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=18;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct operation
{
	int p,v;
	bool operator<(operation b)const{return p<b.p;}
}opt[2*LogN*N];
int n,q,x[N],y[N],last[N],l[N],r[N],lc[N<<2],rc[N<<2],ind,cnt,pos[N<<2];
int f[N],a[N],top,no,siz[N],dist[N];
bool ans[N];
long long h[N];
int find(int x){return f[x]==x?x:find(f[x]);}
int getdis(int x){return f[x]==x?0:getdis(f[x])+dist[x];}
void add(int x,int y)
{
	int fx,fy;
	if(no)return ++no,void();
	fx=find(x),fy=find(y);
	if(fx==fy)
	{
		if((getdis(x)+getdis(y))%2==0)++no;
		else a[top++]=-1;
	}
	else
	{
		if(siz[fx]<siz[fy])fx^=fy^=fx^=fy,x^=y^=x^=y;
		a[top++]=fy;
		dist[fy]=(1+getdis(y))%2;
		f[fy]=x;
		siz[fx]+=siz[fy];
	}
}
void undo()
{
	if(no)return --no,void();
	if(top)
	{
		--top;
		if(~a[top])
		{
			siz[f[a[top]]]-=siz[a[top]];
			f[a[top]]=a[top];
		}
	}
}
int dis(long long x)
{
	int l=0,r=q;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		if(x<h[mid])r=mid;
		else l=mid;
	}
	return l;
}
int build(int l,int r)
{
	int p=ind++,mid=(l+r)>>1;
	lc[p]=rc[p]=-1;
	if(r-l==1)return p;
	lc[p]=build(l,mid);rc[p]=build(mid,r);
	return p;
}
void mark(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)
	{
		opt[cnt].p=p;
		opt[cnt++].v=v;
		return;
	}
	mark(lc[p],l,mid,x,y,v);
	mark(rc[p],mid,r,x,y,v);
}
void solve(int p,int l,int r)
{
	int mid=(l+r)>>1,L=pos[p],R=pos[p+1];
	F(i,L,R)add(x[opt[i].v],y[opt[i].v]);
	if(r-l==1)ans[l]=no==0;
	else solve(lc[p],l,mid),solve(rc[p],mid,r);
	F(i,L,R)undo();
}
int main()
{
	read(n);read(q);
	F(i,0,q)
	{
		read(x[i]);read(y[i]);
		h[i]=(--x[i])*n+(--y[i]);
	}
	sort(h,h+q);
	F(i,0,q)last[i]=-1,l[i]=-1,r[i]=-1;
	F(i,0,q)
	{
		int d=dis(x[i]*n+y[i]);
		if(~last[d])l[last[d]]=last[d],r[last[d]]=i,last[d]=-1;
		else last[d]=i;
	}
	F(i,0,q)if(~last[i])l[last[i]]=last[i],r[last[i]]=q;
	build(0,q);
	F(i,0,q)if(~l[i])mark(0,0,q,l[i],r[i],i);
	sort(opt,opt+cnt);
	for(int i=0,j=0;i<ind;++i)
	{
		while(j<cnt&&opt[j].p==i)++j;
		pos[i+1]=j;
	}
	F(i,0,n)f[i]=i,siz[i]=1;
	solve(0,0,q);
	F(i,0,q)puts(ans[i]?"YES":"NO");
	return 0;
}