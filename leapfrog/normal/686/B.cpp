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
const int N=1005;
int n,a[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) for(int j=n;j>i;j--)
		if(a[j-1]>a[j]) printf("%d %d\n",j-1,j),swap(a[j-1],a[j]);
}