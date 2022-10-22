#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxd=3,maxn=1e5+10;
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
inline void ps(const T &s,char ed=10){
	for(const char &ch:s)if(ch)putchar(ch);
	putchar(ed);
}
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct point{
	int v[maxd];
	inline int operator[](int k)const{return v[k];}
	inline int& operator[](int k){return v[k];}
}a[maxn],tmp[2],_tmp[2];
struct node{
	int ls,rs;
	point mn,mx,v;
}t[maxn];
inline void push_up(int p){
	t[p].mn=t[p].mx=t[p].v;
	for(ri i=0;i<maxd;++i){
		if(t[p].ls)ckmin(t[p].mn[i],t[t[p].ls].mn[i]),ckmax(t[p].mx[i],t[t[p].ls].mx[i]);
		if(t[p].rs)ckmin(t[p].mn[i],t[t[p].rs].mn[i]),ckmax(t[p].mx[i],t[t[p].rs].mx[i]);
	}
}
int cnt;
#define nxt(d) (d+1==maxd?0:d+1)
void build(int &p,int l,int r,int d){
	if(l>r)return;
	ri mid=l+r>>1;
	nth_element(a+l,a+mid+1,a+r,[&](const auto &x,const auto &y){return x[d]<y[d];});
	t[p=++cnt].v=a[mid];
	build(t[p].ls,l,mid-1,nxt(d));
	build(t[p].rs,mid+1,r,nxt(d));
	push_up(p);
}
inline bool est(int p){
	if(!p)return false;
	for(ri i=0;i<maxd;++i)
		if(t[p].mx[i]<tmp[0][i]||tmp[1][i]<t[p].mn[i])
			return false;
	return true;
}
inline bool in(int p){
	for(ri i=0;i<maxd;++i)
		if(t[p].v[i]<tmp[0][i]||tmp[1][i]<t[p].v[i])
			return false;
	return true;
}
bool query(int p){
	return est(p)&&(in(p)||query(t[p].ls)||query(t[p].rs));
}
int m,n,q,rt;
int main(){
	qr(),qr(),qr();
	n=qr(),m=qr(),q=qr();
	for(ri i=0;i<maxd;++i)tmp[0][i]=114514;
	while(n--)
		for(ri i=0,x;i<maxd;++i){
			x=qr();
			ckmin(tmp[0][i],x);
			ckmax(tmp[1][i],x);
		}
	for(ri i=1;i<=m;++i)
		for(ri j=0;j<maxd;++j)
			a[i][j]=qr();
	build(rt,1,m,0);
	if(query(rt))return ps("INCORRECT"),0;
	ps("CORRECT");
	while(q--){
		for(ri i=0;i<maxd;++i)t[m+1].v[i]=qr();
		if(in(m+1))ps("OPEN");
		else{
			memcpy(_tmp,tmp,sizeof tmp);
			for(ri i=0;i<maxd;++i)ckmin(tmp[0][i],t[m+1].v[i]),ckmax(tmp[1][i],t[m+1].v[i]);
			if(query(rt))ps("CLOSED");
			else ps("UNKNOWN");
			memcpy(tmp,_tmp,sizeof tmp);
		}
	}
	return 0;
}