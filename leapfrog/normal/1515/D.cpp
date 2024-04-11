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
int Ca,n,n1,n2,a[200005],b[200005],tn[200005];
inline void solve()
{
	read(n),read(n1),read(n2);int res=0;
	for(int i=1;i<=n1;i++) read(a[i]);
	for(int i=1;i<=n2;i++) read(b[i]);
	for(int i=1;i<=n;i++) tn[i]=0;
	if(n1>n2)
	{
		swap(n1,n2);
		for(int i=1;i<=n;i++) swap(a[i],b[i]);
	}res+=(n2-n1)/2;int cnt=0;
	for(int i=1;i<=n2;i++) tn[b[i]]++;
	for(int i=1;i<=n1;i++) if(tn[a[i]]) tn[a[i]]--;else res++,cnt++;
	for(int i=1;i<=n;i++) if(tn[i]&1) {if(cnt) cnt--;else res++,cnt++;}
	printf("%d\n",res);
}
int main() {for(read(Ca);Ca--;) solve();return 0;}