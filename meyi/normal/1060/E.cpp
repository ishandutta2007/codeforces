#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
struct edge{
	int to,nxt;
}e[maxn<<1];
int hd[maxn],len;
inline void addedge(int fr,int to){
	e[++len]={to,hd[fr]};
	hd[fr]=len;
}
ll ans,sum[maxn][2];
int cnt[maxn][2],n;
void dfs(int p,int fa){
	cnt[p][0]=1;
	for(ri i=hd[p];i;i=e[i].nxt)
		if(e[i].to!=fa){
			dfs(e[i].to,p);
			ans+=cnt[p][1]*sum[e[i].to][0]+cnt[e[i].to][0]*sum[p][1]+1ll*cnt[p][1]*cnt[e[i].to][0];
			ans+=cnt[p][0]*sum[e[i].to][0]+cnt[e[i].to][0]*sum[p][0]+1ll*cnt[p][0]*cnt[e[i].to][0];
			ans+=cnt[p][1]*sum[e[i].to][1]+cnt[e[i].to][1]*sum[p][1]+2ll*cnt[p][1]*cnt[e[i].to][1];
			ans+=cnt[p][0]*sum[e[i].to][1]+cnt[e[i].to][1]*sum[p][0]+1ll*cnt[p][0]*cnt[e[i].to][1];
			cnt[p][0]+=cnt[e[i].to][1],cnt[p][1]+=cnt[e[i].to][0];
			sum[p][0]+=sum[e[i].to][1]+cnt[e[i].to][1],sum[p][1]+=sum[e[i].to][0];
		}
}
int main(){
	n=qr();
	for(ri i=1;i<n;++i){
		ri x=qr(),y=qr();
		addedge(x,y),addedge(y,x);
	}
	dfs(1,0);
	printf("%lld",ans);
	return 0;
}