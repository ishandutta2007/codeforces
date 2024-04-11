#include<cstdio>
#include<cassert>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<cstdlib>
using namespace std;

int read();
typedef long long ll;
#define fr(i,l,r) for(int i=(l);i<=(r);++i)
#define rf(i,l,r) for(int i=(l);i>=(r);--i)
#define fo(i,l,r) for(int i=(l);i<(r);++i)
#define foredge(i,u,v) for(int i=fir[u],v;v=to[i],i;i=nxt[i])
#define filein(File) freopen(File".in","r",stdin)
#define fileout(File) freopen(File".out","w",stdout)

const int N=2e5+5,NN=1<<18;
int n,a[N],rt;
vector<int> G[N],T[N];
ll ans;
int stk[N],top,tmp[N];
int seg[1<<19];
int query(int l,int r) {
	int z=0;
	for(l+=NN-1,r+=NN+1;l^r^1;l>>=1,r>>=1) {
		if(~l&1) z=max(z,seg[l^1]);
		if(r&1) z=max(z,seg[r^1]);
	} return z;
}
int dp[N];
void dfs(int u,int fa) {
	stk[++top]=u;
	if(top>=2) tmp[stk[2]]=max(tmp[stk[2]],a[u]);
	seg[top+NN]=a[u];
	for(int i=top+NN;i!=1;i>>=1)
		seg[i>>1]=max(seg[i^1],seg[i]);
	dp[u]=a[u];
	for(auto v:G[u]) if(v!=fa) {
		dfs(v,u);
		dp[u]=max(dp[u],dp[v]);
	}
	--top;
}
void predfs(int u,int fa) {
	if(dp[u]==a[u]) {
		stk[++top]=u;
		if(u!=rt) {
			int l=1,r=top-1;
			while(l<r) {
				int mid=l+r+1>>1;
				if(a[stk[mid]]>=a[u]) l=mid;
				else r=mid-1;
			}
			//cout<<stk[l]<<' '<<u<<endl;
			T[stk[l]].push_back(u);
		}
	}
	for(auto v:G[u]) if(v!=fa) predfs(v,u);
	if(dp[u]==a[u]) --top;
}
void dfs2(int u) {
	int mx[2]={0};
	for(auto v:T[u]) {
		dfs2(v);
		mx[0]=max(mx[0],a[v]);
	}
	if(!T[u].size()) ans+=a[u];
	else if(u!=rt) ans+=a[u]-mx[0];
	else {
		mx[0]=mx[1]=0;
		for(auto v:G[u]) {
			if(tmp[v]>mx[0]) mx[1]=mx[0],mx[0]=tmp[v];
			else if(tmp[v]>mx[1]) mx[1]=tmp[v];
		}
		ans+=a[u]-mx[0]+a[u]-mx[1];
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin>>n;
	fr(i,1,n) cin>>a[i];
	rt=max_element(a+1,a+n+1)-a;
	for(int i=1,u,v;i<n;++i) {
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(rt,0);
	predfs(rt,0);
	dfs2(rt);
	printf("%lld\n",ans);
	return 0;
}