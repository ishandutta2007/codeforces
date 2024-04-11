//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n;
llo it[200001];
llo cc[200001];
llo de[200001];
llo val[200001];
llo dp[200001][3];
llo vis[200001];
vector<llo> adj[200001];
void dfs(int no,int par=-1){
	vector<int> ss;
	vis[no]=1;
	for(auto j:adj[no]){
		if(j!=par){
			dfs(j,no);
			ss.pb(j);
		}
	}
	if(ss.size()==0){
		if(val[no]<-1){
			dp[no][0]=min(dp[no][0],((abs(val[no])/2))*it[no]);
		}
		else if(val[no]==-1){
			dp[no][1]=min(dp[no][1],((abs(val[no])/2))*it[no]);
		}
		else{
			dp[no][2]=min(dp[no][2],((abs(val[no])/2))*it[no]);
		}
	}
	else{
		vector<llo> tt;
		llo su=0;
		for(auto j:ss){
			llo ma=min(dp[j][0]-it[j],dp[j][1]);
			ma=min(ma,dp[j][2]+it[j]);
			llo mi=min(dp[j][0],min(dp[j][1],dp[j][2]));
			su+=ma;
			tt.pb(mi-ma);
		}		
		sort(tt.begin(),tt.end());
		for(int i=0;i<=ss.size();i++){
			if(i>0){
				su+=tt[i-1];
			}
			llo cur=su;
			cur+=((abs(val[no]+2*i)/2)*it[no]);
			if(val[no]+2*i<-1){
				dp[no][0]=min(dp[no][0],cur);
			}
			else if(val[no]+2*i==-1){
				dp[no][1]=min(dp[no][1],cur);
			}
			else{
				dp[no][2]=min(dp[no][2],cur);
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
	}
	for(llo i=0;i<n;i++){
		cin>>cc[i];
	}
	for(llo i=0;i<n-1;i++){
		llo aa,bb;
		cin>>aa>>bb;
		aa--;
		bb--;
		de[aa]++;
		de[bb]++;
		if(cc[aa]!=cc[bb]){
			if(cc[aa]>cc[bb]){
				swap(aa,bb);
			}
			val[aa]--;
			val[bb]++;
		}
		else{
			adj[aa].pb(bb);
			adj[bb].pb(aa);
			val[aa]--;
			val[bb]--;
		}
	//	adj[aa].pb(bb);
	//	adj[bb].pb(aa);
	}
	for(llo i=0;i<n;i++){
		dp[i][0]=1e18;
		dp[i][1]=1e18;
		dp[i][2]=1e18;
	}
	llo ans=0;
	for(int i=0;i<n;i++){
		ans+=(de[i]/2)*it[i];
		if(de[i]%2==1){
			ans+=it[i];
		}
	}
	//cout<<ans<<endl;
	for(int i=0;i<n;i++){
		if(vis[i]==0){
			dfs(i);
			ans+=min(dp[i][0],min(dp[i][1],dp[i][2]));
			//cout<<ans<<":"<<endl;
		}
	}










	cout<<ans<<endl;






 
	return 0;
}