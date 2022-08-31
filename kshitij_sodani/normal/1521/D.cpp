//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
vector<pair<int,int>> adj[100001*2];
int dp[100001][2];
vector<int> adj2[100001*2];
vector<int> adj3[100001*2];
int vis[100001*2];
void dfs(int no,int par=-1){
	vector<pair<int,int>> ss;
	dp[no][0]=0;//can take in new segment
	dp[no][1]=0;//cannot take

	for(auto j:adj[no]){
		if(j.a!=par){
			dfs(j.a,no);
			ss.pb({dp[j.a][0]+1-dp[j.a][1],j.a});
		
		}
	}
	sort(ss.begin(),ss.end());
	reverse(ss.begin(),ss.end());
	for(auto j:ss){
		dp[no][0]+=dp[j.b][1];
		dp[no][1]+=dp[j.b][1];


	}
	for(int i=0;i<2;i++){
		if(i==ss.size()){
			break;
		}
		if(ss[i].a<0){
			continue;
		}
		if(i==0){
			dp[no][0]+=ss[i].a;
			adj2[no*2].pb(2*ss[i].b);
		}
		dp[no][1]+=ss[i].a;
		adj2[no*2+1].pb(2*ss[i].b);
	}
	//dp[no][1]=max(dp[no][1],dp[no][0]);
	//cout<<no<<":"<<dp[no][0]<<":"<<dp[no][1]<<endl;
}
vector<pair<int,int>> xx;
void dfs2(int no){
	vis[no]=1;
	for(auto j:adj2[no]){
		if(vis[j]==0){
			adj3[no/2].pb(j/2);
			adj3[j/2].pb(no/2);
			dfs2(j);
		}
	}
	for(auto j:adj[no/2]){
		if(vis[2*j.a]==0 and vis[2*j.a+1]==0){
			xx.pb({no/2,j.a});
			dfs2(2*j.a+1);
		}
	}
}
int kk=-1;
void dfs3(int no){
	vis[no]=1;
	kk=no;
	for(auto j:adj3[no]){
		if(vis[j]==0){
			dfs3(j);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			adj[i].clear();
			adj3[i].clear();
			//adj2[i].clear();
		}
		for(int i=0;i<2*n;i++){
			adj2[i].clear();
			vis[i]=0;
		}
		for(int i=0;i<n-1;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb({bb,i});
			adj[bb].pb({aa,i});
		}
		xx.clear();
		dfs(0);
		dfs2(1);
		for(int i=0;i<n;i++){
			vis[i]=0;
		}	
		vector<int> ee;
		vector<int> ff;

		for(int i=0;i<n;i++){
			if(adj3[i].size()<=1){
				if(vis[i]==0){
					ee.pb(i);
					dfs3(i);
					ff.pb(kk);
				}
			}
		}
		/*for(auto j:ee){
			cout<<j<<":";
		}
		cout<<endl;
		for(auto j:ff){
			cout<<j<<":";
		}
		cout<<endl;*/
		cout<<(n-1)-dp[0][1]<<endl;
		for(int i=0;i<(n-1)-dp[0][1];i++){
			cout<<xx[i].a+1<<" "<<xx[i].b+1<<" "<<ff[i]+1<<" "<<ee[i+1]+1<<endl;
		}

	}








	return 0;
}