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
const int N=155;char ch[N][N];int n,m;
int main()
{
	read(n,m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	int xx=0,xn=n+1,yx=0,yn=m+1;
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]=='B')
		xx=max(xx,i),xn=min(xn,i),yx=max(yx,j),yn=min(yn,j);
	return printf("%d %d\n",(xx+xn)/2,(yx+yn)/2),0;
}