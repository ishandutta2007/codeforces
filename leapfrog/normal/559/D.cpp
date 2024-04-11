//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=100005;int n;typedef long double db;
struct vec
{
	int x,y;
	inline vec operator+(vec b) {return(vec){x+b.x,y+b.y};}
	inline vec operator-(vec b) {return(vec){x-b.x,y-b.y};}
	inline ll operator*(vec b) {return 1ll*x*b.y-1ll*y*b.x;}
	inline int count() {return abs(__gcd(x,y));}
}a[N];db pw[N];
inline db gl(int k)
{
	if(n>100) return 1.0/pw[k];
	return (pw[n-k]-1)/(pw[n]-1-n-1.0*n*(n-1)/2);
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i].x,a[i].y);
	pw[0]=1;for(int i=1;i<=100;i++) pw[i]=pw[i-1]*2;
	ll Cn=0,S=0;for(int i=1;i<=n;i++) S+=a[i]*a[i%n+1],Cn+=(a[i%n+1]-a[i]).count();
	db del=0;for(int i=1;i<=n;i++)
	{
		ll s=a[i]*a[i%n+1],cn=(a[i%n+1]-a[i]).count();
		for(int k=3,j=(i+1)%n+1;k<=60&&j%n+1!=i;k++,j=j%n+1)
		{
			s+=a[(j-2+n)%n+1]*a[j],cn+=(a[j]-a[(j-2+n)%n+1]).count();
			del+=gl(k)*(s+a[j]*a[i]-cn+(a[i]-a[j]).count())/2.0;
#ifdef debug
			printf("gl : %.10Lf\n",gl(k));
			printf("del : %.10lf\n",(s+a[j]*a[i]-cn+(a[i]-a[j]).count())/2.0);
#endif
		}
	}
	return printf("%.10Lf\n",(S+2-Cn)/2.0-del),0;
}