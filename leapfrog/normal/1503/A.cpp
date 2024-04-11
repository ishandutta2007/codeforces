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
int T,n;char ch[200005],a[200005],b[200005];
inline void solve()
{
	read(n),scanf("%s",ch+1),a[n+1]=b[n+1]=0;int cn=0;
	if(ch[1]=='0'||ch[n]=='0') return puts("NO"),void();
	for(int i=1;i<=n;i++) {a[i]=b[i]='(';if(ch[i]=='0') cn++,(cn&1?a:b)[i]=')';}
	if(cn&1) return puts("NO"),void();
	cn=(n-cn)>>1;for(int i=n;i;i--) if(ch[i]=='1'&&cn) cn--,a[i]=b[i]=')';
	if(cn) return puts("NO"),void();else puts("YES"),printf("%s\n%s\n",a+1,b+1);
}
int main() {for(read(T);T--;) solve();return 0;}