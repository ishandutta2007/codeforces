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
int n,q[200005],hd=1,tl,rs=0;char v[200005];
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),q[++tl]=x;
	for(int i=1,x;i<=n;i++)
	{
		while(v[q[hd]]) hd++;
		read(x),v[x]=1;if(q[hd]!=x) rs++;
	}
	return printf("%d\n",rs),0;
}