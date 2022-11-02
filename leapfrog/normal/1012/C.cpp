///ll dp[j][0/1/2/3]  j  1/2 
//Coded by leapfrog on 2021.11.19 {{{
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
int f[5005][4],n,a[5005];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(f,0x3f,sizeof(f)),f[0][0]=f[1][1]=0;
	for(int i=2;i<=n;i++) for(int j=(n+1)/2;j;j--)
		f[j][0]=min(f[j][0],f[j][2]),
		f[j][2]=f[j][1]+max(0,a[i]-a[i-1]+1),
		f[j][1]=min(f[j-1][0]+max(0,a[i-1]-a[i]+1),f[j-1][2]+max(0,min(a[i-1],a[i-2]-1)-a[i]+1));
	for(int j=1;j<=(n+1)/2;j++) printf("%d%c",min(f[j][0],min(f[j][1],f[j][2])),j==(n+1)/2?'\n':' ');
	return 0;
}