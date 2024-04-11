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
const int N=1005;int n,m,d[N],s[N],mx[N],rs=0;
int main()
{
	read(n,m);for(int i=1;i<=n;i++) read(d[i]);
	for(int i=1;i<=n;i++) read(s[i]),mx[i]=max(s[i],mx[i-1]);
	int nw=0;for(int i=1;i<=n;i++)
	{
		nw+=s[i];while(nw<d[i]) nw+=mx[i],rs+=m;
		nw-=d[i],rs+=d[i];
	}return printf("%d\n",rs),0;
}