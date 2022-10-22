#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define lc ((p<<1)+1)
#define rc ((p<<1)+2)
using namespace std;
const int N=1e5+5;
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
	int pn,plen[22],pval[22],sn,slen[22],sval[22];
	long long sum;
}seg[N<<2];
int n,m,x,a[N];
long long calc(int a,int al,int b,int bl)
{
	long long ans=0;
	int j=seg[b].pn-1;
	F(i,0,seg[a].sn)
	{
		int tmp;
		if(seg[a].slen[i]>al)break;
		if(i!=seg[a].sn-1)tmp=seg[a].slen[i+1]-1<al?seg[a].slen[i+1]-1:al;
		else tmp=al;
		tmp-=seg[a].slen[i]-1;
		while(j&&(seg[b].pval[j-1]|seg[a].sval[i])>=x)--j;
		if((seg[b].pval[j]|seg[a].sval[i])>=x&&seg[b].plen[j]<=bl)
			ans+=(long long)tmp*(bl-seg[b].plen[j]+1);
	}
	return ans;
}
void pushup(int p,int l,int r)
{
	int mid=(l+r)>>1;
	seg[p].pn=seg[lc].pn;
	F(i,0,seg[lc].pn)
	{
		seg[p].plen[i]=seg[lc].plen[i];
		seg[p].pval[i]=seg[lc].pval[i];
	}
	F(i,0,seg[rc].pn)
	{
		if((seg[p].pval[seg[p].pn-1]&seg[rc].pval[i])!=seg[rc].pval[i])
		{
			seg[p].pval[seg[p].pn]=seg[p].pval[seg[p].pn-1]|seg[rc].pval[i];
			seg[p].plen[seg[p].pn++]=seg[rc].plen[i]+mid-l;
		}
	}
	seg[p].sn=seg[rc].sn;
	F(i,0,seg[rc].sn)
	{
		seg[p].slen[i]=seg[rc].slen[i];
		seg[p].sval[i]=seg[rc].sval[i];
	}
	F(i,0,seg[lc].sn)
	{
		if((seg[p].sval[seg[p].sn-1]&seg[lc].sval[i])!=seg[lc].sval[i])
		{
			seg[p].sval[seg[p].sn]=seg[p].sval[seg[p].sn-1]|seg[lc].sval[i];
			seg[p].slen[seg[p].sn++]=seg[lc].slen[i]+r-mid;
		}
	}
	seg[p].sum=seg[lc].sum+seg[rc].sum;
	seg[p].sum+=calc(lc,mid-l,rc,r-mid);
}
void build(int p,int l,int r)
{
	int mid=(l+r)>>1;
	if(r-l==1)
	{
		seg[p].plen[0]=seg[p].pn=1;
		seg[p].slen[0]=seg[p].sn=1;
		seg[p].pval[0]=seg[p].sval[0]=a[l];
		if(a[l]>=x)seg[p].sum=1;
		return;
	}
	build(lc,l,mid);build(rc,mid,r);
	pushup(p,l,r);
}
void update(int p,int l,int r,int i,int y)
{
	int mid=(l+r)>>1;
	if(r-l==1)
	{
		seg[p].plen[0]=seg[p].pn=1;
		seg[p].slen[0]=seg[p].sn=1;
		seg[p].pval[0]=seg[p].sval[0]=y;
		seg[p].sum=(int)(y>=x);
		return;
	}
	if(i<mid)update(lc,l,mid,i,y);
	else update(rc,mid,r,i,y);
	pushup(p,l,r);
}
long long query(int p,int l,int r,int x,int y)
{
	int mid=(l+r)>>1;
	long long ans=0;
	if(y<=l||r<=x)return 0;
	if(x<=l&&r<=y)return seg[p].sum;
	ans+=query(lc,l,mid,x,y);
	ans+=query(rc,mid,r,x,y);
	if(x<mid&&mid<y)ans+=calc(lc,mid-(x>l?x:l),rc,(y<r?y:r)-mid);
	return ans;
}
int main()
{
	read(n);read(m);read(x);
	F(i,0,n)read(a[i]);
	build(0,0,n);
	while(m--)
	{
		int op;read(op);
		if(op==1)
		{
			int i,y;read(i);read(y);
			update(0,0,n,--i,y);
		}
		else
		{
			int l,r;read(l);read(r);
			printf("%lld\n",query(0,0,n,--l,r));
		}
	}
	return 0;
}