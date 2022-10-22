#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define min(l,r) ((l^x)&((r-1)^x))
#define max(l,r) ((l^x)|((r-1)^x))
using namespace std;
const int N=3e6+5,M=1<<27;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int q,s[N],lc[N],rc[N],cnt=1;
void update(int p,int l,int r,int x,int v)
{
	int mid=(l+r)>>1;
	s[p]+=v;
	if(r-l==1)return;
	if(x<mid)
	{
		if(!lc[p])lc[p]=cnt++;
		update(lc[p],l,mid,x,v);
	}
	else
	{
		if(!rc[p])rc[p]=cnt++;
		update(rc[p],mid,r,x,v);
	}
}
int query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1,ans=0;
	if(max(l,r)<y)return s[p];
	if(min(l,mid)<y&&lc[p])ans+=query(lc[p],l,mid,x,y);
	if(min(mid,r)<y&&rc[p])ans+=query(rc[p],mid,r,x,y);
	return ans;
}
int main()
{
	read(q);
	while(q--)
	{
		int op,p,l;read(op);read(p);
		if(op==1)update(0,0,M,p,1);
		if(op==2)update(0,0,M,p,-1);
		if(op==3)read(l),printf("%d\n",query(0,0,M,p,l));
	}
	return 0;
}