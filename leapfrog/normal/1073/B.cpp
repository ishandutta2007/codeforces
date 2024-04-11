//Coded by leapfrog {{{
//Gened on 2021.10.25 10:05:52
//
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
const int N=200005;int n,a[N],b[N];char v[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),b[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		int cn=0,x;read(x);
		for(int j=b[x];j>=1;j--) if(v[j]) break;else cn++,v[j]=1;
		printf("%d%c",cn,i==n?'\n':' ');
	}return 0;
}