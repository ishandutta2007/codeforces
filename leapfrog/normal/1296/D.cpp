#include<bits/stdc++.h>
using namespace std;
int n,a,b,k,w[200005];
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int main()
{
	read(n),read(a),read(b),read(k);
	for(int i=1;i<=n;i++) read(w[i]),w[i]--,w[i]%=(a+b);
	sort(w+1,w+n+1);int res=0;
	for(int i=1;i<=n;i++) if(w[i]/a<=k) k-=w[i]/a,res++;else break;
	return printf("%d\n",res),0;
}