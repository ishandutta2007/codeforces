/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
const int maxn=2e5;
const int B=256;
struct LCA{
	int n,q;
	int a[maxn],dfn[maxn],tot;
	int st[15][maxn / B + 1];
	int pre[maxn + B], p[maxn + B];
	inline int min(int x,int y){ return dfn[x] < dfn[y] ? x : y; }
	inline void down(int & x,int y){ if(dfn[x] > dfn[y]) x = y; }
	inline int qry(int l,int r){
		const int lg = std::__lg(r - l);
		return l >= r ? 0 : min(st[lg][l],st[lg][r - (1 << lg)]);
	}
	inline int rmq(int l,int r){
		if(l / B == r / B) {
			int ret = p[l];
			for(int i = l + 1;i <= r;++i) 
				down(ret,p[i]);
			return ret;
		}
		else return min(qry(l / B + 1,r / B),min(a[l],pre[r]));
	}
	inline void build(int n){
		++ n;
		memcpy(p,a,n << 2);
		for(int i = 0;i < n;i += B) {
			pre[i] = a[i];
			for(int j = i + 1;j < i + B;++j) pre[j] = min(pre[j - 1],a[j]);
			for(int j = i + B - 2;j >= i;--j) down(a[j], a[j + 1]);
			st[0][i / B] = a[i];
		}
		for(int i = 1;i < 15;++i)
			for(int j = 0;j + (1 << i) - 1 <= n / B + 1;++j)
				st[i][j] = min(st[i - 1][j],st[i - 1][j + (1 << i - 1)]);
	}
	int head[maxn], next[maxn];
	inline void link(int fa, int x) {
		next[x] = head[fa], head[fa] = x;
	}
	inline void dfs(int x,int f){
		a[tot] = f; dfn[x] = ++tot;
		for(int i = head[x];i;i = next[i])
			dfs(i, x);
	}
	inline int get_lca(int x,int y){
		if(dfn[x] > dfn[y]) std::swap(x,y);
		return x == y ? x : rmq(dfn[x], dfn[y] - 1);
	}
	int ans[maxn];
	void init(int n,vector<pair<int,int> >&E){
		//<parent,son>
		for(auto p:E)link(p.first,p.second);
		dfs(1,0); *dfn = 2e9; build(n - 1);
	}
}lca;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+9;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
struct SA{
	int n,sa[1000005],rk[1000005],cnt[1000005],tp[1000005],h[1000005];
	SA(){}
	void Qsort(){
		memset(cnt,0,sizeof cnt);
		int lmt=*max_element(rk+1,rk+n+1);
		for(int i=1;i<=n;i++)cnt[rk[i]]++;
		for(int i=1;i<=lmt;i++)cnt[i]+=cnt[i-1];
		for(int i=n;i>=1;i--)sa[cnt[rk[tp[i]]]--]=tp[i];
	}
	void build(string s){
		for(int i=1;i<=n;i++)rk[i]=s[i]+1,tp[i]=i;
		Qsort();
		for(int w=1;w<=n;w<<=1){
			int pos=0;
			for(int j=n-w+1;j<=n;j++)tp[++pos]=j;
			for(int j=1;j<=n;j++)if(sa[j]>w)tp[++pos]=sa[j]-w;
			Qsort();
			memcpy(tp,rk,sizeof tp);
			pos=0;
			for(int j=1;j<=n;j++)rk[sa[j]]=(j==1||tp[sa[j]]!=tp[sa[j-1]]||tp[sa[j]+w]!=tp[sa[j-1]+w]?++pos:pos);
		}
		for(int i=1;i<=n;i++){
			if(rk[i]==1)continue;
			int tmp=h[rk[i-1]];if(tmp)tmp--;
			while(s[sa[rk[i]]+tmp]==s[sa[rk[i]-1]+tmp])tmp++;
			h[rk[i]]=tmp;
		}
	}
}sa;
string all;int n,m,q;
vector<pair<int,char> >g[100005];
const int base=10007;
const int ibase=modpow(base,mod-2);
int pw[1000005],dep[1000005],ipw[1000005];
int hsh_down[1000005],hsh_up[1000005];
int lb[100005],rb[100005];
int go[17][100005];
const int C=305;
int dat[C][100005];
char cc[100005];
vector<pair<int,int> >E;
void dfs(int x,int par,int d=0){
	go[0][x]=par;
	dep[x]=d;if(par)E.push_back(make_pair(par,x));
	for(auto p:g[x])if(p.first!=par){
		hsh_down[p.first]=(1ull*hsh_down[x]*base+p.second)%mod;
		hsh_up[p.first]=(hsh_up[x]+1ull*pw[d]*p.second)%mod;
		cc[p.first]=p.second;dfs(p.first,x,d+1);
	}
}
int hsh_str[1000005];
void init(){
	for(int i=1;i<=sa.n;i++)hsh_str[i]=(1ull*hsh_str[i-1]*base+all[i])%mod;
}
int get_hash(int st,int len){
	if(st+len-1>sa.n)return -1;
	return (hsh_str[st+len-1]-1ull*hsh_str[st-1]*pw[len]%mod+mod)%mod;
}
int get_kth(int x,int k){
	if(k<C)return dat[k][x];
	for(int i=0;i<17;i++)if(k&(1<<i)){
		x=go[i][x];k^=(1<<i);if(!k)break;
	}
	return x;
}
int get_tree(int u,int v,int len){
	int w=lca.get_lca(u,v);
	if(dep[u]-dep[w]>=len){
		int tar=get_kth(u,len);
		return 1ull*(hsh_up[u]-hsh_up[tar]+mod)*ipw[dep[tar]]%mod;
	}else{
		int got=1ull*(hsh_up[u]-hsh_up[w]+mod)*ipw[dep[w]]%mod;
		len-=(dep[u]-dep[w]);got=1ull*got*pw[len]%mod;
		int up=(dep[v]-dep[w])-len;
		if(up<0)return -2;
		v=get_kth(v,up);
		got=(got+(hsh_down[v]-1ull*hsh_down[w]*pw[len]%mod)+mod)%mod;
		return got;
	}
}
int get_state(int u,int v,int x){
	if(x>sa.n)return 2;
	if(x<=0)return 0;
//	cerr<<"get state: "<<u<<" "<<v<<" "<<x<<endl;
	int w=lca.get_lca(u,v);
	int l=0,r=dep[u]+dep[v]-dep[w]-dep[w]+1;
	while(r-l>1){
		int mid=(l+r)/2;
		if(get_tree(u,v,mid)==get_hash(sa.sa[x],mid))l=mid;
		else r=mid;
	}
	if(l==dep[u]+dep[v]-dep[w]-dep[w])return 1;
	char c1;
	if(l<dep[u]-dep[w]){
		int pos=get_kth(u,l);
		c1=cc[pos];
	}else{
		int tmp=l-(dep[u]-dep[w]);
		int up=dep[v]-dep[w]-tmp-1;
		int pos=get_kth(v,up);
		c1=cc[pos];
	}
	char c2;
	int tar=sa.sa[x]+l;
	if(tar>sa.n)return 0;
	c2=all[tar];
	if(c1<c2)return 2;
	else return 0;
}
int rt[1000005];
namespace count_2D{
	int f[200005*20],ls[200005*20],rs[200005*20],tot=0;
	int insert(int l,int r,int &rt,int x){
		if(l==r){
			int ret=++tot;
			f[ret]=1;
			return ret;
		}
		if(!rt)rt=++tot;
		int mid=(l+r)/2,ret=++tot;
		if(x<=mid)ls[ret]=insert(l,mid,ls[rt],x),rs[ret]=rs[rt];
		else rs[ret]=insert(mid+1,r,rs[rt],x),ls[ret]=ls[rt];
		f[ret]=f[ls[ret]]+f[rs[ret]];
		return ret;
	}
	int query(int rt,int l,int r,int ql,int qr){
		if(!rt)return 0;
		if(qr<l||r<ql)return 0;
		if(ql<=l&&r<=qr)return f[rt];
		return query(ls[rt],l,(l+r)/2,ql,qr)+query(rs[rt],(l+r)/2+1,r,ql,qr);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>q;
	pw[0]=1;ipw[0]=1;
	for(int i=1;i<=1e6;i++)pw[i]=1ull*pw[i-1]*base%mod;
	for(int i=1;i<=1e6;i++)ipw[i]=1ull*ipw[i-1]*ibase%mod;
	for(int i=1;i<n;i++){
		int x,y;char c;
		cin>>x>>y>>c;
		g[x].push_back(make_pair(y,c));
		g[y].push_back(make_pair(x,c));
	}
	dfs(1,0);lca.init(n,E);
	for(int i=1;i<=m;i++){
		string s;cin>>s;
		lb[i]=all.size();all+=s;
		rb[i]=all.size();all+='$';
	}
	for(int j=1;j<=n;j++)dat[0][j]=j;
	for(int i=1;i<C;i++)for(int j=1;j<=n;j++)dat[i][j]=go[0][dat[i-1][j]];
	for(int i=1;i<17;i++)for(int j=1;j<=n;j++)go[i][j]=go[i-1][go[i-1][j]];
//	cerr<<all.size()<<" "<<(int)all.size()-1<<endl;
	sa.n=(int)all.size()-1;all=" "+all;sa.build(all);init();
//	for(int i=1;i<=sa.n;i++)cerr<<getstr(all,sa.sa[i],all.size()-1)<<endl;
	for(int i=1;i<=sa.n;i++)rt[i]=count_2D::insert(1,sa.n,rt[i-1],sa.sa[i]);
	while(q--){
		int u,v,l,r;cin>>u>>v>>l>>r;
//		for(int i=1;i<=sa.n;i++)cerr<<i<<" "<<get_state(u,v,i)<<" "<<getstr(all,sa.sa[i],all.size()-1)<<endl;
//		return 0;
		int L=0,R=all.size();
		while(R-L>1){
			int mid=(L+R)/2;
			if(get_state(u,v,mid)==0)L=mid;
			else R=mid;
		}
		int lim_l=R;
		L=lim_l-1;R=all.size()-1;
		while(R-L>1){
			int mid=(L+R)/2;
			if(get_state(u,v,mid)<=1)L=mid;
			else R=mid;
		}
		int lim_r=L;
//		cerr<<lim_l<<" "<<lim_r<<" "<<lb[l]<<" "<<rb[r]<<endl;
		int ans=0;
//		for(int i=lim_l;i<=lim_r;i++)if(sa.sa[i]>=lb[l]&&sa.sa[i]<=rb[r]){
//			cerr<<i<<" "<<sa.sa[i]<<endl;
//		}
		ans=count_2D::query(rt[lim_r],1,sa.n,lb[l],rb[r])-(lim_l==0?0:count_2D::query(rt[lim_l-1],1,sa.n,lb[l],rb[r]));
		cout<<ans<<endl;
	}
	return 0;
}