#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e5+5;
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
int phi(int x)
{
	int ans=x;
	for(int i=2;i*i<=x;++i)if(x%i==0)
	{
		while(x%i==0)x/=i;
		ans-=ans/i;
	}
	if(x!=1)ans-=ans/x;
	return ans;
}
int pow(int aa,int b,int p)
{
	long long a=aa,c=1;
	for(;b;b>>=1,(a*=a),(a>=p&&(a%=p,a+=p)))if(b&1)(c*=a),(c>=p&&(c%=p,c+=p));
	return (int)c;
}
int n,m[80],a[N],k,q;
int main()
{
	read(n,m[0]);
	F(i,0,n)read(a[i]);
	while(m[k]!=1)m[k+1]=phi(m[k]),++k;
	read(q);
	while(q--)
	{
		int l,r,x=1;read(l,r);--l;if(r>l+k)r=l+k;
		for(int i=r;--i>=l;)x=pow(a[i],x,m[i-l]);
		printf("%d\n",x%m[0]);
	}
	return 0;
}