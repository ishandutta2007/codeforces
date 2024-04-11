//Coded by leapfrog on 2021.10.28 {{{
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
const int N=1005;
int al[N],ar[N],bl[N],br[N],at,bt,l,r,rs;
inline char chk(int a,int b,int l,int r) {return max(l,a)<=min(b,r);}
int main()
{
	read(at,bt,l,r);
	for(int i=1;i<=at;i++) read(al[i],ar[i]);
	for(int i=1;i<=bt;i++) read(bl[i],br[i]);
	for(int k=l;k<=r;k++)
	{
		char fg=0;
		for(int i=1;i<=at;i++) for(int j=1;j<=bt;j++)
			if(chk(al[i],ar[i],bl[j]+k,br[j]+k)) {fg=1;break;}
		rs+=fg;
	}return printf("%d\n",rs),0;
}