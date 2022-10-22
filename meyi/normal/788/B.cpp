#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
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
struct dsu{
	int fa[maxn],siz[maxn];
	int find(int k){return k==fa[k]?k:fa[k]=find(fa[k]);}
	inline bool merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
			return true;
		}
		return false;
	}
}d;
int cnt,deg[maxn],m,n,tot;
int main(){
	n=qr(),m=qr();
	for(ri i=1,x,y;i<=m;++i){
		x=qr(),y=qr();
		if(!d.fa[x])d.fa[x]=x,d.siz[x]=1;
		if(!d.fa[y])d.fa[y]=x,d.siz[y]=1;
		if(x==y)++cnt;
		else d.merge(x,y),++deg[x],++deg[y];
	}
	for(ri i=1;i<=n;++i)
		if(d.find(i)==i)
			++tot;
	if(tot>1)return putchar(48),0;
	ll ans=1ll*cnt*(cnt-1)/2+1ll*cnt*(m-cnt);
	for(ri i=1;i<=n;++i)ans+=1ll*deg[i]*(deg[i]-1)/2;
	printf("%lld",ans);
	return 0;
}