#include <bits/stdc++.h>
using namespace std;
// (martingale; optional stopping theroem)
// guess: ans=sum(f(a_i))+C; m=sum(a_i)
// a: (m,0,...,0) ans=0
// -1=E(next_ans-ans)=sum(i!=j,a_i*a_j/m/(m-1)*(f(a_i+1)+f(a_j-1)-f(a_i)-f(a_j)))
//   =sum(a_i(m-a_i)/m/(m-1)*(f(a_i+1)+f(a_i-1)-2f(a_i))) item=0 if a_i=0 or m
// (if a_i!=(m,0,...,0), a_i<m)
// let x(m-x)/m/(m-1)*(f(x+1)+f(x-1)-2f(x))=-x/m and f(0)=f(1)=0 (<= f(x)+kx+c is ok)
// (f(x+1)-f(x))-(f(x)-f(x-1))=-(m-1)/(m-x)
// f(x+1)-f(x)=f(1)-f(0)+sum(i=1 to x,-(m-1)/(m-i))=sum(i=1 to x,-(m-1)/(m-i))
// f(m)=sum(j=0 to m-1,sum(i=1 to j,-(m-1)/(m-i)))=sum(i=1 to m-1,-(m-1)/(m-i)*(m-i))=-(m-1)^2
// ans=sum(f(a_i))-(n-1)f(0)-f(m)=sum(f(a_i))+(m-1)^2

// solution 2(luogu P5516): enumerate i: all color i at end (c_i balls) (regard as 2 colors)
// easy to know P=c_i/m (P(x)=(P(x+1)+P(x-1))/2, P(0)=0, P(m)=1)
// e: P*E(|...); e(0)=e(m)=0,e(x)=(e(x+1)+e(x-1))/2+m(m-1)/2x(m-x)*P=(e(x+1)+e(x-1))/2+(m-1)/2(m-x)
// (same equation with f but different bondary condition)
// easy to solve for e(1), ans=sum(e(c_i))
typedef long long ll;
const int kcz=1000000007;
const int maxn=2500;
const int maxa=100005;
int n,m,a[maxn],A;
ll ans,f[maxa];
void gcd(ll a,ll b,ll &x,ll &y) { if(b) gcd(b,a%b,y,x),y-=x*(a/b); else x=1,y=0; }
inline ll inv(ll a) { ll x,y; gcd(a,kcz,x,y); return x+((x<0)?kcz:0); }
int main()
{
    int i;
    scanf("%d",&n);
    for(i=0,m=A=0;i<n;i++) scanf("%d",&a[i]),m+=a[i],A=max(A,a[i]);
    for(f[0]=f[1]=0,i=2;i<=A;i++) f[i]=(kcz-m+1)*inv(m-(i-1))%kcz;
    for(i=2;i<=A;i++) (f[i]+=f[i-1])%=kcz;
    for(i=2;i<=A;i++) (f[i]+=f[i-1])%=kcz;
    ans=(m-1ll)*(m-1ll)%kcz;
    for(i=0;i<n;i++) (ans+=f[a[i]])%=kcz;
    printf("%lld\n",ans);
    return 0;
}