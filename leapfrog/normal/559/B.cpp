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
char s[200005],t[200005];int n,m;
inline char sam(int l,int r,int a,int b)
{
	if(r-l!=b-a) return 0;
	for(int i=l;i<=r;i++) if(s[i]!=t[i-l+a]) return 0;
	return 1;
}
inline char chk(int l,int r,int a,int b)
{
	int m=(l+r)>>1,c=(a+b)>>1;if((r-l+1)&1) return sam(l,r,a,b);
	return (chk(l,m,a,c)&&chk(m+1,r,c+1,b))||(chk(l,m,c+1,b)&&chk(m+1,r,a,c));
}
int main()
{
	scanf("%s",s+1),n=strlen(s+1),scanf("%s",t+1),m=strlen(t+1);
	return puts(n==m&&chk(1,n,1,n)?"YES":"NO"),0;
}