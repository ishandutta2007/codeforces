#include<cstdio>
#include<algorithm>
#include<functional>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5,M=5e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,k,a[N],c[M];
long long sum=1;
bool check(int v)
{
	long long ans=1,now=1;
	F(i,0,v)c[i]=0;
	c[0]=1;c[1]=-1;
	for(int i=0,j=0;i<n;++i)
	{
		int x=a[i]>>1,y=(a[i]-1)>>1;
		while(j<v&&!c[j])++j;
		if(j==v)break;
		x=min(j+x+2,v);y=min(j+y+2,v);
		--c[j];++c[j+1];c[j+2]+=2;--c[x];--c[y];
		now+=x-j+y-j-5;
		ans=max(ans,now);
	}
	return ans>=k;
}
int solve()
{
	int l=0,r=5e5+2,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid;
	}
	return r;
}
int main()
{
	read(n,k);
	F(i,0,n)read(a[i]),sum+=a[i]-2;
	sort(a,a+n,greater<int>());
	if(sum<k)return puts("-1"),0;
	printf("%d\n",solve()-1);
	return 0;
}