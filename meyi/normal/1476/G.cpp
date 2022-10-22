#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
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
int a[maxn],ans[maxn],bel[maxn],cnt[maxn],cnt2[maxn],dl,ele[maxn],len,m,n,pos[maxn],ql,tot,v[maxn];
inline void insert(int k){ele[++len]=k,pos[k]=len;}
inline void erase(int k){if(pos[k]==len)--len;else pos[ele[len]]=pos[k],ele[pos[k]]=ele[len--];}
inline void add2(int k){if(!cnt2[k]++)insert(k);++tot;}
inline void del2(int k){if(!--cnt2[k])erase(k);--tot;}
inline void add(int k){if(cnt[k])del2(cnt[k]);add2(++cnt[k]);}
inline void del(int k){del2(cnt[k]);if(--cnt[k])add2(cnt[k]);}
struct mdf{int pos,val;}d[maxn];
struct qry{
	int l,r,k,pre,id;
	inline bool operator<(const qry &k)const{return bel[l]!=bel[k.l]?l<k.l:bel[r]!=bel[k.r]?r<k.r:pre<k.pre;}
}q[maxn];
inline void update(int k,int id){
	if(q[id].l<=d[k].pos&&d[k].pos<=q[id].r)del(a[d[k].pos]);
	swap(d[k].val,a[d[k].pos]);
	if(q[id].l<=d[k].pos&&d[k].pos<=q[id].r)add(a[d[k].pos]);
}
signed main(){
	n=qr(),m=qr();
	ri B=cbrt(1ll*n*m);
	for(ri i=1,j=0;i<=n;++i){
		a[i]=qr();
		if(++j==B)++*bel,j=0;
		bel[i]=*bel;
	}
	for(ri i=1;i<=m;++i){
		if(qr()&1)ans[++ql]=-1,q[ql].l=qr(),q[ql].r=qr(),q[ql].k=qr(),q[ql].pre=dl,q[ql].id=ql;
		else ++dl,d[dl].pos=qr(),d[dl].val=qr();
	}
	sort(q+1,q+ql+1);
	ri now=0,pl=1,pr=0;
	for(ri i=1;i<=ql;++i){
		while(pl>q[i].l)add(a[--pl]);
		while(pr<q[i].r)add(a[++pr]);
		while(pl<q[i].l)del(a[pl++]);
		while(pr>q[i].r)del(a[pr--]);
		while(now<q[i].pre)update(++now,i);
		while(now>q[i].pre)update(now--,i);
		if(tot<q[i].k)continue;
		ans[q[i].id]=INT_MAX;
		memcpy(v+1,ele+1,len<<2);
		sort(v+1,v+len+1);
		for(ri i_=1,j=1,l=cnt2[v[1]];i_<=len;){
			while(j<len&&l<q[i].k)l+=cnt2[v[++j]];
			if(l<q[i].k)break;
			ckmin(ans[q[i].id],v[j]-v[i_]);
			l-=cnt2[v[i_++]];
		}
	}
	for(ri i=1;i<=ql;++i){
		if(~ans[i])qw(ans[i]);
		else putchar('-'),putchar(49);
		putchar(10);
	}
	return 0;
}