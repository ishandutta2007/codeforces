//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
const int P=1e9+7;int n;ll sm[500005],a[500005];
struct vec
{
	ll x,y;inline ll operator*(vec a) const {return x*a.y-y*a.x;}
	inline vec operator+(vec a) const {return(vec){x+a.x,y+a.y};}
	inline vec operator-(vec a) const {return(vec){x-a.x,y-a.y};}
	inline vec operator%(int P) const {return(vec){x%P,y%P};}
}p[500005],s[500005];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline ll Abs(ll a) {return a<0?-a:a;}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(p[i].x),read(p[i].y),s[i]=(s[i-1]+p[i])%P;
	for(int i=2;i<=n;i++) a[i]=a[i-1]+p[i-1]*p[i],sm[i]=(sm[i-1]+a[i]%P)%P;
	a[n+1]=a[n]+p[n]*p[1];ll nw=Abs(a[n+1]);int rs=0;
	for(int l=1,r=3;r<=n;r++)
	{
		while(l<r-1&&nw/2.0<Abs(a[r]-a[l]+p[r]*p[l])) ++l;
		rs=(rs+a[r]%P*(r-l-1)-sm[r-2]+sm[l-1]+p[r]*(s[r-2]-s[l-1]))%P;
		rs=(rs+sm[l-1]+s[l-1]*p[r]%P+(a[n+1]-a[r])%P*(l-1)%P)%P;
	}
	rs=(rs+nw%P*ksm(4)%P*n%P*(n-3)%P)%P;
	return printf("%lld\n",(rs*2ll%P+P)%P),0;
}