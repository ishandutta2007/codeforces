#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("NO"),0;
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
struct part
{
	int l,r,p,id;
	bool operator<(part b)const{return l<b.l;}
}a[N];
struct actor
{
	int l,r,k,real,fake;
	bool operator<(actor b)const{return l<b.l;}
}b[N];
int n,m,m2,real[N],r[N],ans[N];
long long c[131077];
bool cmpa(part a,part b){return a.r<b.r;}
bool cmp(actor a,actor b){return a.r<b.r;}
void add(int x,int y)
{
	for(++x;x<=m2;x+=(x&-x))c[x]+=y;
}
long long sum(int x)
{
	long long ans=0;
	for(;x;x-=(x&-x))ans+=c[x];
	return ans;
}
int next(int x)
{
	int i=0;
	long long k=sum(x);
	if(k>=sum(m2))return -1;
	for(int j=m2>>1;j;j>>=1)if(k>=c[i+j])k-=c[i+=j];
	return i;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i].l),read(a[i].r),a[i].id=i;
	read(m);
	m2=1;while(m2<m)m2<<=1;
	F(i,0,m)read(b[i].l),read(b[i].r),read(b[i].k),b[i].real=i;
	sort(a,a+n,cmpa);sort(b,b+m,cmp);
	F(i,0,m)b[i].fake=i,real[i]=b[i].real,r[i]=b[i].r;
	for(int i=0,j=0;i<n;++i)
	{
		while(j<m&&r[j]<a[i].r)++j;
		a[i].p=j;
	}
	sort(a,a+n);sort(b,b+m);
	for(int i=0,j=0;i<n;++i)
	{
		int k;
		while(j<m&&b[j].l<=a[i].l){add(b[j].fake,b[j].k);++j;}
		k=next(a[i].p);
		if(k==-1)fail;
		ans[a[i].id]=real[k];
		add(k,-1);
	}
	puts("YES");
	F(i,0,n)printf("%d ",ans[i]+1);
	return 0;
}