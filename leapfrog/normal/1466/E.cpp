//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7;
int T,n,cnt[65];ll a[1000005];
int main()
{
	for(read(T);T--;)
	{
		memset(cnt,0,sizeof(cnt));ll res=0;
		read(n);for(int i=1;i<=n;i++) read(a[i]);
		for(int i=1;i<=n;i++) for(int j=0;j<63;j++) cnt[j]+=(a[i]>>j)&1;
		for(int i=1;i<=n;i++)
		{
			ll nw=0;
			for(int j=0;j<63;j++) if((a[i]>>j)&1) nw=(nw+(1ll<<j)%P*n%P)%P;else nw=(nw+(1ll<<j)%P*cnt[j]%P)%P;
			for(int j=0;j<63;j++) if((a[i]>>j)&1) res=(res+(1ll<<j)%P*cnt[j]%P*nw%P)%P;
		}
		printf("%lld\n",res);
	}
	return 0;
}