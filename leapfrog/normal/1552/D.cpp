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
int n,m,K,a[15];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),a[i]=a[i]<0?-a[i]:a[i];
	int pw=1;for(int i=1;i<=n;i++) pw*=3;
	for(int i=1;i<pw;i++)
	{
		int sm=0;for(int j=1,x=i;j<=n;j++,x/=3)
			if(x%3==1) sm+=a[j];else if(x%3==2) sm-=a[j];
		if(sm==0) return puts("YES"),void();
	}
	puts("NO");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}