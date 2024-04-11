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
int Ca,n,a[100005],c[100005];
inline void solve()
{
	read(n);ll res=0;int qwq=0;
	for(int i=1;i<=n;i++) read(a[i]),c[i]=0;
	for(int i=1;i<=n;i++)
	{
		qwq+=c[i];
		if(qwq<a[i]) res+=a[i]-1-qwq,c[i+2]++,c[min(n+1,i+a[i]+1)]--;
		else c[i+1]+=qwq-a[i]+1,c[i+2]-=qwq-a[i],c[min(n+1,i+a[i]+1)]--;
	}
	printf("%lld\n",res);
}
int main() {for(read(Ca);Ca--;) solve();}