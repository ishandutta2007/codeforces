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
inline int count(int n)
{
	char cn[11];memset(cn,0,sizeof(cn));
	while(n) cn[n%10]=1,n/=10;
	int rs=0;for(int i=0;i<10;i++) rs+=cn[i];
	return rs;
}
inline void solve()
{
	int n,K;read(n),read(K);
	while(count(n)>K)
	{
		int l=1,r=n;while(count(r)>K) r/=10,l*=10;
		l/=10,n=((n/l)+1)*l;
	}
	printf("%d\n",n);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}