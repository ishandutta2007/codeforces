#include<cstdio>
#include<vector>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc (p<<1)
#define rc (p<<1|1)
using namespace std;
const int N=6e5+5,M=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
struct position
{
	int x,y;
	friend bool operator<(position a,position b){return ((long long)a.x<<20|a.y)<((long long)b.x<<20|b.y);}
};
int n,n2,k,m,id[M],last[M],c[N],ans[M];
void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
int sum(int x){int a=0;for(;x;x-=x&-x)a+=c[x];return a;}
int binary(int x){int a=0;for(int d=n2;d;d>>=1)if(a+d<=n&&c[a+d]<=x)x-=c[a+=d];return a;}
vector<int> d[M<<2];
void update(int p,int l,int r,int x,int y,int v)
{
	int mid=(l+r)>>1;
	if(y<=l||r<=x)return;
	if(x<=l&&r<=y)return d[p].push_back(v);
	update(lc,l,mid,x,y,v);update(rc,mid,r,x,y,v);
}
void dfs(int p,int l,int r,int mx)
{
	int mid=(l+r)>>1;
	for(int &i:d[p])
	{
		i=binary(sum(i));
		add(i,-1);
		mx=max(mx,i);
	}
	if(r-l==1)ans[l]=mx;
	else dfs(lc,l,mid,mx),dfs(rc,mid,r,mx);
	for(int i:d[p])add(i,1);
}
position a[M],v[M];
int main()
{
	int n_;
	read(n,k,m);--k;n_=n;n<<=1;n+=m;for(n2=1;(n2<<1)<n;n2<<=1);
	F(i,1,n+1)c[i]=i&-i;
	F(i,0,m)
	{
		--read(a[i].x);--read(a[i].y);
		v[i]=a[i];
	}
	sort(v,v+m);
	F(i,0,m)id[i]=int(lower_bound(v,v+m,a[i])-v);
	F(i,0,m)last[i]=-1;
	F(i,0,m)last[id[i]]=~last[id[i]]?update(1,0,m,last[id[i]],i,a[i].y+abs(a[i].x-k)),-1:i;
	F(i,0,m)if(~last[i])update(1,0,m,last[i],m,v[i].y+abs(v[i].x-k));
	dfs(1,0,m,0);
	F(i,0,m)printf("%d\n",max(ans[i]-n_+1,0));
	return 0;
}