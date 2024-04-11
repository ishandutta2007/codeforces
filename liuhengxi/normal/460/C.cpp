#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
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
int n,m,w,a[N],min=INF,max,c[2*N];
bool check(int v)
{
	int now=0;
	long long cnt=0;
	F(i,0,n)c[i]=0;
	F(i,0,n)
	{
		int k;
		now-=c[i];
		k=v-a[i]-now;
		if(k>0)
		{
			now+=k;
			cnt+=k;
			c[i+w]+=k;
		}
	}
	return cnt<=m;
}
int solve()
{
	int l=min,r=max+m+1,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))l=mid;
		else r=mid;
	}
	return l;
}
int main()
{
	read(n);read(m);read(w);
	F(i,0,n)read(a[i]);
	F(i,0,n)if(a[i]<min)min=a[i];
	F(i,0,n)if(a[i]>max)max=a[i];
	printf("%d\n",solve());
	return 0;
}