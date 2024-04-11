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
int fg[105][105];
int main()
{
	int n;read(n);
	if(n==5) return puts(">...v\nv.<..\n..^..\n>....\n..^.<\n1 1"),0;
	if(n==3) return puts(">vv\n^<.\n^.<\n1 3\n");
	int lim=n/2-1;
	for(int k=n;k>=1;k--)
	{
		if(k&1)
		{
			for(int i=1;i<=lim;i++) fg[k][i]='>';
			for(int i=lim+1;i<=lim*2;i++) fg[k][i]=(i-lim)&1?'>':'.';
			fg[k][lim*2+1]='^';
		}
		else
		{
			for(int i=2;i<=lim+1;i++) fg[k][i]=i&1?'<':'.';
			for(int i=lim+1;i<=lim*2+1;i++) fg[k][i]='<';
			fg[k][1]='^';
		}fg[k][n]='v';
	}
	fg[1][n-1]='.',fg[n][n]='<';
	for(int i=1;i<=n;i++,putchar('\n')) for(int j=1;j<=n;j++) putchar(fg[i][j]);
	printf("%d %d\n",n,n);
}