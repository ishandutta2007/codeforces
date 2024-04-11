//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(!(c^45)) f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x,1:1;
}
struct pamn{int fa,len,dep;}pm[2000005];int pmt,pls;
struct edge{int to,w,nxt;}e[2000005];int et,head[2000005];
const int P=51123987;char c[2000005];int n;int ed[2000005];
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
inline int getc(int x,int c) {for(int i=head[x];i;i=e[i].nxt) if(e[i].w==c) return e[i].to;return 0;}
inline void paminit() {pmt=pls=2,pm[1].fa=pm[2].fa=1,pm[1].len=-1;}
inline void pamins(int wh,int c,char *s)
{
	int p=pls;for(;s[wh]^s[wh-pm[p].len-1];p=pm[p].fa);
	int ch=getc(p,c);if(ch) return pls=ch,void();
	int np=pls=++pmt,ph=pm[p].fa;pm[np].len=pm[p].len+2;
	for(;s[wh]^s[wh-pm[ph].len-1];ph=pm[ph].fa);
	int gg=getc(ph,c);pm[np].fa=gg?gg:2,head[np]=0;
	adde(p,np,c),pm[np].dep=pm[pm[np].fa].dep+1;
}
int main()
{
	read(n),scanf("%s",c+1),paminit(),c[0]=-1;ll qwq=0;
	for(int i=1;i<=n;i++) pamins(i,c[i]-='a',c),qwq+=(ed[i]=pm[pls].dep);
	for(int i=1;i<=n;i++) (ed[i]+=ed[i-1])%=P;
	qwq=(qwq&1?(qwq-1)/2%P*(qwq%P)%P:qwq/2%P*((qwq-1)%P)%P);
	reverse(c+1,c+n+1),reverse(ed+1,ed+n+1),paminit();
	for(int i=1;i<=n;i++) pamins(i,c[i],c),(qwq-=1ll*ed[i+1]*pm[pls].dep%P)%=P;
	return printf("%lld\n",(qwq%P+P)%P),0;
}