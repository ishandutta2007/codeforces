#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
int t,x,q,k,p[9],s[200],lg[200],pop[200],c/*c<=7*/;
int calc(int a)//sigma [x<=a][gcd(x,p)==1]
{
	long long tot=0;
	F(i,0,1<<c)tot+=(1-2*(pop[i]&1))*(a/s[i]);
	return (int)tot;
}
int solve()
{
	int l=-1,r=10000000,mid;
	while(r-l>1)
	{
		mid=(l+r)>>1;
		if(calc(mid)<k)l=mid;
		else r=mid;
	}
	return r;
}
int main()
{
	read(t);
	F(i,1,8)lg[1<<i]=i;
	F(i,1,128)pop[i]=pop[i^(i&-i)]+1;
	while(t--)
	{
		read(x);read(q);read(k);
		c=0;
		for(int i=2;i*i<=q;++i)if(q%i==0)
		{
			p[c++]=i;while(q%i==0)q/=i;
		}
		if(q!=1)p[c++]=q,q=1;
		s[0]=1;
		F(i,1,1<<c)s[i]=s[i^(i&-i)]*p[lg[i&-i]];
		k+=calc(x);
		printf("%d\n",solve());
	}
	return 0;
}