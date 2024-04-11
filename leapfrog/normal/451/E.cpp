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
const int P=1e9+7;int n;ll s,a[21],iv[21];
inline int C(ll n,int m)
{
	if(n<0||m<0||n<m) return 0;else if(!m||n%P==0) return 1;
	int r=1;for(ll i=n-m+1;i<=n;i++) r=i%P*r%P;
	for(int i=1;i<=m;i++) r=1ll*iv[i]*r%P;
	return r;
}
int main()
{
	read(n),read(s);for(int i=1;i<=n;i++) read(a[i]);
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	int rs=0;for(int S=0;S<(1<<n);S++)
	{
		char cn=0;ll lim=s;
		for(int i=0;i<n;i++) if((S>>i)&1) cn^=1,lim-=a[i+1]+1;
		if(cn) rs=(rs+P-C(lim+n-1,n-1))%P;else rs=(rs+C(lim+n-1,n-1))%P;
	}
	return printf("%d\n",rs),0;
}