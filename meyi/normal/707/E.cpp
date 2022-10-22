#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=2010;
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
	char ch=getchar();
	while(ch!='H'&&ch!='K')ch=getchar();
	return ch;
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;

bitset<maxn>a,b;
ll c[maxn][maxn];
int k,m,n,q;
struct node{int x,y,z;};
vector<node>v[maxn];
inline void add(int x,int y,int z){
	for(ri i=x;i<=n;i+=i&-i)
		for(ri j=y;j<=m;j+=j&-j)
			c[i][j]+=z;
}
inline ll query(int x1,int y1,int x2,int y2){
	ll ret=0;
	for(ri i=x2;i;i^=i&-i){
		for(ri j=y2;j;j^=j&-j)ret+=c[i][j];
		for(ri j=y1-1;j;j^=j&-j)ret-=c[i][j];
	}
	for(ri i=x1-1;i;i^=i&-i){
		for(ri j=y2;j;j^=j&-j)ret-=c[i][j];
		for(ri j=y1-1;j;j^=j&-j)ret+=c[i][j];
	}
	return ret;
}
signed main(){
	n=qr(),m=qr(),k=qr();
	for(ri i=1;i<=k;++i){
		a.set(i);
		v[i].resize(qr());
		for(node &j:v[i])j.x=qr(),j.y=qr(),j.z=qr(),add(j.x,j.y,j.z);
	}
	q=qr();
	while(q--){
		char op=gc();
		if(op=='H')b.flip(qr());
		else{
			for(ri i=b._Find_first();i<maxn;i=b._Find_next(i)){
				for(const node &j:v[i])add(j.x,j.y,a[i]?-j.z:j.z);
				a.flip(i),b.reset(i);
			}
			ri x1=qr(),y1=qr(),x2=qr(),y2=qr();
			qw(query(x1,y1,x2,y2)),putchar(10);
		}
	}
	return 0;
}