#include<bits/stdc++.h>
#define i64 long long
#define i128 __int128
using std::max;
template<class T> inline void read(T &x){
	x=0; register char c=getchar(); register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar(); if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10); putchar(x%10+'0');
}
const int k=19,lim=1<<k,N=lim;
const i64 mod=4179340454199820289;
int n,m,q,a[N],b[N],x[N],rev[N];
i64 f[2][N],g[2][N],w[N],s[N],ans[N];
inline i64 dec(i64 a,i64 b){a-=b;return a<0?a+mod:a;}
inline i64 inc(i64 a,i64 b){a+=b;return a>=mod?a-mod:a;}
inline i64 fpow(i64 a,i64 b){i64 s=1;for(;b;b>>=1,a=(i128)a*a%mod)if(b&1)s=(i128)s*a%mod;return s;}
void DFT(i64 *a){
	for(int i=0;i<lim;i++)if(i<rev[i])std::swap(a[i],a[rev[i]]);
	for(int len=1;len<lim;len<<=1)
		for(int i=0;i<lim;i+=(len<<1))
			for(int j=0;j<len;j++){
				i64 x=a[i+j],y=(i128)a[i+j+len]*w[j+len]%mod;
				a[i+j]=inc(x,y),a[i+j+len]=dec(x,y);
				if(a[i+j]>=mod)a[i+j]-=mod;
				if(a[i+j+len]<0)a[i+j+len]+=mod;
			}	
}
void solve(){
	memset(f,0,sizeof(f));
	memset(g,0,sizeof(g));
	memset(s,0,sizeof(s));
	for(int i=1;i<=n;i++)f[0][a[i]]++;
	for(int i=1;i<n;i++)f[1][max(a[i],a[i+1])]++;
	for(int i=1;i<=m;i++)g[0][b[i]]++;
	for(int i=1;i<m;i++)g[1][max(b[i],b[i+1])]++;
	DFT(f[0]),DFT(g[0]),DFT(f[1]),DFT(g[1]);
	for(int p=0;p<2;p++)
		for(int q=0;q<2;q++)if(p^q){
			for(int i=0;i<lim;i++)s[i]=(s[i]-(i128)f[p][i]*g[q][i])%mod;
		}else{
			for(int i=0;i<lim;i++)s[i]=(s[i]+(i128)f[p][i]*g[q][i])%mod;
		}
	for(int i=0;i<lim;i++)if(s[i]<0)s[i]+=mod;
	DFT(s),std::reverse(s+1,s+lim);
	i64 invlim=fpow(lim,mod-2);
	for(int i=0;i<lim;i++)s[i]=(i128)s[i]*invlim%mod;
	for(int i=1;i<lim;i++)s[i]=inc(s[i],s[i-1]);
	// for(int i=0;i<=20;i++)printf("%lld%c",s[i]<(mod>>1)?s[i]:s[i]-mod," \n"[i==20]);
	for(int i=1;i<=q;i++)ans[i]=inc(ans[i],s[x[i]]);
	// for(int i=1;i<=q;i++)printf("%lld%c",ans[i]," \n"[i==q]);
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	for(int i=0;i<lim;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(k-1));
	for(int len=1;len<lim;len<<=1){
		i64 wn=fpow(3ll,(mod-1)/(len<<1)); w[len]=1;
		for(int i=1;i<len;i++)w[i+len]=(i128)w[i+len-1]*wn%mod;
	}
	read(n),read(m),read(q);
	for(int i=1;i<=n;i++)read(a[i]);
	for(int i=1;i<=m;i++)read(b[i]);
	for(int i=1;i<=q;i++)read(x[i]);
	for(int i=1;i<=q;i++)--x[i];
	solve();
	for(int i=1;i<=n;i++)a[i]=1e5-a[i]+1;
	for(int i=1;i<=m;i++)b[i]=1e5-b[i]+1;
	for(int i=1;i<=q;i++)ans[i]=dec(mod,ans[i]),x[i]=(2e5-x[i]+1);
	solve();
	for(int i=1;i<=q;i++)print(ans[i]<(mod>>1)?ans[i]:ans[i]-mod),putchar('\n');
}