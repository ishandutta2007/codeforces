//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	char c=getchar();int f=0;x=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<3)+(x<<1)+(c^48);
	f?x=-x:x;
}
int T,n,a[100005],b[100005],K;
inline void solve()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]);
	sort(a+1,a+n+1);for(int i=1;i<=n;i++) read(b[i]);
	sort(b+1,b+n+1,greater<int>());int cnt=0;
	for(int i=1;i<=n;i++) cnt+=(a[i]+b[i]>K);
	if(cnt) puts("No");else puts("Yes");
}
int main() {for(read(T);T--;) solve();}