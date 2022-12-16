#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define F(N,S,E) for(int N=(int)(S);N<=(int)(E);N++)

const int N=1001001;
bool vis[N]={false};
int nxt[N];
int find(int x){
	return nxt[x]==x?x:(nxt[x]=find(nxt[x]));
}
int n,m;
typedef pair<int,int> P;
set<P> es;
void dfs(int x){
	// cerr<<x;
	vis[x]=true;
	nxt[x]=nxt[x+1];
	for(int i=find(1);i<=n;i=find(i+1)){
		if(!es.count(P(x,i))){
			dfs(i);
		}
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>m;
	F(i,1,n+1)nxt[i]=i;
	while(m--){
		int u,v;
		cin>>u>>v;
		es.insert(P(u,v));
		es.insert(P(v,u));
	}
	int ans=-1;
	F(i,1,n)if(!vis[i]){
		// cerr<<"!";
		ans++;
		dfs(i);
	};
	cout<<ans<<endl;
	return 0;
}