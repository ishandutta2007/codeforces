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
int T,n,a[2005],tn[2000005];
inline void clear() {for(int i=1;i<=n;i++) tn[a[i]]=0;}
inline char chk(int sm,int fg)
{
	for(int i=1;i<=n;i++) tn[a[i]]++;
	if(fg) puts("YES"),printf("%d\n",sm);
	for(int i=1,wh=n;i+i<=n;i++)
	{
		if(!tn[sm-a[wh]]||wh<1) return clear(),0;
		if(fg) printf("%d %d\n",a[wh],sm-a[wh]);
		tn[a[wh]]--;if(!tn[sm-a[wh]]) return clear(),0;
		tn[sm-a[wh]]--,sm=a[wh];
		while(wh>=1&&!tn[a[wh]]) wh--;
	}
	return clear(),1;
}
inline void solve()
{
	read(n),n<<=1;for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<n;i++) if(chk(a[i]+a[n],0)) return chk(a[i]+a[n],1),void();
	puts("NO");
}
int main() {for(read(T);T--;) solve();return 0;}