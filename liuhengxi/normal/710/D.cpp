#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(long long i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
long long a1,b1,a2,b2,l,r;
long long ans;
long long d(long long a,long long b){return (a-(a%b+b)%b)/b;}
int main()
{
	read(a1,b1,a2,b2,l,r);l=max(l,max(b1,b2));
	if(l>r)return puts("0"),0;
	b1=(b1%a1+a1)%a1;
	b2=(b2%a2+a2)%a2;
	if(a1<a2)swap(a1,a2),swap(b1,b2);
	if(a1<=1000)
	{
		long long c=a1*a2;
		--l;
		l+=c;r+=c;
		F(i,0,a1*a2)if(i%a1==b1&&i%a2==b2)ans+=d(r-i,c)-d(l-i,c);
	}
	else
	{
		long long i=d(l,a1)*a1+b1;
		++r;
		if(i<l)i+=a1;
		for(;i<r;i+=a1)if((i%a2+a2)%a2==b2)++ans;
	}
	printf("%lld\n",ans);
	return 0;
}