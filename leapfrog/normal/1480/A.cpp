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
const int N=1000005;int T,n,m,K,a[N];char c[N];
struct edge{int to,nxt;}e[N<<1];int et,head[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void solve()
{
	scanf("%s",c+1),n=strlen(c+1);
	for(int i=1;i<=n;i++) if(i&1) putchar(c[i]=='a'?'b':'a');else putchar(c[i]=='z'?'y':'z');
	putchar('\n');
}
int main() {for(read(T);T--;) solve();return 0;}