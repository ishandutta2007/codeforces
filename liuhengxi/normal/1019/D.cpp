#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
typedef long long ll;
const int N=2005;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct slope
{
	int x,y,u,v;
	void pos(){if(x<0)x=-x,y=-y;}
	slope(int a=0,int b=0){x=a,y=b;}
	bool operator<(slope b)const
	{
		if(b.x==0)return false;
		if(x==0)return true;
		return y*(ll)b.x<b.y*(ll)x;
	}
}s[N*N/2];
struct point
{
	int x,y;
	slope operator-(point b){return slope(x-b.x,y-b.y);}
}p[N];
int n,m,id[N],rnk[N];
ll a;
bool cmp(int a,int b){return p[a].x!=p[b].x?p[a].x<p[b].x:p[a].y>p[b].y;}
inline ll cross(point a,point b){return a.x*(ll)b.y-a.y*(ll)b.x;}
inline ll area(point a,point b,point c)
{
	ll ans=cross(a,b)+cross(b,c)+cross(c,a);
	return ans>0?ans:-ans;
}
bool find(int l,int r,point u,point v)
{
	int mid;ll tmp;
	static int cnt=0;
	++cnt;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		tmp=area(p[id[mid]],u,v);
		if(cnt&1?tmp<a:tmp>a)r=mid;
		else l=mid;
	}
	if(area(p[l=id[l]],u,v)==a)
	{
		puts("Yes");
		printf("%d %d\n",p[l].x,p[l].y);
		printf("%d %d\n",u.x,u.y);
		printf("%d %d\n",v.x,v.y);
		return true;
	}
	return false;
}
int main()
{
	read(n);read(a);a*=2;
	F(i,0,n)read(p[i].x),read(p[i].y),id[i]=i;
	F(i,0,n)F(j,i+1,n)(s[m]=p[j]-p[i]).pos(),s[m].v=j,s[m].u=i,++m;
	sort(s,s+m);
	sort(id,id+n,cmp);
	F(i,0,n)rnk[id[i]]=i;
	F(i,0,m)
	{
		int u=s[i].u,v=s[i].v;
		swap(id[rnk[u]],id[rnk[v]]);swap(rnk[u],rnk[v]);
		if(find(0,min(rnk[u],rnk[v]),p[u],p[v]))return 0;
		if(find(max(rnk[u],rnk[v])+1,n,p[u],p[v]))return 0;
	}
	puts("No");
	return 0;
}