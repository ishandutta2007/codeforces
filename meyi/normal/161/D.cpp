#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct edge{
	int to,nxt;
}e[maxn<<1];
int len,hd[maxn];
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
int fa[maxn],mx[maxn],rt,siz[maxn],son[maxn],tot;
bool vis[maxn];
void calcsz(int now,int f){
	mx[now]=0;
	siz[now]=1;
	for(ri i=hd[now];i;i=e[i].nxt){
		ri nxt=e[i].to;
		if(vis[nxt]||nxt==f)continue;
		calcsz(nxt,now);
		mx[now]=max(mx[now],siz[nxt]);
		siz[now]+=siz[nxt];
	}
	mx[now]=max(mx[now],tot-siz[now]);
	if(mx[now]<mx[rt])rt=now;
}
ll cnt[maxn];
int dis[maxn],k;
void calcdis(int now,int f){
	if(dis[now]>k)return;
	++cnt[dis[now]];
	for(ri i=hd[now];i;i=e[i].nxt){
		ri nxt=e[i].to;
		if(vis[nxt]||nxt==f)continue;
		dis[nxt]=dis[now]+1;
		calcdis(nxt,now);
	}
}
ll ans;
void calcans(int now,int len,int sign){
	memset(cnt,0,sizeof(ll)*(k+1));
	dis[now]=len;
	calcdis(now,0);
	ll ret=0;
	for(ri i=0;i<k-i;++i)ret+=cnt[i]*cnt[k-i];
	if(k%2==0)ret+=cnt[k>>1]*(cnt[k>>1]-1)>>1;
	ans+=ret*sign;
}
int n;
void dfs(int now){
	vis[now]=true;
	calcans(now,0,1);
	for(ri i=hd[now];i;i=e[i].nxt){
		ri nxt=e[i].to;
		if(vis[nxt])continue;
		calcans(nxt,1,-1);
		mx[rt=0]=n,tot=siz[nxt];
		calcsz(nxt,now);
		dfs(rt);
	}
}
int main(){
	n=qr(),k=qr();
	for(ri i=1;i<n;++i){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	mx[rt=0]=tot=n;
	calcsz(1,0);
	dfs(rt);
	printf("%lld",ans);
	return 0;
}