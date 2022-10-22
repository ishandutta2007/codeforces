#include<bits/stdc++.h>
using namespace std;
#define ri int
typedef long long ll;
const int maxa=1e9+1,maxn=2e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
static char pbuf[1000000],*p1=pbuf,*p2=pbuf;
#define getchar() p1==p2&&(p2=(p1=pbuf)+fread(pbuf,1,1000000,stdin),p1==p2)?EOF:*p1++
inline ll qr(){
	ll in=0;
	char ch;
	while(!isdigit(ch=getchar()));
	do in=(in<<1)+(in<<3)+(ch^48);while(isdigit(ch=getchar()));
	return in;
}
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
#define fi first
#define se second
inline pll operator+(const pll &x,const pll &y){return {x.fi+y.fi,x.se+y.se};}
inline pll operator-(const pll &x,const pll &y){return {x.fi-y.fi,x.se-y.se};}
struct segment_tree{
	int ls,rs;
	pll sum;
}t[maxn<<5];
int a[maxn],cnt,mx[maxn],r[maxn],req[maxn],rt[maxn];
int insert(int p,int l,int r,int k,int id){
	t[++cnt]=t[p];
	p=cnt;
	t[p].sum=t[p].sum+pll{mx[id],::r[id]};
	if(l==r)return p;
	ri mid=l+r>>1;
	if(k<=mid)t[p].ls=insert(t[p].ls,l,mid,k,id);
	else t[p].rs=insert(t[p].rs,mid+1,r,k,id);
	return p;
}
pll query(int p1,int p2,int l,int r,int k){
	if(l==r)return t[p2].sum-t[p1].sum;
	ri mid=l+r>>1;
	pll ret={0,0};
	if(k<=mid)return query(t[p1].ls,t[p2].ls,l,mid,k);
	else return t[t[p2].ls].sum-t[t[p1].ls].sum+query(t[p1].rs,t[p2].rs,mid+1,r,k);
}
int m,n;
ll ans,pre_r[maxn];
struct node{
	int l,r,t;
	ll ex;
	inline bool operator<(const node &k)const{return l<k.l;}
};
set<node>s;
int main(){
	n=qr();
	s.insert({1,n,-1});
	for(ri i=1;i<=n;++i){
		mx[i]=qr(),r[i]=qr();
		pre_r[i]=pre_r[i-1]+r[i];
		if(r[i])req[i]=(mx[i]+r[i]-1)/r[i];
		else req[i]=maxa;
		rt[i]=insert(rt[i-1],1,maxa,req[i],i);
	}
	m=qr();
	while(m--){
		ri t=qr();
		ll sum=qr();
		auto it=s.begin();
		while(it!=s.end()){
			node tmp=*it;
			it=s.erase(it);
			if(tmp.t==-1){
				for(ri i=tmp.l;i<=tmp.r;++i){
					if(mx[i]>=sum){
						if(i>1)s.insert({1,i-1,t,0});
						s.insert({i,i,t,mx[i]-sum});
						if(i<n)s.insert({i+1,n,-1,0});
						goto skip;
					}
					else sum-=mx[i];
				}
			}
			else if(tmp.ex){
				ll val=min((ll)mx[tmp.l],tmp.ex+1ll*(t-tmp.t)*r[tmp.l]);
				if(val>=sum){
					if(tmp.l>1)s.insert({1,tmp.l-1,t,0});
					s.insert({tmp.l,tmp.r,t,val-sum});
					goto skip;
				}
				else sum-=val;
			}
			else{
				pll tmp2=query(rt[tmp.l-1],rt[tmp.r],1,maxa,t-tmp.t);
				ll val=tmp2.fi+(pre_r[tmp.r]-pre_r[tmp.l-1]-tmp2.se)*(t-tmp.t);
				if(val>=sum){
					ri l=tmp.l,r=tmp.r,pos=-1;
					ll pv=0;
					while(l<=r){
						ri mid=l+r>>1;
						tmp2=query(rt[tmp.l-1],rt[mid],1,maxa,t-tmp.t);
						val=tmp2.fi+(pre_r[mid]-pre_r[tmp.l-1]-tmp2.se)*(t-tmp.t);
						if(val>=sum)pos=mid,pv=val,r=mid-1;
						else l=mid+1;
					}
					if(pos>1)s.insert({1,pos-1,t,0});
					s.insert({pos,pos,t,pv-sum});
					if(pos<tmp.r)s.insert({pos+1,tmp.r,tmp.t,0});
					goto skip;
				}
				else sum-=val;
			}
		}
		s.insert({1,n,t,0});
		ans+=sum;
		skip:;
	}
	printf("%lld",ans);
	return 0;
}