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
int n,a[200005];priority_queue<int>q;
int main()
{
	read(n);int cnt=0;for(int i=1;i<=n;i++) read(a[i]);
	ll sm=0;for(int i=1;i<=n;i++) {sm+=a[i],q.push(-a[i]);if(sm<0) sm+=q.top(),q.pop(),cnt++;}
	return printf("%d\n",n-cnt),0;
}