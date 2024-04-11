#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[maxn],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,maxn,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
inline char gc(){
	char ch;
	while(ch=getchar(),ch!='s'&&ch!='h'&&ch!='\n');
	return ch;
}
ll ans,sum;
int id[maxn],n,x[maxn],y[maxn];
char s[maxn];
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		id[i]=i;
		for(char ch;(ch=gc())!='\n';){
			if(ch=='s')++x[i];
			else ans+=x[i],++y[i];
		}
	}
	sort(id+1,id+n+1,[&](int u,int v){return 1ll*x[u]*y[v]>1ll*x[v]*y[u];});
	for(ri i=1;i<=n;++i)ans+=sum*y[id[i]],sum+=x[id[i]];
	printf("%lld",ans);
	return 0;
}