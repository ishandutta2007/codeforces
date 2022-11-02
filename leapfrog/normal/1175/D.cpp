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
int n,K,a[300005];ll sm[300005];
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	sm[n+1]=0;for(int i=n;i;i--) sm[i]=sm[i+1]+a[i];
	priority_queue<ll>q;ll rs=sm[1];
	for(int i=2;i<=n;i++) q.push(sm[i]);
	K--;for(int i=1;i<=K;i++) rs+=q.top(),q.pop();
	printf("%lld\n",rs);
}