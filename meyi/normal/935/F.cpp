#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline int qr(){
	ri in=0;char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
int cnt,n,q,vis[maxn];
ll a[maxn],ans,c[maxn];
inline ll query(int k){
	if(vis[k]==cnt)return a[k];
	vis[k]=cnt;
	ll &ret=a[k]=0;
	for(;k;k^=k&-k)ret+=c[k];
	return ret;
}
inline ll calc(int k,ll x){
	return (k>1?abs(query(k-1)-x):0)+(k<n?abs(x-query(k+1)):0);
}
bool ge[maxn<<2];
int le[maxn<<2];
ll v[maxn<<2];
#define ls(p) (p<<1)
#define rs(p) (p<<1|1)
inline void push_up(int p){
	le[p]=le[ls(p)]|le[rs(p)];
	ge[p]=ge[ls(p)]|ge[rs(p)];
	v[p]=min(v[ls(p)],v[rs(p)]);
}
void build(int p,int l,int r){
	if(l==r){
		le[p]=ge[p]=0,v[p]=1e9;
		if(query(l)>=query(l-1)&&query(r)>=query(r+1))ge[p]=1;
		else if(query(l)<query(l-1)&&query(r)<query(r+1))le[p]=l;
		else v[p]=max(query(l-1),query(r+1))-query(l);
		return;
	}
	ri mid=l+r>>1;
	build(ls(p),l,mid);
	build(rs(p),mid+1,r);
	push_up(p);
}
void modify(int k){
	ri l=2,p=1,r=n-1;
	while(l!=r){
		ri mid=l+r>>1;
		if(k<=mid)p=ls(p),r=mid;
		else l=mid+1,p=rs(p);
	}
	le[p]=ge[p]=0,v[p]=1e9;
	if(query(k)>=query(k-1)&&query(k)>=query(k+1))ge[p]=1;
	else if(query(k)<query(k-1)&&query(k)<query(k+1))le[p]=k;
	else v[p]=max(query(k-1),query(k+1))-query(k);
	while(p>>=1)push_up(p);
}
ll query(int p,int l,int r,int ql,int qr,int x){
	ll ret=INT_MIN;
	if(ql<=l&&r<=qr){
		if(ge[p])return x<<1;
		if(l!=r||!le[p])ckmax(ret,max(2*(x-v[p]),0ll));
		if(le[p])ckmax(ret,calc(le[p],query(le[p])+x)-calc(le[p],query(le[p])));
	}
	else{
		ri mid=l+r>>1;
		if(ql<=mid)ckmax(ret,query(ls(p),l,mid,ql,qr,x));
		if(qr>mid)ckmax(ret,query(rs(p),mid+1,r,ql,qr,x));
	}
	return ret;
}
int main(){
	n=qr();
	for(ri i=1;i<=n;++i){
		a[i]=qr();
		c[i]+=a[i]-a[i-1];
		if(i+(i&-i)<=n)c[i+(i&-i)]+=c[i];
	}
	for(ri i=1;i<=n;++i)ans+=calc(i,query(i));
	build(1,2,n-1);
	q=qr();
	while(q--){
		ri op=qr(),l=qr(),r=qr(),x=qr();
		if(op&1)printf("%lld\n",(ans>>1)+query(1,2,n-1,l,r,x));
		else{
			set<int>s;
			for(ri i:{-1,0,1})s.insert(l+i),s.insert(r+i);
			for(ri i:s)
				if(1<=i&&i<=n)
					ans-=calc(i,query(i));
			++cnt;
			for(ri i=l;i<=n;i+=i&-i)c[i]+=x;
			for(ri i=r+1;i<=n;i+=i&-i)c[i]-=x;
			for(ri i:s)
				if(1<=i&&i<=n)
					ans+=calc(i,query(i));
			if(l-1>1)modify(l-1);
			modify(l),modify(r);
			if(r+1<n)modify(r+1);
		}
	}
	return 0;
}