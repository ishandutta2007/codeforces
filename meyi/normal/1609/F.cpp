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
inline ll qr(){
	ll in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
ll a[maxn],ans;
int c[maxn],n,st1[maxn],st2[maxn],tp1,tp2;
bool b[maxn];
#define lowbit(k) (k&-k)
struct BIT{
	int c1[maxn],c2[maxn];
	inline void clear(){
		::clear(c1,n),::clear(c2,n);
	}
	inline void add(int l,int r,int v){
		for(ri i=l;i<=n;i+=lowbit(i))c1[i]+=v,c2[i]+=(l-1)*v;
		for(ri i=r+1;i<=n;i+=lowbit(i))c1[i]-=v,c2[i]-=r*v;
	}
	inline int query(int l,int r){
		int ret=0;
		for(ri i=r;i;i^=lowbit(i))ret+=r*c1[i]-c2[i];
		for(ri i=l-1;i;i^=lowbit(i))ret-=(l-1)*c1[i]-c2[i];
		return ret;
	}
}t[2];
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)c[i]=__builtin_popcountll(a[i]=qr());
	for(ri i=0;i<60;++i){
		int cnt=0;
		for(ri j=1;j<=n;++j){
			b[j]=(c[j]==i);
			while(tp1&&a[st1[tp1]]<=a[j]){
				if(b[st1[tp1]])cnt-=t[0].query(st1[tp1-1]+1,st1[tp1]),t[1].add(st1[tp1-1]+1,st1[tp1],-1);
				--tp1;
			}
			if(b[j]){
				cnt+=t[0].query(st1[tp1]+1,j);
				t[1].add(st1[tp1]+1,j,1);
			}
			st1[++tp1]=j;
			while(tp2&&a[st2[tp2]]>=a[j]){
				if(b[st2[tp2]])cnt-=t[1].query(st2[tp2-1]+1,st2[tp2]),t[0].add(st2[tp2-1]+1,st2[tp2],-1);
				--tp2;
			}
			if(b[j]){
				cnt+=t[1].query(st2[tp2]+1,j);
				t[0].add(st2[tp2]+1,j,1);
			}
			st2[++tp2]=j;
			ans+=cnt;
		}
		t[0].clear(),t[1].clear();
		tp1=tp2=0;
	}
	printf("%lld",ans);
	return 0;
}