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
int T,n,m,a[1000005];char ch[1000005];
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);int wh=0;
	for(int i=1;i<=n;i++) if(ch[i]^'a') wh=i;
	if(!wh) return puts("NO"),void();else puts("YES");
	wh=n+1-wh;for(int i=1;i<wh;i++) putchar(ch[i]);
	putchar('a');for(int i=wh;i<=n;i++) putchar(ch[i]);
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}