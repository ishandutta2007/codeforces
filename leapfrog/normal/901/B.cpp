//Coded by leapfrog on 2021.11.04 {{{
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
const int N=155;int n,a[N][N];
int main()
{
	read(n),a[0][0]=1,a[1][1]=1;
	for(int i=2;i<=n;i++)
	{
		a[i][0]=a[i-2][0];
		for(int j=1;j<=i;j++) a[i][j]=a[i-2][j]^a[i-1][j-1];
	}
	printf("%d\n",n);
	for(int i=0;i<=n;i++) printf("%d%c",a[n][i],i==n?'\n':' ');
	printf("%d\n",n-1);
	for(int i=0;i<n;i++) printf("%d%c",a[n-1][i],i==n-1?'\n':' ');
	return 0;
}