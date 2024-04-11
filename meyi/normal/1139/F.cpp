#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxn=1e5+10;
static char pbuf[1000000],*p1=pbuf,*p2=pbuf,obuf[1000000],*o=obuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define putchar(x) (o-obuf<1000000)?(*o++=(x)):(fwrite(obuf,o-obuf,1,stdout),o=obuf,*o++=(x))
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
struct flusher{~flusher(){fwrite(obuf,o-obuf,1,stdout);}}autoflush;
struct discretize{
	int b[maxn*3],bl;
	inline void insert(int k){
		b[++bl]=k;
	}
	inline void init(){
		sort(b+1,b+bl+1);
		bl=unique(b+1,b+bl+1)-b-1;
	}
	inline int query(int k){
		return lower_bound(b+1,b+bl+1,k)-b;
	}
}b1,b2,b3;
// b1: bi prefj
// b2: bi+pi incj+prefj
// b3: pi-bi incj-prefj
struct BIT_SGT{
	struct SGT{
		int ls,rs,sum;
	}t[maxn*100];
	int cnt;
	inline void push_up(int p){
		t[p].sum=t[t[p].ls].sum+t[t[p].rs].sum;
	}
	void insert(int &p,int l,int r,int k,int v){
		if(!p)p=++cnt;
		if(l==r){
			t[p].sum+=v;
			return;
		}
		ri mid=l+r>>1;
		if(k<=mid)insert(t[p].ls,l,mid,k,v);
		else insert(t[p].rs,mid+1,r,k,v);
		push_up(p);
	}
	typedef vector<int> vi;
	int query(vi &pt,int l,int r,int ql,int qr){
		if(ql<=l&&r<=qr){
			ri ret=0;
			for(auto p:pt)ret+=t[p].sum;
			return ret;
		}
		ri mid=l+r>>1,ret=0;
		if(ql<=mid){
			vi tmp=pt;
			for(auto &p:tmp)p=t[p].ls;
			ret+=query(tmp,l,mid,ql,qr);
		}
		if(qr>mid){
			vi tmp=pt;
			for(auto &p:tmp)p=t[p].rs;
			ret+=query(tmp,mid+1,r,ql,qr);
		}
		return ret;
	}
	#define lowbit(k) ((k)&(-k))
	int len1,len2,rt[maxn*3];
	inline void modify(int k1,int k2,int v){
		for(ri i=k1;i<=len1;i+=lowbit(i))insert(rt[i],1,len2,k2,v);
	}
	inline int query(int k1,int k2){
		vi tmp;
		for(ri i=k1;i;i^=lowbit(i))tmp.push_back(rt[i]);
		return query(tmp,1,len2,1,k2);
	}
}t1,t2;
struct node{
	int id,op,pos;
	inline bool operator<(const node &k)const{
		return pos!=k.pos?pos<k.pos:op<k.op;
	}
}q[maxn*3];
int ans[maxn],b[maxn],bp[maxn],cnt,inc[maxn],ip[maxn],m,n,p[maxn],pb[maxn],pi[maxn],pref[maxn],s[maxn];
int main(){
	n=qr(),m=qr();
	for(ri i=1;i<=n;++i)p[i]=qr();
	for(ri i=1;i<=n;++i)s[i]=qr();
	for(ri i=1;i<=n;++i){
		b[i]=qr();
		b1.insert(b[i]);
		b2.insert(b[i]+p[i]);
		b3.insert(p[i]-b[i]);
		q[++cnt]={i,1,p[i]};
		q[++cnt]={i,2,s[i]+1};
	}
	for(ri i=1;i<=m;++i)inc[i]=qr();
	for(ri i=1;i<=m;++i){
		pref[i]=qr();
		b1.insert(pref[i]);
		b2.insert(inc[i]+pref[i]);
		b3.insert(inc[i]-pref[i]);
		q[++cnt]={i,3,inc[i]};
	}
	b1.init();
	t1.len1=t2.len1=b1.bl;
	b2.init();
	t1.len2=b2.bl;
	b3.init();
	t2.len2=b3.bl;
	for(ri i=1;i<=n;++i){
		bp[i]=b2.query(b[i]+p[i]);
		pb[i]=b3.query(p[i]-b[i]);
		b[i]=b1.query(b[i]);
	}
	for(ri i=1;i<=m;++i){
		ip[i]=b2.query(inc[i]+pref[i]);
		pi[i]=b3.query(inc[i]-pref[i]);
		pref[i]=b1.query(pref[i]);
	}
	sort(q+1,q+cnt+1);
	for(ri i=1;i<=cnt;++i)
		if(q[i].op==1){
			t1.modify(b1.bl-b[q[i].id]+1,bp[q[i].id],1);
			t2.modify(b[q[i].id],pb[q[i].id],1);
		}
		else if(q[i].op==2){
			t1.modify(b1.bl-b[q[i].id]+1,bp[q[i].id],-1);
			t2.modify(b[q[i].id],pb[q[i].id],-1);
		}
		else{
			ri sum=0;
			sum+=t1.query(b1.bl-pref[q[i].id]+1,ip[q[i].id]);
			sum+=t2.query(pref[q[i].id]-1,pi[q[i].id]);
			ans[q[i].id]=sum;
		}
	for(ri i=1;i<=m;++i)qw(ans[i]),putchar(32);
	return 0;
}