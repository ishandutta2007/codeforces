//Coded by leapfrog on 2021.10.29 {{{
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
const int N=1000005;int n;
char a[N],b[N];int v[N],cn;
int main()
{
	read(n),scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;i++) cn+=(a[i]^=48),cn-=(b[i]^=48);
	int sm,r1=0,r2=0;if(cn) return puts("-1"),0;
	sm=0;for(int i=1;i<=n;i++) if(a[i]^b[i]) sm=max(sm+(a[i]<<1)-1,0),r1=max(r1,sm);
	sm=0;for(int i=1;i<=n;i++) if(a[i]^b[i]) sm=max(sm+(b[i]<<1)-1,0),r2=max(r2,sm);
	return printf("%d\n",max(r1,r2)),0;
}