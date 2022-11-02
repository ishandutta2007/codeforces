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
int n,a[405],rs=1e9+5;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
	{
		int c1=1,c2=0,vl=a[i]-1,nw;
		for(int k=i+1;k<=j;k++) c1+=vl/a[k],vl%=a[k];
		nw=vl=a[i]-vl-1+a[j];
		for(int k=1;k<=n;k++) c2+=vl/a[k],vl%=a[k];
		if(c1<c2) rs=min(rs,nw);
	}return printf("%d\n",rs>1e9?-1:rs),0;
}