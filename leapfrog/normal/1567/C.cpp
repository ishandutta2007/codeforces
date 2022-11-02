//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
char ch[114514];int n;ll rs=0;
inline void pt() {for(int i=1;i<=n;i++) printf("%d%c",ch[i],i==n?'\n':' ');}
inline void dfs(int x,ll ti)
{
	if(x==0) return rs+=ti,void();else if(!ti) return;
	int c1=0;for(int i=0;i<10;i++) for(int j=0;j<10;j++) if(i+j==ch[x]) c1++;
	dfs(x-1,1ll*c1*ti);if(x-2<1) return;else c1=0;
	//printf("%d\n",x),pt();
	ch[x-2]--;int i;for(i=x-2;i>1&&ch[i]<0;i-=2) ch[i]+=10,ch[i-2]--;
	//printf("! %d\n",x),pt();
	if(i<1||(i==1&&ch[i]<0)) {for(;i<x-2;i+=2) ch[i]++,ch[i+2]-=10;ch[x-2]++;return;}
	for(int a=0;a<10;a++) for(int b=0;b<10;b++) if(a+b==ch[x]+10) c1++;
	dfs(x-1,1ll*c1*ti),ch[x-2]++;for(;i<x-2;i+=2) ch[i]++,ch[i+2]-=10;
	//printf("? %d\n",x),pt();
}
inline void solve()
{
	scanf("%s",ch+1),n=strlen(ch+1);
	for(int i=1;i<=n;i++) ch[i]^=48;
	rs=0,dfs(n,1),printf("%lld\n",rs-2);
}
int main() {int Ca;for(read(Ca);Ca--;) solve();return 0;}