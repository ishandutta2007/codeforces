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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
int a[maxn],ans[maxn],c[maxn],m,n,pos[maxn];
vector<int>add[maxn];
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)pos[a[i]=qr()]=i;
	for(ri i=1;i<=m;++i){
		ri l=qr(),r=qr();
		q[r].emplace_back(l,i);
	}
	for(ri i=1;i<=n;++i)
		for(ri j=i;j<=n;j+=i)
			add[max(pos[i],pos[j])].push_back(min(pos[i],pos[j]));
	for(ri i=1;i<=n;++i){
		#define lowbit(k) (k&-k)
		for(ri j:add[i])
			for(ri k=j;k<=n;k+=lowbit(k))
				++c[k];
		ri sum=0;
		for(ri k=i;k;k^=lowbit(k))sum+=c[k];
		for(const pii &j:q[i]){
			ans[j.se]=sum;
			for(ri k=j.fi-1;k;k^=lowbit(k))ans[j.se]-=c[k];
		}
	}
	for(ri i=1;i<=m;++i)qw(ans[i]),putchar(10);
	return 0;
}