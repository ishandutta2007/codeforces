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
int n,m,K;char a[2000005],b[2000005];ll N,M;
inline int work()
{
	int a2=5,a1=5,b2=0,b1=0;
	//for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
	for(int i=1;i<=n;i++)
	{
		if(i&1) a1--,b1+=b[i];else a2--,b2+=b[i];
		if(a1+b1<b2||a2+b2<b1) return i;
	}
	return 1e9;
}
inline void solve()
{
	scanf("%s",a+1),n=10;int mx=1e9;
	for(int i=1;i<=n;i++) if(a[i]=='?') b[i]=i&1;else b[i]=a[i]^48;
	mx=min(mx,work());
	for(int i=1;i<=n;i++) if(a[i]=='?') b[i]=!(i&1);else b[i]=a[i]^48;
	mx=min(mx,work());
	printf("%d\n",min(mx,10));
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}