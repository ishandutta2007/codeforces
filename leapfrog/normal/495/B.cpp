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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
int main()
{
	int a,b,rs=0;read(a,b),a-=b;
	for(int i=1;i*i<=a;i++) if(a%i==0) rs+=(i>b)+(a/i!=i&&a/i>b);
	if(!a) puts("infinity");else printf("%d\n",rs);
}