#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

int it[5010];
int dp[5010];

int co[5010];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>it[i];
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			vector<int> ss;
			ss.pb(0);
			for(int j=0;j<n;j++){
				if(it[j]==i){
					ss.pb(j+1);
				}
			}

			ss.pb(n+1);
			if(ss.size()>2){
				dp[0]=0;
				for(int j=1;j<ss.size();j++){
					dp[j]=-1e9;
					int ma=0;
					for(int ii=j-1;ii>=0;ii--){

						for(int jj=ss[ii]+1;jj<ss[ii+1];jj++){
							co[it[jj-1]]++;
							
							ma=max(ma,co[it[jj-1]]);
						}

						
						if(ma+ma<=ss[j]-ss[ii]-1){
							if((ss[j]-ss[ii]-1)%2==0){
								dp[j]=max(dp[j],dp[ii]+1);
							}
						}
					}
					for(int ii=0;ii<=n;ii++){
						co[ii]=0;
					}
				}


				ans=max(ans,dp[ss.size()-1]-1);
			}
		}
		cout<<ans<<endl;
	}






	return 0;
}