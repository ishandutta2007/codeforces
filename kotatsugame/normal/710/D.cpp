#line 1 "a.cpp"
#include<iostream>
#include<algorithm>
using namespace std;
#line 1 "/home/kotatsugame/library/math/extgcd.cpp"
template<typename T>
T extgcd(T a,T b,T&x,T&y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a;
	}
	T q=a/b;
	T g=extgcd(b,a-q*b,y,x);
	y-=q*x;
	return g;
}
#line 5 "a.cpp"
long long a1,b1,a2,b2;
long long f(long long N)
{
	long long x,y;
	long long g=extgcd(a1,a2,x,y);
	if((b2-b1)%g!=0)return 0;
	long long d=(b2-b1)/g;
	cerr<<a1<<"*"<<x<<"+"<<a2<<"*"<<y<<"="<<g<<endl;
	x*=d;
	y*=d;
	cerr<<a1<<"*"<<x<<"+"<<a2<<"*"<<y<<"="<<d*g<<endl;
	if(x<0)
	{
		long long t=-x;
		long long z=a2/g;
		long long k=(t+z-1)/z;
		x+=k*z;
		y-=k*(a1/g);
	}
	if(y>0)
	{
		long long t=y;
		long long z=a1/g;
		long long k=(t+z-1)/z;
		x+=k*(a2/g);
		y-=k*z;
	}
	{
		long long z=a2/g;
		long long w=a1/g;
		long long k1=x/z;
		long long k2=-y/w;
		if(k1>k2)k1=k2;
		x-=k1*z;
		y+=k2*w;
	}
	cerr<<a1<<"*"<<x<<"+"<<a2<<"*"<<y<<"="<<d*g<<endl;
	long long s=b1+a1*x;
	long long a=a1/g*a2;
	if(s<0)s%=a;
	if(s<0)s+=a;
	cerr<<a<<"x+"<<s<<"<="<<N<<endl;
	if(s>N)return 0;
	return 1+(N-s)/a;
}
main()
{
	long long L,R;
	cin>>a1>>b1>>a2>>b2>>L>>R;
	R-=L;
	b1-=L;
	b2-=L;
	if(b1>b2)swap(b1,b2),swap(a1,a2);
	cerr<<a1<<"x+"<<b1<<endl;
	cerr<<a2<<"x+"<<b2<<endl;
	cout<<f(R)<<endl;
}