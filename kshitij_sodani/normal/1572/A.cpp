//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<int> adj[200001];
int dp[200001];
int co[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			dp[i]=1;
		}
		for(int i=0;i<n;i++){
			int x;
			cin>>x;
			co[i]=x;
			for(int j=0;j<x;j++){
				int y;
				cin>>y;
				y--;
				adj[y].pb(i);
				
			}
		}
		queue<int> ss;
		for(int i=0;i<n;i++){
			if(co[i]==0){
				ss.push(i);
				dp[i]=1;
			}
		}
		int aa=0;
		int ans=1;
		while(ss.size()){
			int no=ss.front();
			ss.pop();
			aa++;
			//cout<<no<<":"<<endl;
			for(auto j:adj[no]){
				co[j]--;
				dp[j]=max(dp[j],dp[no]);
				if(no>j){
					dp[j]=max(dp[j],dp[no]+1);
				}
				if(co[j]==0){
					ss.push(j);
				}
			}
		}
		if(aa<n){
			cout<<-1<<endl;
		}
		else{
			for(int i=0;i<n;i++){
				ans=max(ans,dp[i]);
			}
			cout<<ans<<endl;
		}

	}



 
 
 
	return 0;
}