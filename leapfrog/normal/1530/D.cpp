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
int n,a[200005],b[200005],tn[200005],ct;
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) tn[i]=b[i]=0,read(a[i]);
	for(int i=1;i<=n;i++) if(!tn[a[i]]) b[i]=a[i],tn[a[i]]=1;
	ct=1;for(int i=1;i<=n;i++) if(!b[i]) {while(tn[ct]) ct++;b[i]=ct++;}
	ct=0;for(int i=1;i<=n;i++) if(b[i]==i) {if(!ct) ct=i;else swap(b[ct],b[i]);}
	if(ct) for(int i=1;i<=n;i++) if(a[i]==a[ct]) {swap(b[i],b[ct]);break;}
	//for(int i=1;i<=n;i++) if(!b[i]) b[i]=c[ct--];
	//for(int i=1;i<=n;i++) if(b[i]==i) assert(0);
	int cnt=0;for(int i=1;i<=n;i++) cnt+=b[i]==a[i];
	printf("%d\n",cnt);for(int i=1;i<=n;i++) printf("%d%c",b[i],i==n?'\n':' ');
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}