#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

struct dsu{
	vector<int> V;
	dsu(int N){ V.resize(N,-1); }
	int root(int a){ return (V[a]<0)?a:(V[a]=root(V[a])); }
	bool merge(int u,int v){
		u=root(u); v=root(v);
		if(u==v) return false;
		if(V[u]<V[v]) swap(u,v); else if(V[u]==V[v]) V[u]--;
		V[v]=u;
		return true;
	}
};

const ULL MOD=1000000007;

int N,M;

int main(){
	scanf("%d%d",&N,&M);
	dsu G(M+1);
	vector<int> ans;
	rep(i,N){
		int K; scanf("%d",&K);
		if(K==1){
			int u; scanf("%d",&u); u--;
			if(G.merge(u,M)) ans.push_back(i);
		}
		if(K==2){
			int u,v; scanf("%d%d",&u,&v); u--; v--;
			if(G.merge(u,v)) ans.push_back(i);
		}
	}
	ULL T_size=1; rep(i,ans.size()) T_size=T_size*2%MOD;
	printf("%llu %d\n",T_size,(int)ans.size());
	rep(i,ans.size()){ if(i) printf(" "); printf("%d",ans[i]+1); } printf("\n");
	return 0;
}