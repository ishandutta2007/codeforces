//Coded by leap_frog on 2021.11.19 {{{
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
const int N=1005;
int n,a[N][N],cn;
int main()
{
	read(n);for(int i=1;i<=n/2;i++) for(int j=1;j<=n/2;j++)
		a[i][j]=cn<<2,a[i][j+n/2]=cn<<2|1,a[i+n/2][j]=cn<<2|2,a[i+n/2][j+n/2]=cn<<2|3,cn++;
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) printf("%d%c",a[i][j],j==n?'\n':' ');
	return 0;
}