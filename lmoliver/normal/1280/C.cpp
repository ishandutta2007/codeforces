#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct E{
	int v,w;
};
typedef vector<E> VE;
const int N=600600;
VE es[N];
VE ch[N];
int sz[N];

void dfs0(int x,int fa=-1){
	sz[x]=1;
	for(E e:es[x]){
		if(e.v!=fa){
			dfs0(e.v,x);
			ch[x].push_back({e.v,e.w});
			sz[x]+=sz[e.v];
		}
	}
}

int szf[N];
void dfs1(int x,int fa=-1){
	int sum=fa==-1?1:szf[x]+1;
	for(E e:ch[x]){
		sum+=sz[e.v];
	}
	for(E e:ch[x]){
		szf[e.v]=sum-sz[e.v];
		dfs1(e.v,x);
	}
}

LL dfs2(int x){
	LL ans=0;
	for(E e:ch[x]){
		if(sz[e.v]%2==1){
			ans+=e.w;
		}
		ans+=dfs2(e.v);
	}
	return ans;
}

LL dfs3(int x){
	LL ans=0;
	for(E e:ch[x]){
		ans+=(LL)min(sz[e.v],szf[e.v])*e.w;
		ans+=dfs3(e.v);
	}
	return ans;
}

void work(){
	int k;
	cin>>k;
	for(int i=1;i<=2*k;i++){
		es[i].clear();
		ch[i].clear();
	}
	for(int i=1;i<=2*k-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		es[u].push_back({v,w});
		es[v].push_back({u,w});
	}
	dfs0(1);
	dfs1(1);
	LL g=dfs2(1);
	LL b=dfs3(1);
	cout<<g<<" "<<b<<endl;
}

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		work();
	}
	return 0;
}