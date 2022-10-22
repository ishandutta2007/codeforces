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
struct query
{
	int l,r,id;
	bool operator<(query b)const{return r<b.r;}
}q[N];
int n,m,a[N],c[N],maxdelta,ans[N];
inline void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
inline int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
inline int find(int x)
{
	int l=0,now=0;
	for(int delta=maxdelta;delta;delta>>=1)if(l+delta<=n)
		if(now+c[l+delta]>=x)now+=c[l+=delta];
	return l;
}
int main()
{
	int r=0;
	read(n);read(m);
	for(maxdelta=1;maxdelta<n;maxdelta<<=1);
	F(i,0,n)
	{
		read(a[i]);
		a[i]=i-a[i]+1;
		if(a[i]<0)a[i]=i+1;
	}
	F(i,0,m)read(q[q[i].id=i].l),read(q[i].r),q[i].r=n-q[i].r;
	sort(q,q+m);
	add(0,-1);
	F(i,0,m)
	{
		while(r<q[i].r)
		{
			add(r,1);
			add(r+1,-1);
			add(find(a[r]),-1);
			add(0,1);
			++r;
		}
		ans[q[i].id]=sum(q[i].l+1);
	}
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}