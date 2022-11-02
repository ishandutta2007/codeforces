//Coded by Kamiyama_Shiki on 2021.11.04 {{{
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
const int N=105;
int n,m,fg[N];
int main()
{
	read(n,m),fg[0]=1;for(int i=1,l,r;i<=n;i++)
		{read(l,r);if(fg[l]) for(int j=l;j<=r;j++) fg[j]=1;}
	return puts(fg[m]?"YES":"NO"),0;
}