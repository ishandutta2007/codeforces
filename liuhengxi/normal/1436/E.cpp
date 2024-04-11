#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define mid ((l+r)>>1)
using namespace std;
const int N=1e5+5,INF=0x3fffffff;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct node
{
	int val,pos;
	bool operator<(node b){return val!=b.val?val<b.val:pos<b.pos;}
}s[N];
int n,a[N],rt[N],b[N+1],ans;
int cnt,val[N<<5],lc[N<<5],rc[N<<5];
int build(int l,int r)
{
	int p=cnt++;
	val[p]=-1;
	if(r-l>1)
	{
		lc[p]=build(l,mid);
		rc[p]=build(mid,r);
	}
	return p;
}
int update(int p,int l,int r,int x,int v)
{
	int q=cnt++;
	lc[q]=lc[p];rc[q]=rc[p];
	if(r-l>1)
	{
		if(x<mid)lc[q]=update(lc[p],l,mid,x,v);
		else rc[q]=update(rc[p],mid,r,x,v);
		val[q]=val[lc[q]]<val[rc[q]]?val[lc[q]]:val[rc[q]];
	}
	else val[q]=v;
	return q;
}
int query(int p,int l,int r,int x,int y)
{
	int a,b;
	if(y<=l||r<=x)return INF;
	if(x<=l&&r<=y)return val[p];
	a=query(lc[p],l,mid,x,y);
	b=query(rc[p],mid,r,x,y);
	return a<b?a:b;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),s[i].val=--a[i],s[i].pos=i;
	sort(s,s+n);
	rt[0]=update(build(0,n),0,n,a[0],0);
	F(i,1,n)rt[i]=update(rt[i-1],0,n,a[i],i);
	F(i,0,n)if(a[i])b[0]=1;
	for(int i=0,l=0,r=0;i<=n;++i,l=r)
	{
		int last=-1;
		while(r<n&&i==s[r].val)++r;
		if(i==0)continue;
		F(j,l,r)
		{
			if(query(rt[s[j].pos],0,n,0,i)>last)b[i]=1;
			last=s[j].pos;
		}
		if(query(rt[n-1],0,n,0,i)>last)b[i]=1;
		last=n-1;
	}
	while(b[ans])++ans;
	printf("%d\n",ans+1);
	return 0;
}