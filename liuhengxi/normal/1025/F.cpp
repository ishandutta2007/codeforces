#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
		return y*(long long)b.x<b.y*(long long)x;
	}
}s[N*N/2];
struct point
{
	int x,y;
	slope operator-(point b){return slope(x-b.x,y-b.y);}
}p[N];
int n,m,id[N],rnk[N];
long long ans;
bool cmp(int a,int b){return p[a].x!=p[b].x?p[a].x<p[b].x:p[a].y>p[b].y;}
int main()
{
	read(n);
	F(i,0,n)read(p[i].x),read(p[i].y),id[i]=i;
	F(i,0,n)F(j,i+1,n)(s[m]=p[j]-p[i]).pos(),s[m].v=j,s[m].u=i,++m;
	sort(s,s+m);
	sort(id,id+n,cmp);
	F(i,0,n)rnk[id[i]]=i;
	F(i,0,m)// <2*10^6
	{
		int u=s[i].u,v=s[i].v,left=min(rnk[u],rnk[v]),right=n-max(rnk[u],rnk[v])-1;
		swap(id[rnk[u]],id[rnk[v]]);swap(rnk[u],rnk[v]);
		ans+=left*(left-1ll)*right*(right-1ll);// <10^12
	}
	ans>>=2;
	printf("%lld\n",ans);
	return 0;
}