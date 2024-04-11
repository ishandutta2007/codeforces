//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[3001];
llo dp[3001];
vector<pair<llo,llo>> cot[3001];

/*#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>
*/
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		dp[0]=0;
		for(int i=0;i<=n;i++){
			cot[i].clear();
		}
		for(llo i=1;i<n;i++){
			dp[i]=n;
			llo cur=0;
			for(auto j:cot[i]){
				dp[j.a]=min(dp[j.a],j.b);
			}
			for(llo j=i-1;j>=0;j--){
				if(it[j]+j>=i){
					cot[it[j]+j+1].pb({i,dp[j]+cur});
					if(i==n-1){
						dp[i]=min(dp[i],dp[j]+cur);
					}
					//dp[i]=min(dp[i],dp[j]+cur);
				}
				if(it[j]+j>=i){
					cur+=1;
				}
			}
			/*for(int i=0;i<n;i++){
				cout<<dp[i]<<",";
			}
			cout<<endl;*/

		}
		/*for(auto j:cot[n]){
			dp[j.a]=min(dp[j.a],j.b);
		}
*/
	/*	for(int i=0;i<n;i++){
			cout<<dp[i]<<",";
		}
		cout<<endl;*/
		cout<<dp[n-1]<<endl;

	}






 
 
	return 0;
}