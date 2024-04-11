//Coded by leapfrog on 2021.10.29 {{{
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
const int N=524295;
int n,X,vs[N],rs[N],rst;
int main()
{
	read(n,X),vs[X]=1;for(int i=1;i<(1<<n);i++) if(!vs[i]) rs[++rst]=i,vs[i^X]=1;
	printf("%d\n",rst);for(int i=1;i<=rst;i++) printf("%d%c",rs[i]^rs[i-1],i==rst?'\n':' ');
	return 0;
}