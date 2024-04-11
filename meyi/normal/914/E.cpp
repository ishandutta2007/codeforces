#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
inline char gc(){
	char ch;
	while(!islower(ch=getchar()));
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int mx[maxn],rt,siz[maxn],tot;
bool vis[maxn];
inline void calc_siz(int p,int f){
	mx[p]=0,siz[p]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]&&e[i].to!=f){
			calc_siz(e[i].to,p);
			ckmax(mx[p],siz[e[i].to]);
			siz[p]+=siz[e[i].to];
		}
	ckmax(mx[p],tot-siz[p]);
	if(mx[p]<mx[rt])rt=p;
}
ll ans[maxn],sum[maxn];
int id[maxn];
char s[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
inline int my_hash(int k){return (1145141ll*k+67942)&2097151;}
inline int my_hash(const pii &k){return (1145141ll*k.fi+k.se+67942)&2097151;}
template<class T>
struct hmap{
	struct data{
		T id;
		int val,nxt;
	}d[maxn];
	int cnt,hd[1<<21],len,vis[1<<21];
	inline void clear(){++cnt,len=0;}
	inline void add(const T &p){
		ri tmp=my_hash(p);
		if(vis[tmp]!=cnt)hd[tmp]=0,vis[tmp]=cnt;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p){
				++d[i].val;
				return;
			}
		d[++len]={p,1,hd[tmp]};
		hd[tmp]=len;
	}
	inline int query(const T &p){
		ri tmp=my_hash(p);
		if(vis[tmp]!=cnt)hd[tmp]=0,vis[tmp]=cnt;
		for(ri i=hd[tmp];i;i=d[i].nxt)
			if(d[i].id==p)
				return d[i].val;
		return 0;
	}
};
hmap<int>all;
hmap<pii>sub;
inline void calc_ans(){
	all.clear(),sub.clear();
	for(ri i=hd[rt],j=0;i;i=e[i].nxt)
		if(!vis[e[i].to]){
			function<void(int,int,int)>calc_dis=[&](int p,int f,int b){
				b^=1<<s[p];
				all.add(b),sub.add({j,b});
				for(ri i=hd[p];i;i=e[i].nxt)
					if(!vis[e[i].to]&&e[i].to!=f)
						calc_dis(e[i].to,p,b);
			};
			calc_dis(e[i].to,rt,0);
			++j;
		}
	sum[rt]=0;
	for(ri i=hd[rt],j=0;i;i=e[i].nxt)
		if(!vis[e[i].to]){
			function<void(int,int,int)>calc_sum=[&](int p,int f,int b){
				sum[p]=0;
				b^=1<<s[p];
				for(ri i=-1;i<20;++i){
					ri x=(i==-1?0:(1<<i)),y=all.query(b^x)-sub.query({j,b^x});
					if(b==x)++ans[rt],--sum[rt],++sum[p];
					sum[p]+=y;
				}
				for(ri i=hd[p];i;i=e[i].nxt)
					if(!vis[e[i].to]&&e[i].to!=f)
						calc_sum(e[i].to,p,b),sum[p]+=sum[e[i].to];
				ans[p]+=sum[p];
			};
			calc_sum(e[i].to,rt,1<<s[rt]);
			sum[rt]+=sum[e[i].to];
			++j;
		}
	ans[rt]+=sum[rt]>>1;
}
void dfs(int p){
	vis[p]=true;
	calc_ans();
	for(ri i=hd[p];i;i=e[i].nxt)
		if(!vis[e[i].to]){
			rt=0,tot=siz[e[i].to];
			calc_siz(e[i].to,p);
			dfs(rt);
		}
}
int n;
int main(){
	n=qr();
	for(ri i=1;i<n;++i){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	for(ri i=1;i<=n;++i)s[i]=gc()-'a';
	mx[0]=INT_MAX,tot=n;
	calc_siz(1,0);
	dfs(rt);
	for(ri i=1;i<=n;++i)qw(ans[i]+1),putchar(32);
	return 0;
}