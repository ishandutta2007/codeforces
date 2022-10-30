//
#include<bits/stdc++.h>
#define ri register
using namespace std;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
struct edge{int to,nxt;}e[1000005];const int P=1e9+7;
int n,et,head[1000005],we[1000005],num[1000005],f[1000005];long long v[1000005],sm=0;
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs(int x) {for(int i=head[x];i;i=e[i].nxt) dfs(e[i].to),v[x]+=v[e[i].to];}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(v[i]),sm+=v[i];
	for(int i=2,f;i<=n;i++) read(f),adde(f,i);
	dfs(1);for(int i=1;i<=n;i++) if(sm/__gcd(sm,v[i])<=n) num[sm/__gcd(sm,v[i])]++;
	for(int i=1;i<=n;i++) if(num[i]) for(int j=i;j<=n;j+=i) f[j]=(f[j]+num[i])%P;
	int res=0;for(int i=1;i<=n;i++) f[i]=(f[i]==i);
	for(int i=n;i>1;i--) if(f[i]) {for(int j=i+i;j<=n;j+=i) (f[i]+=f[j])%=P;res=(res+f[i])%P;}
	return printf("%d\n",res+1),0;//why the ALL is the only special way?
}