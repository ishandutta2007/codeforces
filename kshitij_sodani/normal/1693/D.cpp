#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
llo it[200001];
llo dp[200001][2];
//0 in increasing.so malloain maximum possible last element
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=n-1;i>=0;i--){
			dp[i][0]=1e9;
			dp[i][1]=-1e9;
			for(llo j=i+1;j<n;j++){
				llo x=dp[j][0];
				llo y=dp[j][1];
				dp[j][0]=-1e9;
				dp[j][1]=1e9;
				if(it[j-1]<it[j]){
					dp[j][0]=max(dp[j][0],dp[j-1][0]);
				}
				if(it[j-1]>it[j]){
					dp[j][1]=min(dp[j][1],dp[j-1][1]);
				}
				if(dp[j-1][0]>it[j]){
					dp[j][1]=min(dp[j][1],it[j-1]);
				}
				if(dp[j-1][1]<it[j]){
					dp[j][0]=max(dp[j][0],it[j-1]);
				}
				if(dp[j][0]==x and dp[j][1]==y){
					break;
				}
			}
			llo low=i;
			for(llo j=19;j>=0;j--){
				if(low+(1<<j)<n){
					if(dp[low+(1<<j)][0]==-1e9 and dp[low+(1<<j)][1]==1e9){

					}
					else{
						low+=(1<<j);
					}
				}
			}
			ans+=(low-i+1);

		}
		cout<<ans<<endl;






 
 
 
	return 0;
}