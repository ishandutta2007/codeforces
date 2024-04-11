#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=2e5+10,maxp=510;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
#define flush() fwrite(obuf,o-obuf,1,stdout)
inline int qr(){
	ri in=0;register char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
template<class T>
void qw(T out){
	if(out>9)qw(out/10);
	putchar(out%10|48);
}
int a[maxn],ans[maxn],b[maxn],bl,bel[maxn],cnt,kbel[maxn],kcnt,kl[maxp],kr[maxp],km,m,sum[maxp],tmp[maxn],vcnt[maxn];
struct modify{
	int pos,val;
}d[maxn];
int dl;
struct query{
	int l,r,pre,id;
	inline bool operator<(const query &k){
		return bel[l]!=bel[k.l]?bel[l]<bel[k.l]:bel[r]!=bel[k.r]?bel[r]<bel[k.r]:pre<k.pre;
	}
}q[maxn];
int ql;
inline void add(int k){
	if(vcnt[k]>0&&!--tmp[vcnt[k]])--sum[kbel[vcnt[k]]];
	++vcnt[k];
	if(vcnt[k]>0&&!tmp[vcnt[k]]++)++sum[kbel[vcnt[k]]];
}
inline void del(int k){
	if(vcnt[k]>0&&!--tmp[vcnt[k]])--sum[kbel[vcnt[k]]];
	--vcnt[k];
	if(vcnt[k]>0&&!tmp[vcnt[k]]++)++sum[kbel[vcnt[k]]];
}
inline void update(int k,int id){
	if(q[id].l<=d[k].pos&&d[k].pos<=q[id].r){
		del(a[d[k].pos]);
		swap(a[d[k].pos],d[k].val);
		add(a[d[k].pos]);
	}
	else swap(a[d[k].pos],d[k].val);
}
inline int getans(){
	for(ri i=1;i<=kcnt;++i)
		if(sum[i]!=kr[i]-kl[i]+1)
			for(ri j=kl[i];j<=kr[i];++j)
				if(!tmp[j])
					return j;
}
int n,t;
int main(){
	n=qr(),t=qr();
	km=320,m=n/cbrt(n);
	for(ri i=1;i<=100001;++i){
		if(i%km==1)kr[kcnt]=i-1,kl[++kcnt]=i;
		kbel[i]=kcnt;
	}
	kr[kcnt]=100001;
	for(ri i=1;i<=n;++i){
		b[i]=a[i]=qr();
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	bl=n;
	for(ri i=1;i<=t;++i){
		ri op=qr(),x=qr(),y=qr();
		if(op&1)++ql,q[ql]={x,y,dl,ql};
		else b[++bl]=y,d[++dl]={x,y};
	}
	sort(b+1,b+bl+1);
	bl=unique(b+1,b+bl+1)-b-1;
	for(ri i=1;i<=n;++i)a[i]=lower_bound(b+1,b+bl+1,a[i])-b;
	for(ri i=1;i<=dl;++i)d[i].val=lower_bound(b+1,b+bl+1,d[i].val)-b;
	sort(q+1,q+ql+1);
	ri now=0,pl=1,pr=0;
	for(ri i=1;i<=ql;++i){
		while(pl<q[i].l)del(a[pl++]);
		while(pl>q[i].l)add(a[--pl]);
		while(pr<q[i].r)add(a[++pr]);
		while(pr>q[i].r)del(a[pr--]);
		while(now<q[i].pre)update(++now,i);
		while(now>q[i].pre)update(now--,i);
		ans[q[i].id]=getans();
	}
	for(ri i=1;i<=ql;++i)qw(ans[i]),putchar(10);
	flush();
	return 0;
}