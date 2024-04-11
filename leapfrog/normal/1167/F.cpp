//Coded by leapfrog on 2021.10.27 {{{
//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=500005,P=1e9+7;int n,a[N],tn[N],rs;
struct bit
{
	int T[N];inline int pls(int a,int b) {return (a+=b)>=P?a-P:a;}
	inline void add(int x,int w) {for(;x<=n;x+=x&(-x)) T[x]=pls(T[x],w);}
	inline int qry(int x) {int r=0;for(;x;x-=x&(-x)) r=pls(r,T[x]);return r;}
}A,B;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),tn[i]=a[i];
	sort(tn+1,tn+n+1);for(int i=1;i<=n;i++) a[i]=lower_bound(tn+1,tn+n+1,a[i])-tn;
	for(int i=1;i<=n;i++) rs=(rs+1ll*tn[a[i]]*A.qry(a[i])%P*(n-i+1))%P,A.add(a[i],i);
	for(int i=n;i>=1;i--) rs=(rs+1ll*tn[a[i]]*B.qry(a[i])%P*i)%P,B.add(a[i],n-i+1);
	for(int i=1;i<=n;i++) rs=(rs+1ll*i*(n-i+1)%P*tn[a[i]])%P;
	return printf("%d\n",rs),0;
}