#include<bits/stdc++.h>//{{{
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
    x=0;char c=getchar(),f=0;
    for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
    for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
    f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
const int N=200005;int n,a[N],f1[N],f2[N];char ch[N];
inline void solve()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]),f1[i]=f2[i]=0;
	scanf("%s",ch+1);for(int i=1;i<=n;i++)
		if(ch[i]=='B') if(a[i]<1) return puts("NO"),void();else f1[min(a[i],n)]++;
		else if(a[i]>n) return puts("NO"),void();else f2[max(a[i],1)]++;
	for(int i=n-1;i>=1;i--) f1[i]+=f1[i+1];
	for(int i=2;i<=n;i++) f2[i]+=f2[i-1];
	int cnt=0;for(int i=1;i<=n;i++) if(ch[i]=='B') cnt++;
	for(int i=cnt;i>=1;i--) if(f1[i]<cnt-i+1) return puts("NO"),void();
	for(int i=cnt+1;i<=n;i++) if(f2[i]<i-cnt) return puts("NO"),void();
	puts("YES");
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}