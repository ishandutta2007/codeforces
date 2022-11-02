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
int T,n,a[100005],w,cnt[100005];ll res=0;
inline int getw(int x,int w) {int cnt=0;while(x%w==0) cnt++,x/=w;return cnt;}
int main()
{
	for(read(T);T--;)
	{
		read(n),read(w),res=0;for(int i=1;i<=n;i++) read(a[i]),cnt[i]=getw(a[i],w);
		int wh,mn=1e9;for(int i=1;i<=n;i++) if(mn>=cnt[i]) mn=cnt[i];
		for(int i=1;i<=n;i++) if(cnt[i]==mn) {wh=i;break;}
//		printf("%d , %d\n",wh,mn);
		for(int i=1;i<=n;i++) if(i<wh) res+=1ll*(mn+2)*a[i];else res+=1ll*(mn+1)*a[i];
		printf("%lld\n",res);
	}
	return 0;
}