#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo n;
llo it[500001];
llo ans=0;
llo ma=0;
llo dp[500001];
llo dp2[500001];
llo dp3[500001][2];
void solve(){
	llo ind=-1;
	for(llo i=0;i<n;i++){
		if(it[i]==ma){
			ind=i;
		}
	}
	for(llo i=0;i<n;i++){
		if(i==0){
			dp[i]=-1;
		}
		else{
			if(dp[i-1]<-1){
				dp[i]=-2;
				continue;
			}
			if(it[i]>it[i-1] and it[i]>dp[i-1]){
				dp[i]=min(it[i-1],dp[i-1]);
			}
			else if(it[i]>it[i-1]){
				dp[i]=dp[i-1];
			}
			else if(it[i]>dp[i-1]){
				dp[i]=it[i-1];
			}
			else{
				dp[i]=-2;
			}
		}
	}
	for(llo i=n-1;i>=0;i--){
		if(i==n-1){
			dp2[i]=-1;
		}
		else{
			if(dp2[i+1]<-1){
				dp2[i]=-2;
				continue;
			}
			if(it[i]>it[i+1] and it[i]>dp2[i+1]){
				dp2[i]=min(it[i+1],dp2[i+1]);
			}
			else if(it[i]>it[i+1]){
				dp2[i]=dp2[i+1];
			}
			else if(it[i]>dp2[i+1]){
				dp2[i]=it[i+1];
			}
			else{
				dp2[i]=-2;
			}
		}
	}
	//1-min
	//0-max
	dp3[ind][1]=dp2[ind];//last is decreasing
	dp3[ind][0]=-2;
	for(llo i=ind-1;i>=0;i--){
		dp3[i][0]=-2;
		dp3[i][1]=-2;
		if(it[i]<it[i+1] and dp3[i+1][1]>-2){
			dp3[i][1]=dp3[i+1][1];
		}
		if(it[i]<dp3[i+1][0] and dp3[i+1][0]>-2){
			if(dp3[i][1]==-2){
				dp3[i][1]=it[i+1];
			}
			dp3[i][1]=min(dp3[i][1],it[i+1]);
		}
		if(it[i]>it[i+1] and dp3[i+1][0]>-2){
			dp3[i][0]=dp3[i+1][0];
		}
		if(it[i]>dp3[i+1][1] and dp3[i+1][1]>-2){
			if(dp3[i][0]==-2){
				dp3[i][0]=it[i+1];
			}
			dp3[i][0]=max(dp3[i][0],it[i+1]);
		}
	}
	for(llo i=0;i<ind;i++){
		//check if compat
		if(dp3[i][0]>-2 and dp[i]>-2){
			if(dp3[i][0]>dp[i]){
				ans++;
			}
		}
		llo x=dp3[i][0];
	}
	
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;

	for(llo i=0;i<n;i++){
		cin>>it[i];
		ma=max(ma,it[i]);
	}
	solve();
	for(llo i=0;i<n/2;i++){
		swap(it[i],it[n-i-1]);
	}
	solve();
	cout<<ans<<endl;





	return 0;
}