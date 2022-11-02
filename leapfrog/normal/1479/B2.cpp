//Coded by Kamiyama_Shiki on 2021.11.08 {{{
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
const int N=100005;int n,a[N],rs=0,nx[N],tn[N];
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),tn[i]=n+1;
	for(int i=n;i>=1;i--) nx[i]=tn[a[i]],tn[a[i]]=i;
	int x=0,y=0;nx[0]=n+1;
	for(int i=1;i<=n;i++)
	{
		if(a[x]!=a[i]&&a[y]!=a[i]) {rs++;if(nx[x]<nx[y]) y=i;else x=i;}
		else if(a[x]==a[i]) x=i;
		else if(a[y]==a[i]) y=i;
		else x=y=i;
	}
	return printf("%d\n",rs),0;
}