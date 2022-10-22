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
int cmpcmpcmp=0;
struct sss
{
	int v,p;
}s[N];
int n,a[N],b[N],x,c[N+1];
long long ans=0;
bool cmp(sss a,sss b)
{
	int c,d;
	if(~cmpcmpcmp)
	{
		c=a.v>>cmpcmpcmp,d=b.v>>cmpcmpcmp;
		return c<d;
	}
	c=a.v,d=b.v;
	return c!=d?c<d:a.p<b.p;
}
int lowbit(int x){return x&-x;}
void add(int x,int y)
{
	for(x=n-x;x<=n;x+=lowbit(x))c[x]+=y;
}
int sum(int x)
{
	int ans=0;
	for(x=n-x;x;x-=lowbit(x))ans+=c[x];
	return ans;
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]);
	F(i,0,n)s[s[i].p=i].v=a[i];
	F(iii,0,31)
	{
		long long a=0,b=0;
		sort(s,s+n,cmp);
		for(int i=0,j=0,k=0;i<n;i=k)
		{
			while(j<n&&!cmp(s[i],s[j]))++j;
			++cmpcmpcmp;
			while(k<n&&!cmp(s[i],s[k]))++k;
			--cmpcmpcmp;
			F(l,i,j)add(s[l].p,1);
			F(l,j,k)a+=sum(s[l].p);
			F(l,i,j)add(s[l].p,-1);
			F(l,j,k)add(s[l].p,1);
			F(l,i,j)b+=sum(s[l].p);
			F(l,j,k)add(s[l].p,-1);
		}
		if(a>b)x^=1<<iii;
		++cmpcmpcmp;
	}
	F(i,0,n)b[i]=a[i]^x;
	F(i,0,n)s[s[i].p=i].v=b[i];
	cmpcmpcmp=-1;
	sort(s,s+n,cmp);
	F(i,0,n)
	{
		ans+=sum(s[i].p);
		add(s[i].p,1);
	}
	printf("%lld %d\n",ans,x);
	return 0;
}