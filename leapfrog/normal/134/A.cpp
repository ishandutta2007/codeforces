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
int n,a[1000005];ll sm;
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),sm+=a[i];
	vector<int>v;for(int i=1;i<=n;i++) if(1ll*n*a[i]==sm) v.push_back(i);
	printf("%d\n",(int)v.size());for(auto x:v) printf("%d ",x);
	return putchar('\n'),0;
}