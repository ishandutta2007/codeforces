#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int n,p[N],a[3*N],k;
long long ans,pos,neg,poscnt,negcnt;
int main()
{
	read(n);
	F(i,0,n)read(p[i]),++a[(p[i]-=i+1)+n];
	F(i,0,n)if(p[i]>=0)pos+=p[i],++poscnt;else neg-=p[i],++negcnt;
	ans=pos+neg;
	k=0;
	F(i,0,n-1)
	{
		int j=(n-1-i)%n;
		--a[p[j]+n];
		if(p[j]>=i)pos-=p[j]-i,--poscnt;else neg+=p[j]-i,--negcnt;
		if(p[j]+n>=i)pos+=p[j]+n-i,++poscnt;else neg-=p[j]+n-i,++negcnt;
		++a[p[j]+n+n];
		poscnt-=a[i+n];negcnt+=a[i+n];
		pos-=poscnt;neg+=negcnt;
		if(pos+neg<ans)ans=pos+neg,k=i+1;
	}
	printf("%lld %d\n",ans,k);
	return 0;
}