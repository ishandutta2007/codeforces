#include<bits/stdc++.h>
using namespace std;
#define ri register int
typedef long long ll;
const int maxa=1e9+1,maxn=1e5+10;
template<class T>inline bool ckmin(T &x,const T &y){return x>y?x=y,1:0;}
template<class T>inline bool ckmax(T &x,const T &y){return x<y?x=y,1:0;}
template<class T>inline void clear(T *arr,int siz,int val=0){memset(arr,val,sizeof(T)*(siz+1));}
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
ll pre_r[maxn];
struct node{
	int l,r,t;
	inline bool operator<(const node &k)const{return l<k.l;}
};
set<node>s;
int main(){
	scanf("%d",&n);
	s.insert({1,n,-1});
	for(ri i=1;i<=n;++i){
		scanf("%d%d%d",a+i,mx+i,r+i);
		pre_r[i]=pre_r[i-1]+r[i];
		if(r[i])req[i]=(mx[i]+r[i]-1)/r[i];
		else req[i]=maxa;
		rt[i]=insert(rt[i-1],1,maxa,req[i],i);
	}
	scanf("%d",&m);
	while(m--){
		ri l,r,t;
		scanf("%d%d%d",&t,&l,&r);
		ll ans=0;
		vector<node>ex={{l,r,t}};
		auto it=--s.upper_bound({l});
		while(it!=s.end()&&it->l<=r){
			node tmp=*it;
			it=s.erase(it);
			if(tmp.l<l)ex.push_back({tmp.l,l-1,tmp.t}),tmp.l=l;
			if(tmp.r>r)ex.push_back({r+1,tmp.r,tmp.t}),tmp.r=r;
			if(tmp.t==-1){
				for(ri i=tmp.l;i<=tmp.r;++i)ans+=min((ll)mx[i],a[i]+1ll*t*::r[i]);
			}
			else{
				pll tmp2=query(rt[tmp.l-1],rt[tmp.r],1,maxa,t-tmp.t);
				ans+=tmp2.fi+(pre_r[tmp.r]-pre_r[tmp.l-1]-tmp2.se)*(t-tmp.t);
			}
		}
		for(const node &i:ex)s.insert(i);
		printf("%lld\n",ans);
	}
	return 0;
}