#include<bits/stdc++.h>
template<class T> inline void read(T &x){
	x=0;register char c=getchar();register bool f=0;
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))x=x*10+c-'0',c=getchar();if(f)x=-x;
}
template<class T> inline void print(T x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);putchar(x%10+'0');
}
template<class T> inline void print(T x,char c){print(x),putchar(c);}
template<class T> inline void print(T a,int l,int r){for(int i=l;i<=r;i++)print(a[i]," \n"[i==r]);}
const int N=4e5+10;
int n,ma,mb,al[N],bl[N],ar[N],br[N],as[N],bs[N];
struct node{
	int al,ar,bl,br;
	inline bool operator<(const node &other)const{
		return ar<other.ar;
	}
}e[N];
struct seg_node{
	int l,r,mid,ll,rr;
}p[N<<2];
void build(int u,int l,int r){
	p[u].l=l,p[u].r=r,p[u].mid=(l+r)>>1,p[u].ll=p[u].rr=INT_MAX;
	if(l==r)return;
	build(u<<1,l,p[u].mid),build(u<<1|1,p[u].mid+1,r);
}
int queryL(int u,int l,int r){
	// printf("%d %d %d : %d %d %d %d\n",u,l,r,p[u].l,p[u].r,p[u].ll,p[u].rr);
	if(p[u].l==l&&p[u].r==r)return p[u].ll;
	if(r<=p[u].mid)return queryL(u<<1,l,r);
	if(l>p[u].mid)return queryL(u<<1|1,l,r);
	return std::min(queryL(u<<1,l,p[u].mid),queryL(u<<1|1,p[u].mid+1,r));
}
int queryR(int u,int l,int r){
	// printf("%d %d %d : %d %d %d %d\n",u,l,r,p[u].l,p[u].r,p[u].ll,p[u].rr);
	if(p[u].l==l&&p[u].r==r)return p[u].rr;
	if(r<=p[u].mid)return queryR(u<<1,l,r);
	if(l>p[u].mid)return queryR(u<<1|1,l,r);
	return std::min(queryR(u<<1,l,p[u].mid),queryR(u<<1|1,p[u].mid+1,r));
}
void modifyL(int u,int k,int x){
	p[u].ll=std::min(p[u].ll,x);
	if(p[u].l==p[u].r)return;
	modifyL(k<=p[u].mid?u<<1:u<<1|1,k,x);
}
void modifyR(int u,int k,int x){
	p[u].rr=std::min(p[u].rr,x);
	if(p[u].l==p[u].r)return;
	modifyR(k<=p[u].mid?u<<1:u<<1|1,k,x);
}
void solve(int m){
	std::sort(e+1,e+n+1),build(1,1,n<<1);
	for(int i=n;i;--i){
		if(e[i].bl>1&&queryR(1,1,e[i].bl-1)<=e[i].ar)puts("NO"),exit(0);
		if(e[i].br<m&&queryL(1,e[i].br+1,m)<=e[i].ar)puts("NO"),exit(0);
		modifyR(1,e[i].br,e[i].al);
		modifyL(1,e[i].bl,e[i].al);
	}
}
int main(){
#ifdef memset0
	freopen("1.in","r",stdin);
#endif
	read(n);
	for(int i=1;i<=n;++i){
		read(al[i]),read(ar[i]),read(bl[i]),read(br[i]);
		as[i*2-1]=al[i],as[i*2]=ar[i];
		bs[i*2-1]=bl[i],bs[i*2]=br[i];
	}
	std::sort(as+1,as+n+n+1),ma=std::unique(as+n+1,as+n+n+1)-as-1;
	std::sort(bs+1,bs+n+n+1),mb=std::unique(bs+n+1,bs+n+n+1)-bs-1;
	for(int i=1;i<=n;++i){
		al[i]=std::lower_bound(as+1,as+ma+1,al[i])-as;
		bl[i]=std::lower_bound(bs+1,bs+mb+1,bl[i])-bs;
		ar[i]=std::lower_bound(as+1,as+ma+1,ar[i])-as;
		br[i]=std::lower_bound(bs+1,bs+mb+1,br[i])-bs;
	}
	for(int i=1;i<=n;++i)e[i].al=al[i],e[i].bl=bl[i],e[i].ar=ar[i],e[i].br=br[i]; solve(mb);
	for(int i=1;i<=n;++i)e[i].al=bl[i],e[i].bl=al[i],e[i].ar=br[i],e[i].br=ar[i]; solve(ma);
	puts("YES");
}