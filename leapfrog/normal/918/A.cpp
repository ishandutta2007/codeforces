//Coded by Kamiyama_Shiki on 2021.11.09 {{{
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
const int N=1005;int n,f[N];char a[N];
int main()
{
	read(n),f[1]=1,f[2]=1;
	int i;for(i=3;f[i-1]<=n;i++) f[i]=f[i-1]+f[i-2];
	for(int j=1;j<=i;j++) a[f[j]]=1;
	for(int i=1;i<=n;i++) if(a[i]) putchar('O');else putchar('o');
	return putchar('\n'),0;
}