//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int Ca,n,a[100005],l[100005],tn[100005],tt;
inline void solve()
{
	read(n),tt=0;for(int i=1;i<=n;i++) read(a[i]);
	for(int i=1;i<=n;i++) {read(l[i]);if(!l[i]) tn[++tt]=a[i];}
	sort(tn+1,tn+tt+1,greater<int>());int nw=1;
	for(int i=1;i<=n;i++) if(l[i]) printf("%d ",a[i]);else printf("%d ",tn[nw++]);
	return putchar('\n'),void();
}
int main() {for(read(Ca);Ca--;) solve();return 0;}