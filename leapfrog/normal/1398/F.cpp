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
int n,ls[1000005][2];char ch[1000005];
int main()
{
	read(n),scanf("%s",ch+1);for(int i=1;i<=n;i++)
	{
		ls[i][0]=ls[i-1][0],ls[i][1]=ls[i-1][1];
		if(ch[i]^'?') ls[i][(ch[i]&1)^1]=i;
	}
	for(int l=1;l<=n;l++)
	{
		int nw=0,rs=0;while(nw+l<=n)
			if(ls[nw+l][0]==ls[nw][0]||ls[nw+l][1]==ls[nw][1]) rs++,nw+=l;
			else nw=min(ls[nw+l][0],ls[nw+l][1]);
		printf("%d%c",rs,l==n?'\n':' ');
	}return 0;
}