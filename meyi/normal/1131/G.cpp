#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=1e7+10,maxn=25e4+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>a[maxn];
int cnt,fa[maxm],h[maxm],l[maxm],m,n,r[maxm],st[maxm],tp;
ll f[maxm],g[maxm],w[maxm];
int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
int main(){
	n=qr(),qr();
	for(ri i=1;i<=n;++i){
		a[i].resize(qr());
		for(auto &j:a[i])j.fi=qr();
		for(auto &j:a[i])j.se=qr();
	}
	m=qr();
	while(m--){
		ri x=qr(),y=qr();
		for(auto i:a[x])++cnt,h[cnt]=i.fi,w[cnt]=1ll*i.se*y;
	}
	m=cnt;
	for(ri i=1;i<=m;++i){
		while(tp&&i-h[i]+1<=st[tp]-h[st[tp]]+1)--tp;
		if(!tp||i-h[i]+1>st[tp])l[i]=max(i-h[i]+1,1);
		else l[i]=l[st[tp]];
		st[++tp]=i;
	}
	tp=0;
	for(ri i=m;i;--i){
		while(tp&&i+h[i]-1>=st[tp]+h[st[tp]]-1)--tp;
		if(!tp||i+h[i]-1<st[tp])r[i]=min(i+h[i]-1,m);
		else r[i]=r[st[tp]];
		st[++tp]=i;
	}
	for(ri i=1;i<=m;++i)fa[i]=i;
	g[tp=0]=1e18;
	for(ri i=1;i<=m;++i){
		while(tp&&r[st[tp]]<i)--tp;
		g[i]=min(g[st[tp]],f[i-1]+w[i]);
		f[i]=min(g[i],f[l[i]-1]+w[i]);
		st[++tp]=i;
	}
	printf("%lld",f[m]);
	return 0;
}