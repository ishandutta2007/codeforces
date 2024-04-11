#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=25e4+10;
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
struct edge{
	int v,to;
	inline edge(int v_=0,int to_=0):v(v_),to(to_){}
};
#define eb emplace_back
#define SZ(k) (k.size())
vector<edge>e[maxn];
inline bool operator<(const edge &x,const edge &y){
	return SZ(e[x.to])<SZ(e[y.to]);
}
vector<int>deg[maxn];
int lim,n,now[maxn],vis[maxn];
ll ans,f[2][maxn],sum[maxn];
multiset<ll>h[maxn];
void dfs(int p,int fa){
	vis[p]=lim;
	for(;now[p]<SZ(e[p])&&SZ(e[e[p][now[p]].to])<=lim;++now[p]){
		sum[p]+=e[p][now[p]].v;
		h[p].insert(e[p][now[p]].v);
	}
	while(SZ(h[p])>SZ(e[p])-lim){
		auto it=--h[p].end();
		sum[p]-=*it;
		h[p].erase(it);
	}
	ll res=0;
	for(ri i=now[p];i<SZ(e[p]);++i)
		if(e[p][i].to!=fa){
			dfs(e[p][i].to,p);
			res+=f[0][e[p][i].to];
			ll tmp=f[1][e[p][i].to]+e[p][i].v-f[0][e[p][i].to];
			sum[p]+=tmp;
			h[p].insert(tmp);
		}
	auto it=--h[p].end();
	for(ri i=SZ(h[p]);i>SZ(e[p])-lim;--i,--it){
		if(*it<=0)break;
		res-=*it;
	}
	f[0][p]=sum[p]+res;
	f[1][p]=sum[p]+res-max(0ll,*it);
	for(ri i=now[p];i<SZ(e[p]);++i)
		if(e[p][i].to!=fa){
			ll tmp=f[1][e[p][i].to]+e[p][i].v-f[0][e[p][i].to];
			sum[p]-=tmp;
			h[p].erase(h[p].find(tmp));
		}
}
int main(){
	n=qr();
	for(ri i=1,x,y,z;i<n;++i){
		x=qr(),y=qr(),z=qr();
		e[x].eb(z,y),e[y].eb(z,x);
		ans+=z;
	}
	qw(ans);
	for(ri i=1;i<=n;++i){
		sort(e[i].begin(),e[i].end());
		for(ri j=1;j<SZ(e[i]);++j)deg[j].eb(i);
	}
	for(lim=1;lim<n;++lim){
		if(ans){
			ans=0;
			for(ri i=0;i<SZ(deg[lim]);++i)
				if(vis[deg[lim][i]]<lim)
					dfs(deg[lim][i],0),ans+=f[0][deg[lim][i]];
		}
		putchar(32),qw(ans);
	}
	fwrite(obuf,o-obuf,1,stdout);
	return 0;
}