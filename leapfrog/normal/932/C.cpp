#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=1000005;int a,b,n,nw=0;
inline void cir(int x,int y) {for(int i=x+1;i<=y;i++) printf("%d ",i);printf("%d ",x);}
int main()
{
	read(n,a,b);int x=-1,y;
	for(int i=0;i*a<=n;i++) if((n-i*a)%b==0) x=i,y=(n-i*a)/b;
	if(x==-1) return puts("-1"),0;
	for(int i=1;i<=x;i++) cir(nw+1,nw+a),nw+=a;
	for(int i=1;i<=y;i++) cir(nw+1,nw+b),nw+=b;
	return putchar('\n'),0;
}