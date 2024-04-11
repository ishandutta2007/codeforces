#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e6+10;
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
int a[maxn],ans[maxn],c[maxn],m,n;
unordered_map<int,int>lst;
typedef pair<int,int> pii;
#define fi first
#define se second
vector<pii>q[maxn];
int main(){
	n=qr();
	for(ri i=1;i<=n;++i)a[i]=qr();
	m=qr();
	for(ri i=1;i<=m;++i){
		ri l=qr(),r=qr();
		q[r].emplace_back(l,i);
	}
	#define lowbit(k) (k&-k)
	for(ri i=1;i<=n;++i){
		ri &pre=lst[a[i]];
		if(pre)for(ri j=pre;j<=n;j+=lowbit(j))c[j]^=a[i];
		pre=i;
		ri sum=0;
		for(ri j=i;j;j^=lowbit(j))sum^=c[j];
		for(const pii &j:q[i]){
			ans[j.se]=sum;
			for(ri k=j.fi-1;k;k^=lowbit(k))ans[j.se]^=c[k];
		}
	}
	for(ri i=1;i<=m;++i)qw(ans[i]),putchar(10);
	return 0;
}