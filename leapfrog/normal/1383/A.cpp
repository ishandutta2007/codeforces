//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
const int P=998244353;int T,n,fa[35];char c[100005],s[100005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline char mrg(int x,int y) {x=getf(x),y=getf(y);return x^y?fa[x]=y,1:0;}
inline void solve()
{
	int cnt=0;read(n),scanf("%s%s",c+1,s+1);for(int i=1;i<=26;i++) fa[i]=i;
	for(int i=1;i<=n;i++) if(c[i]>s[i]) return puts("-1"),void();else cnt+=mrg(c[i]-'a'+1,s[i]-'a'+1);
	printf("%d\n",cnt);
}
int main() {for(read(T);T--;) solve();return 0;}