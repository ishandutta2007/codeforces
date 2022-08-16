#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'
 
int it[1000001];
int dp[5000001];
int vis[5000001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	/*for(int j=1;j<=5e6;j++){
		for(int i=j;i<=5e6;i+=j){
			pre[i].pb(j);
		}
	}*/
	while(t--){
		int n,m;
		cin>>n>>m;
		int mi=m;
		for(int i=0;i<n;i++){
			cin>>it[i];
			mi=min(mi,it[i]);
			vis[it[i]]=1;
		}
 
		
		multiset<int> cur;
		for(int i=0;i<=m;i++){
			dp[i]=1e9;
		}
		int ans=1e9;
		for(int j=m;j>=1;j--){
			dp[j]=j;
			if(vis[j]==1){
				cur.insert(j);
			}
			for(int i=j+j;i<=m;i+=j){
				//if(vis[i]==1){
					int x=dp[i];
					dp[i]=min(dp[i],max(dp[i/j],j));
					if(dp[i]<x){
						if(vis[i]==1){
							auto kk=cur.find(x);
							cur.erase(kk);
							cur.insert(dp[i]);
						}
					}
				//}
			}
			/*if(j==5){
				cout<<dp[35]<<",,"<<endl;
			}*/
 
			if(j<=mi){
				auto jj=cur.end();
				jj--;
				ans=min(ans,(*jj)-j);
			}
		}
		cout<<ans<<endl;
 
 
		for(int i=0;i<n;i++){
			vis[it[i]]=0;
		}
 
 
	}
 
 
 
 
 
 
	return 0;
}