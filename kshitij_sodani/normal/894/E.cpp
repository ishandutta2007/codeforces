//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
vector<pair<llo,llo>> adj[1000002];
vector<pair<llo,llo>> adj2[1000002];
llo vis[1000002];
vector<llo> ord;
void dfs(llo no){
	vis[no]=1;
	for(auto j:adj[no]){
		if(vis[j.a]==0){
			dfs(j.a);
		}
	}
	ord.pb(no);
}
llo cur=0;
void dfs2(llo no){
	vis[no]=cur;
	for(auto j:adj2[no]){
		if(vis[j.a]==0){
			dfs2(j.a);
		}
	}
}
vector<pair<llo,llo>> adj3[1000002];
vector<pair<llo,llo>> adj4[1000002];

llo val[1000002];
llo co[1000002];
llo dp[1000002];
llo pre[1000002];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	pre[1]=1;
	for(int i=2;i<=1000000;i++){
		pre[i]=pre[i-1]+((i*(i+1)))/2;
	}

	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		aa--;
		bb--;
		
		//cout<<cc<<":"<<su<<endl;
	//	cout<<cc<<":"<<su<<endl;
		//cout<<low<<":"<<endl;
		adj[aa].pb({bb,cc});
		adj2[bb].pb({aa,cc});
	}
	llo kk;
	cin>>kk;
	kk--;
	for(llo i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i);
		}
	}
	for(llo i=0;i<n;i++){
		vis[i]=0;
	}
	reverse(ord.begin(),ord.end());
	for(auto j:ord){
		if(vis[j]==0){
			cur++;
			dfs2(j);
		}
	}
	for(llo i=0;i<n;i++){
		for(auto j:adj[i]){
			llo cc=j.b;
			llo low=0;
			for(int j=19;j>=0;j--){
				if(((low+(1LL<<j))*(low+(1LL<<j)+1))/2<=cc){
					low+=(1LL<<j);
				}
			}
			llo su=cc*(low+1);
			su-=pre[low];
			if(vis[j.a]==vis[i]){
				val[vis[i]]+=su;
			}
			else{
				adj3[vis[i]].pb({vis[j.a],j.b});
				adj4[vis[j.a]].pb({vis[i],j.b});
				co[vis[i]]++;
			}
		}
	}
	queue<llo> ss;
	for(llo i=1;i<=n;i++){
		if(co[i]==0){
			dp[i]=val[i];
			ss.push(i);
		}
	}
	llo ans=0;
	while(ss.size()){
		llo no=ss.front();
		ss.pop();
		dp[no]=val[no];
		for(auto j:adj3[no]){
			dp[no]=max(dp[no],val[no]+j.b+dp[j.a]);
		}
		for(auto j:adj4[no]){
			co[j.a]--;
			if(co[j.a]==0){
				ss.push(j.a);
			}
		}
		if(no==vis[kk]){
			ans=max(ans,dp[no]);
		}
	}
	cout<<ans<<endl;

	
	



 
	return 0;
}