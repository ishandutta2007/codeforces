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
const int N=105;int n;char a[N];
inline void solve()
{
	read(n),scanf("%s",a+1);
	int fs=0;for(int i=1;i<=n;i++) if(a[i]=='>') {fs=i;break;}
	int ls=0;for(int i=n;i>=1;i--) if(a[i]=='<') {ls=i;break;}
	if(!fs) puts("0");else printf("%d\n",min(fs-1,n-ls));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}