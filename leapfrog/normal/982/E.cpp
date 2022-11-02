#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int n,m,x,y,u,v;
inline int gcd(int x,int y) {return y?gcd(y,x%y):x;}
inline void exgcd(ll a,ll b,ll &x,ll &y) {if(!b) x=1,y=0;else exgcd(b,a%b,y,x),y-=a/b*x;}
int main()
{
	read(n),read(m),read(x),read(y),read(u),read(v);
	if(u==0) return x==0||x==n?printf("%d %d\n",x,(v>0)*m):puts("-1"),0;
	if(v==0) return y==0||y==m?printf("%d %d\n",(u>0)*n,y):puts("-1"),0;
	if(u<0) u=1,x=n-x;else u=0;
	if(v<0) v=1,y=m-y;else v=0;
	if((x-y)%gcd(n,m)) return puts("-1");
	//printf("%d %d %d %d %d %d\n",n,m,x,y,u,v);
	ll A,B,g=gcd(n,m),aa=m/g;exgcd(n,-m,A,B),A*=(x-y)/g,B*=(x-y)/g;
	if(x-y!=A*n-B*m) A=-A,B=-B;
	ll ra=((A+aa-1)%aa+aa)%aa+1,rb=(ra*n-x+y)/m;u^=ra&1,v^=rb&1;
	//printf("%lld , %lld ; %lld , %lld\n",A,B,ra,rb);
	return printf("%d %d\n",u?n:0,v?m:0),0;
}