//Coded by STUPID_JUSTlN {{{
//Gened on 2021.10.24 18:05:02
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
const int N=100005;int n,a[N],fg[513];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	memset(fg,0x3f,sizeof(fg)),fg[0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int v=0;v<512;v++) if(fg[v]<a[i])
			fg[a[i]^v]=min(fg[a[i]^v],a[i]);
	}
	int mx=0;for(int i=1;i<=n;i++) mx=max(mx,a[i]);
	int rs=0;for(int i=0;i<512;i++) rs+=(fg[i]<=mx);
	printf("%d\n",rs);for(int i=0;i<512;i++) if(fg[i]<=mx) printf("%d ",i);
	return putchar('\n'),0;
}