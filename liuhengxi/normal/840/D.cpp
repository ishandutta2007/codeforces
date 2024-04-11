#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,m,a[N],b,bl[N],mid,r,ans[N];
struct query
{
	int l,r,k,id;
	bool operator<(query b)const{return bl[l]!=bl[b.l]?bl[l]<bl[b.l]:r<b.r;}
}q[N];
struct cnt
{
	int c[N],a[5],oa[5],sta[N],top;
	void record(){top=0;oa[0]=a[0];oa[1]=a[1];oa[2]=a[2];oa[3]=a[3];oa[4]=a[4];}
	void add(int x)
	{
		++c[sta[top++]=x];
		if(x==a[0])a[0]=a[1],a[1]=a[2],a[2]=a[3],a[3]=a[4],a[4]=n;
		else if(x==a[1])a[1]=a[2],a[2]=a[3],a[3]=a[4],a[4]=n;
		else if(x==a[2])a[2]=a[3],a[3]=a[4],a[4]=n;
		else if(x==a[3])a[3]=a[4],a[4]=n;
		else if(x==a[4])a[4]=n;
		if(c[x]>c[a[0]])a[4]=a[3],a[3]=a[2],a[2]=a[1],a[1]=a[0],a[0]=x;
		else if(c[x]>c[a[1]])a[4]=a[3],a[3]=a[2],a[2]=a[1],a[1]=x;
		else if(c[x]>c[a[2]])a[4]=a[3],a[3]=a[2],a[2]=x;
		else if(c[x]>c[a[3]])a[4]=a[3],a[3]=x;
		else if(c[x]>c[a[4]])a[4]=x;
	}
	void restore()
	{
		while(top)--c[sta[--top]];
		a[0]=oa[0];a[1]=oa[1];a[2]=oa[2];a[3]=oa[3];a[4]=oa[4];
	}
	void clear(){F(i,0,n)c[i]=0;}
}c/*normal*/,d/*brute force*/;
int get(const cnt &c,int lim)
{
	int ans=-1;
	if(c.c[c.a[0]]>lim)
	{
		if(!~ans||ans>c.a[0])ans=c.a[0];
		if(c.c[c.a[1]]>lim)
		{
			if(!~ans||ans>c.a[1])ans=c.a[1];
			if(c.c[c.a[2]]>lim)
			{
				if(!~ans||ans>c.a[2])ans=c.a[2];
				if(c.c[c.a[3]]>lim)
				{
					if(!~ans||ans>c.a[3])ans=c.a[3];
					if(c.c[c.a[4]]>lim)
					{
						if(!~ans||ans>c.a[4])ans=c.a[4];
					}
				}
			}
		}
	}
	return ans;
}
int main()
{
	read(n);read(m);
	F(i,0,n)read(a[i]),--a[i];
	while(b*b<n)++b;
	F(i,0,n+1)bl[i]=i/b;
	F(i,0,m)read(q[i].l),--q[i].l,read(q[i].r),read(q[i].k),q[i].id=i;
	sort(q,q+m);
	d.record();
	F(i,0,m)
	{
		int lim=(q[i].r-q[i].l)/q[i].k;
		if(bl[q[i].l]==bl[q[i].r])
		{
			F(j,q[i].l,q[i].r)d.add(a[j]);
			ans[q[i].id]=get(d,lim);
			d.restore();
		}
		else
		{
			int tmp=(bl[q[i].l]+1)*b;
			if(mid!=tmp)
			{
				c.clear();
				r=mid=tmp;
			}
			while(r<q[i].r)c.add(a[r++]);
			c.record();
			F(j,q[i].l,mid)c.add(a[j]);
			ans[q[i].id]=get(c,lim);
			c.restore();
		}
	}
	F(i,0,m)printf("%d\n",~ans[i]?ans[i]+1:-1);
	return 0;
}