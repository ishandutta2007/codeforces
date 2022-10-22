#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxm=5e5+10,maxn=1e5+10,maxp=321;
template<class T>inline void ckmax(T &x,const T &y){if(x<y)x=y;}
template<class T>inline void ckmin(T &x,const T &y){if(x>y)x=y;}
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
typedef pair<int,int> pii;
#define fi first
#define se second
struct undo_ufs{
	int ans,fa[maxn],siz[maxn],st[maxn],tp;
	inline void init(int k){
		ans=tp=0;
		for(ri i=1;i<=k;++i)fa[i]=i,siz[i]=1;
	}
	int find(int k){
		return k==fa[k]?k:find(fa[k]);
	}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			++ans;
			if(siz[x]>siz[y])swap(x,y);
			fa[x]=y,siz[y]+=siz[x];
			st[++tp]=x;
		}
	}
	inline void undo(int k){
		while(tp>k)fa[st[tp]]=st[tp],--tp;
	}
}bg;
struct ufs{
	int ans,fa[maxn];
	inline void init(int l,int r){
		ans=0;
		for(ri i=l;i<=r;++i)fa[i]=i;
	}
	int find(int k){
		return k==fa[k]?k:fa[k]=find(fa[k]);
	}
	inline void merge(int x,int y){
		x=find(x),y=find(y);
		if(x!=y){
			++ans;
			fa[x]=y;
		}
	}
}sm;
pii e[maxm];
vector<int>to1[maxn],to2[maxn];
inline int calc(int l,int r){
	sm.init(l,r);
	for(ri i=l;i<r;++i)
		for(auto j:to1[i])
			if(e[j].se<=r)
				sm.merge(i,e[j].se);
	return r-l+1-sm.ans;
}
int ans[maxn],bel[maxn],cnt,m,n,ql;
struct node{int l,r,id;};
vector<node>q[maxp];
int main(){
	n=qr(),qr(),m=qr();
	for(ri i=1;i<=m;++i){
		ri x=qr(),y=qr();
		if(x>y)swap(x,y);
		e[i]={x,y};
		to1[x].push_back(i);
		to2[y].push_back(i);
	}
	m=530;
	for(ri i=1;i<=n;++i){
		if(i%m==1)++cnt;
		bel[i]=cnt;
	}
	ql=qr();
	for(ri i=1;i<=ql;++i){
		ri l=qr(),r=qr();
		if(r-l+1<=m)ans[i]=calc(l,r);
		else q[bel[l]].push_back({l,r,i});
	}
	for(ri i=1;i<=cnt;++i){
		bg.init(n);
		sort(q[i].begin(),q[i].end(),[&](const node &x,const node &y){return x.r<y.r;});
		ri kr=min(i*m,n),R=kr,L=R+1;
		for(auto j:q[i]){
			while(R<j.r){
				++R;
				for(auto k:to2[R])
					if(e[k].fi>=kr)
						bg.merge(e[k].fi,R);
			}
			ri tmp1=bg.ans,tmp2=bg.tp;
			while(L>j.l){
				--L;
				for(auto k:to1[L])
					if(e[k].se<=j.r)
						bg.merge(L,e[k].se);
			}
			ans[j.id]=j.r-j.l+1-bg.ans;
			bg.ans=tmp1;
			bg.undo(tmp2);
			L=kr+1;
		}
	}
	for(ri i=1;i<=ql;++i)qw(ans[i]),putchar(10);
	fwrite(obuf,o-obuf,1,stdout);
	return 0;
}