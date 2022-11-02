//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,a[100005],cnt=0,q;
int main()
{
	read(n),read(q);for(int i=1;i<=n;i++) read(a[i]),cnt+=a[i]==1;
	for(int op,x;q--;) {read(op),read(x);if(op==2) printf("%d\n",cnt>=x);else {if(a[x]==0) cnt++;else cnt--;a[x]^=1;}}
}