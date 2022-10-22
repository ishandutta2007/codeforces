#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
#define mkp make_pair
const int MAXN=5e4+5,MAXM=1e7;
int n,m;
ll a[MAXN],b[MAXN];
int ans[MAXN];
int cntp,rt,lc[MAXM],rc[MAXM],tag[MAXM];
#define ls lc[k],l,mid
#define rs rc[k],mid+1,r
inline void add(int &k,int v){
	if(!k) k=++cntp;
	tag[k]=v;
}
inline void pushdwn(int k){
	if(tag[k]){
		add(lc[k],tag[k]);
		add(rc[k],tag[k]);
		tag[k]=0;
	}
}
void Modify(int &k,ll l,ll r,ll x,ll y,int v){
	if(!k) k=++cntp;
	if(x<=l&&r<=y) return add(k,v);
	pushdwn(k);
	ll mid=l+r>>1;
	if(x<=mid) Modify(ls,x,y,v);
	if(mid<y) Modify(rs,x,y,v);
	return ;
}
int Query(int k,ll l,ll r,ll w){
	if(tag[k]) return k;
	ll mid=l+r>>1;
	if(w<=mid) return Query(ls,w);
	return Query(rs,w);
}
int pre[MAXM];
int fnd(int x){
	if(x!=pre[x]) pre[x]=fnd(pre[x]);
	return pre[x];
}
vector<pr> vec[MAXN];
void Dfs2(int k,int p){
	if(tag[k]&&tag[p]){
		vec[min(tag[k],tag[p])].push_back(mkp(k,p));
		return ;
	}
	int l=lc[k],r=lc[p];
	if(!l) l=k;
	if(!r) r=p;
	Dfs2(l,r);
	l=rc[k],r=rc[p];
	if(!l) l=k;
	if(!r) r=p;
	Dfs2(l,r);
	return ;
}
void Dfs1(int k){
	if(!lc[k]) return ;
	Dfs2(lc[k],rc[k]);
	Dfs1(lc[k]);
	Dfs1(rc[k]);
	return ;
}
int main(){
	//freopen("in2.txt","r",stdin);
	scanf("%d%d",&n,&m);
	add(rt,m+1);
	for(int i=1; i<=m; i++){
		char op[10];
		scanf("%s%lld%lld",op,a+i,b+i);
		if(op[0]=='b') ans[i]=-1,Modify(rt,0,(1ll<<n)-1,a[i],b[i],i);
	}
	Dfs1(rt);
	for(int i=1; i<=cntp; i++)
		pre[i]=i;
	ans[m+1]=-1;
	for(int i=m+1; i; i--){
		for(int j=0; j<vec[i].size(); j++){
			int x=fnd(vec[i][j].first),y=fnd(vec[i][j].second);
			if(x!=y) pre[x]=y;
		}
		if(!ans[i]) ans[i]=(fnd(Query(rt,0,(1ll<<n)-1,a[i]))==fnd(Query(rt,0,(1ll<<n)-1,b[i])));
	}
	for(int i=1; i<=m; i++)
		if(ans[i]>=0) printf("%d\n",ans[i]);
	return 0;
}