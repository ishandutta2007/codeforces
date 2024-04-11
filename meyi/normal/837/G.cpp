#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=75010,mx=1e9+1;
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
typedef pair<ll,ll> pll;
#define fi first
#define se second
struct segment_tree{
	int ls,rs;
	pll v;
}t[maxn<<6];
int cnt;
void insert(int &p,int l,int r,int k,int x,int y){
	t[++cnt]=t[p];
	p=cnt;
	if(l==r){
		t[p].v.fi+=x,t[p].v.se+=y;
		return;
	}
	ri mid=l+r>>1;
	k<=mid?insert(t[p].ls,l,mid,k,x,y):insert(t[p].rs,mid+1,r,k,x,y);
	t[p].v.fi=t[t[p].ls].v.fi+t[t[p].rs].v.fi,t[p].v.se=t[t[p].ls].v.se+t[t[p].rs].v.se;
}
pll ans;
void query(int p1,int p2,int l,int r,int k){
	if(r<=k){
		ans.fi+=t[p2].v.fi-t[p1].v.fi,ans.se+=t[p2].v.se-t[p1].v.se;
		return;
	}
	ri mid=l+r>>1;
	query(t[p1].ls,t[p2].ls,l,mid,k);
	if(k>mid)query(t[p1].rs,t[p2].rs,mid+1,r,k);
}
int m,n,rt[maxn];
ll lst,pre[maxn];
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		ri x1=qr(),x2=qr(),y1=qr(),a=qr(),b=qr(),y2=qr();
		pre[i]=pre[i-1]+y1;
		rt[i]=rt[i-1];
		insert(rt[i],0,mx,x1+1,a,b-y1);
		insert(rt[i],0,mx,x2+1,-a,y2-b);
	}
	m=qr();
	while(m--){
		ri l=qr(),r=qr(),x=(qr()+lst)%(mx-1);
		ans={0,0};
		query(rt[l-1],rt[r],0,mx,x);
		qw(lst=pre[r]-pre[l-1]+ans.fi*x+ans.se),putchar(10);
	}
	return 0;
}