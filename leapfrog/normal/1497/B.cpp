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
int Ca,n,m,a[100005],cnt[100005];
inline void solve()
{
	read(n),read(m);for(int i=1;i<=n;i++) read(a[i]);
	int res=0;for(int i=1;i<=n;i++) cnt[a[i]%m]++;
	if(cnt[0]) res++,cnt[0]=0;
	for(int i=1;i<=m/2;i++)
	{
		int a=cnt[i],b=cnt[m-i];if(a>b) swap(a,b);
		if(!a&&!b);else if(a==b||a+1==b) res++;else res+=b-a;
	}
	printf("%d\n",res);for(int i=1;i<=n;i++) cnt[a[i]%m]=0;
}
int main() {for(read(Ca);Ca--;) solve();return 0;}