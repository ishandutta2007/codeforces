#include<bits/stdc++.h>
#define int long long
using namespace std;
typedef pair<int,int> node;
int const N=100010,MOD=998244353,INF=0x3f3f3f3f3f3f3f3fll;
int n,m,s,t,d1[N],d2[N],f1[N],f2[N],vis[N];
vector<node>e[N],g[N];
vector<array<int,3> >edge;
priority_queue<node,vector<node>,greater<node> >q;
void solve(int s,int d[N],int f[N],vector<node>*e){
	for(int i=1;i<=n;i++)
		d[i]=INF,f[i]=vis[i]=0;
	q.push({d[s]=0,s}),f[s]=1;
	while(!q.empty()){
		int x=q.top().second;q.pop();
		if(vis[x])
			continue;
		vis[x]=1;
		for(auto i:e[x]){
			int y=i.first,w=i.second+d[x];
			if(d[y]==w)
				f[y]=(f[y]+f[x])%MOD;
			else if(!vis[y]&&d[y]>w)
				q.push({d[y]=w,y}),f[y]=f[x];
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>s>>t;
	while(m--){
		int a,b,c;cin>>a>>b>>c;
		e[a].push_back({b,c});
		g[b].push_back({a,c});
		edge.push_back({a,b,c});
	}
	solve(s,d1,f1,e);
	solve(t,d2,f2,g);
	for(auto i:edge){
		int x=i[0],y=i[1],w=i[2];
		if(d1[x]==INF||d2[y]==INF)
			cout<<"NO\n";
		else if(d1[x]+w+d2[y]==d1[t]){
			if(f1[x]*f2[y]%MOD==f1[t])
				cout<<"YES\n";
			else if(w>1)
				cout<<"CAN 1\n";
			else
				cout<<"NO\n";
        }else{
			int k=d1[x]+w+d2[y]-d1[t]+1;
			if(k<w)
				cout<<"CAN "<<k<<"\n";
			else
				cout<<"NO\n";
		}
	}
}