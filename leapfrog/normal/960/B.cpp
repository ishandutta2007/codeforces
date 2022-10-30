//Coded by Kamiyama_Shiki on 2021.11.10 {{{
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
int n,K,k1,k2,a[1005],b[1005];priority_queue<int>q;
int main()
{
	read(n,k1,k2),K=k1+k2;
	for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) {read(b[i]);if(a[i]^b[i]) q.push(abs(a[i]-b[i]));}
	while(!q.empty()&&K)
	{
		K--;int x=q.top();q.pop();
		if(--x) q.push(x);
	}
	if(q.empty()) return printf("%d\n",K&1),0;
	ll rs=0;while(!q.empty()) rs+=1ll*q.top()*q.top(),q.pop();
	return printf("%lld\n",rs),0;
}