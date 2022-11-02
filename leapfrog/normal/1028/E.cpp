//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=140585;int n,a[N];ll rs[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),rs[i]=a[i];
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	int ps=0;for(int i=1;i<=n;i++) if(a[i]==mx&&a[(i-2+n)%n+1]!=mx) {ps=i;break;}
	if(mx==0) {puts("YES");for(int i=1;i<=n;i++) printf("1%c",i==n?'\n':' ');return 0;}
	if(!ps) return puts("NO"),0;else puts("YES"),rs[(ps-2+n)%n+1]+=mx;
	for(int i=2;i<=n;i++) rs[(ps-2+n)%n+1]+=rs[ps],ps=(ps-2+n)%n+1;
	for(int i=1;i<=n;i++) printf("%lld%c",rs[i],i==n?'\n':' ');
	return 0;
}