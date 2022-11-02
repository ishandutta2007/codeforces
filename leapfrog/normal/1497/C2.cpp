//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}/*}}}*/
int Ca,n,K;
inline void solve()
{
	read(n),read(K);
	for(int i=4;i<=K;i++) n--,printf("1 ");
	if(n&1) printf("%d %d %d\n",1,n/2,n/2);
	else if(n%4==2) printf("%d %d %d\n",2,n/2-1,n/2-1);
	else printf("%d %d %d\n",n/4,n/4,n/2);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}