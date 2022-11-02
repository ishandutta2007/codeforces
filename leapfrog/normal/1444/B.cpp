//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	char c=getchar();int f=0;x=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	f?x=-x:x;
}
int n,a[300005];const int P=998244353;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n);for(int i=1;i<=n+n;i++) read(a[i]);
	sort(a+1,a+n+n+1);int res=0;
	for(int i=1;i<=n;i++) (res+=P-a[i])%=P;
	for(int i=n+1;i<=n+n;i++) (res+=a[i])%=P;
	for(int i=1;i<=n;i++) res=1ll*res*ksm(i)%P;
	for(int i=n+1;i<=n+n;i++) res=1ll*res*i%P;
	return printf("%d\n",res),0;
}