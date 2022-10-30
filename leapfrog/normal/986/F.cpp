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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
int wt,ln[55],qu[1000005];ll q[55],vl[55][105],ds[55][500005];char vs[500005];
const int N=31622779;int pr[1951959],pc;char pv[N];//prinit{{{
inline void prinit(int n=N-1)
{
	pv[1]=1;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++) {pv[i*pr[j]]=1;if(i%pr[j]==0) break;}
	}
}//}}}
inline int ksm(int x,int q,int P) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline char chk(ll a,ll b,ll v)
{
	if(1.0L*a*b-a-b<v) return 1;//ax+by=v,by%a=v%a
	if(a==2) return v%2==0||((b&1)&&v>=b);//y=v*(b^-)%a
	ll y=1ll*v%a*ksm(b%a,a-2,a)%a,x=(v-b*y)/a;
	if(a*x+b*y!=v) return 0;else return x>=0;
}
inline void init(ll b)
{
	++wt;ll *f=vl[wt],*d=ds[wt];q[wt]=b;
	for(register int i=1;1ll*pr[i]*pr[i]<=b;i++)
		if(b%pr[i]==0) {f[++ln[wt]]=pr[i];while(b%pr[i]==0) b/=pr[i];}
	int hd=1,tl=1;if(b!=1) f[++ln[wt]]=b;
	if(ln[wt]<=2) return;else memset(vs,0,f[1]+1),sort(f+1,f+ln[wt]+1);
	int P=f[1];memset(d,0x3f,(P+1)<<4),d[0]=0,qu[1]=0;
	//for(int i=1;i<=ln[wt];i++) printf("%lld%c",f[i],i==ln[wt]?'\n':' ');
	while(hd<=tl)
	{
		int x=qu[hd++];vs[x]=0;
		for(int i=2;i<=ln[wt];i++)
		{
			int y=(x+f[i])%P;if(d[y]>d[x]+f[i])
				{d[y]=d[x]+f[i];if(!vs[y]) vs[y]=1,qu[++tl]=y;}
		}
	}
	//for(int i=0;i<P;i++) printf("%lld%c",d[i],i==P-1?'\n':' ');
}
inline void solve()
{
	ll a,b,*f,*d;read(a),read(b);int n=0;if(b==1) return puts("NO"),void();
	for(int i=1;i<=wt;i++) if(q[i]==b) f=vl[i],n=ln[i],d=ds[i];
	if(!n) init(b),n=ln[wt],d=ds[wt],f=vl[wt];
	if(n==1) return puts(a%b==0?"YES":"NO"),void();
	if(n==2) return puts(chk(f[1],f[2],a)?"YES":"NO"),void();
	//for(int i=0;i<f[1];i++) printf("%lld%c",d[i],i==f[1]-1?'\n':' ');
	int P=f[1];if(d[a%P]<=a) puts("YES");else puts("NO");
}
int main() {int Ca;for(prinit(),read(Ca);Ca--;) solve();return 0;}