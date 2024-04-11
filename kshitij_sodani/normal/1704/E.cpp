#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
const llo mod=998244353;

vector<int> adj[1001];
vector<int> adj2[1001];
int it[1001];
int co[1001];
int tt[1001];
llo dp[1001][1001];
pair<llo,llo> val[1001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<n;i++){
			cin>>it[i];
			tt[i]=it[i];
		}
		for(int i=0;i<n;i++){
			adj[i].clear();
			adj2[i].clear();
			val[i]={0,it[i]};//ending time


		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				dp[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			int aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			adj[aa].pb(bb);
			adj2[bb].pb(aa);
		}
		int xx=0;
		queue<int> ss;
		for(int i=0;i<n;i++){
			co[i]=adj2[i].size();
			if(adj2[i].size()==0){
				ss.push(i);
			}
		}
		vector<llo> ee;
		while(ss.size()){
			int no=ss.front();
			ss.pop();
			ee.pb(no);
			for(auto j:adj[no]){
				co[j]--;
				if(co[j]==0){
					co[j]=1;
					ss.push(j);
				}
			}
		}
		for(int i=0;i<n;i++){
			for(auto j:ee){
				if(j==i){
					dp[j][i]=1;
				}
				for(auto jj:adj2[j]){
					dp[j][i]+=dp[jj][i];
					if(dp[j][i]>=mod){
						dp[j][i]-=mod;
					}
				}
			}
		}
		int coo=0;
		llo ans=0;
		llo st=0;
		for(int i=0;i<=1000;i++){
			vector<int> ss;
			for(auto j=0;j<n;j++){
				if(tt[j]>0){
					ss.pb(j);
				}
			}
			if(ss.size()==0){
				st=1;
				ans=i;
				break;
			}
			if(tt[ee.back()]==0){
				ans=(ans+1)%mod;
			}
			for(auto j:ss){
				tt[j]--;
				for(auto ii:adj[j]){
					tt[ii]++;
				}
			}


		}
		if(st==1){
			cout<<ans<<endl;
			continue;
		}
		for(int i=0;i<n;i++){
			ans+=(dp[ee.back()][i]*it[i]);
			ans%=mod;
		}

		cout<<ans<<endl;
		
	}







	return 0;
}