#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int cnt,lim,m,n,to[maxn],x[maxn],y[maxn],z[maxn];
vector<int>pt[maxn];
bool vis[maxn],tag[maxn];
inline void solve(){
	for(ri i=1;i<=cnt;++i){
		if(x[i]&1)tag[to[y[i]]]=tag[to[z[i]]]=true;
		else tag[y[i]]=true;
	}
	for(ri i=1;i<=n;++i)
		if(tag[i])
			for(ri j=i;;){
				pt[i].push_back(j);
				j=to[j];
				if(tag[j])break;
			}
	for(ri i=1;i<=cnt;++i)
		if(x[i]&1)swap(to[y[i]],to[z[i]]);
		else{
			ri ans=-1,ring=0;
			for(ri j=y[i];!vis[j];j=to[pt[j].back()]){
				ring+=pt[j].size();
				vis[j]=true;
			}
			z[i]%=ring;
			for(ri j=y[i];vis[j];j=to[pt[j].back()]){
				if(ans==-1&&pt[j].size()>z[i])ans=pt[j][z[i]];
				z[i]-=pt[j].size();
				vis[j]=false;
			}
			qw(ans),putchar(10);
		}
	for(ri i=1;i<=cnt;++i){
		if(x[i]&1){
			pt[to[y[i]]]=pt[to[z[i]]]={};
			tag[to[y[i]]]=tag[to[z[i]]]=false;
		}
		else pt[y[i]]={},tag[y[i]]=false;
	}
	cnt=0;
}
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)to[i]=qr();
	lim=round(sqrt(m));
	while(m--){
		++cnt;
		x[cnt]=qr(),y[cnt]=qr(),z[cnt]=qr();
		if(cnt%lim==0)solve();
	}
	if(cnt)solve();
	return 0;
}