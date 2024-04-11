#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5,LogN=18,LogA=31;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,a[N],q,logn,s[2*N][LogN],v[N*LogA],c[N*LogA],id[N*LogA],t[N*LogA],cnt;
long long sum[N*LogA];
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
bool cmp(int a,int b){return v[a]<v[b];}
long long query(int x)
{
	int l=0,r=cnt+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(x<v[mid-1])r=mid;
		else l=mid;
	}
	return sum[l];
}
int main()
{
	read(n);F(i,0,n)read(a[i]);
	while((1<<logn)<=n)++logn;
	F(i,0,n)s[i][0]=a[i];
	F(i,0,logn-1)F(j,0,n)s[j][i+1]=gcd(s[j][i],s[j+(1<<i)][i]);
	F(i,0,n)
	{
		int now=a[i];
		for(int j=i,last=i;j<n;last=j)
		{
			for(int k=logn-1;~k&&j<n;--k)if(s[j][k]%now==0)j+=1<<k;
			if(j>n)j=n;
			v[cnt]=now;c[id[cnt]=cnt]=j-last;++cnt;
			now=gcd(now,a[j]);
		}
	}
	sort(id,id+cnt,cmp);
	F(i,0,cnt)t[i]=v[id[i]];F(i,0,cnt)v[i]=t[i];
	F(i,0,cnt)t[i]=c[id[i]];F(i,0,cnt)c[i]=t[i];
	F(i,0,cnt)sum[i+1]=sum[i]+c[i];
	read(q);
	while(q--)
	{
		int x;read(x);
		printf("%lld\n",query(x)-query(x-1));
	}
	return 0;
}