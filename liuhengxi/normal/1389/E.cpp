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
int t,m,d,w,s,ww;
long long ans;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
int main()
{
	read(t);
	while(t--)
	{
		ans=0;
		read(m);read(d);read(w);
		ww=w/gcd(w,d-1);
		s=m<d?m:d;
		ans=(long long)(s/ww)*(s/ww-1)/2*ww;
		ans+=s%ww*(long long)(s/ww);
		printf("%lld\n",ans);
	}
	return 0;
}