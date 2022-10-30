//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}/*}}}*/
int n,b[1000505],lg[1000505];
int main()
{
	read(n);for(int i=1,x;i<=n;i++) read(x),b[x]++;
	lg[0]=-1;for(int i=1;i<=1000000;i++) lg[i]=lg[i>>1]+1;
	for(int i=0;i<=1000500;i++) if(b[i])
		while(b[i]>1) b[i+lg[b[i]]]++,b[i]-=1<<lg[b[i]];
	int res=0;for(int i=0;i<=1000500;i++) res+=b[i];
	return printf("%d\n",res),0;
}