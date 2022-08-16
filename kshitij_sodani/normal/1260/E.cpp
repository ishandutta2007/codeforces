#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
llo n;
vector<llo> it;
llo dp[300001][20];
llo dp2[20];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	llo st=1;
	llo co=0;
	llo x=1;
	while(x!=n){
		x*=2;
		co+=1;
	}
	for(llo i=0;i<n;i++){
		llo aa;
		cin>>aa;
		if(aa==-1){
			st=0;
			continue;
		}
		if(st){
			it.pb(0);
		}
		else{
			it.pb(aa);
		}
	}
	for(llo i=0;i<n;i++){
		for(llo j=0;j<=co;j++){
			dp[i][j]=-1;
			dp2[j]=-1;
		}
	
	}
	//memset(dp,(llo)-1,sizeof(dp));
//	memset(dp2,(llo)-1,sizeof(dp2));
	dp[0][0]=0;
	dp2[0]=0;
	for(llo i=1;i<n;i++){
		for(llo j=1;j<=co;j++){
			dp[i][j]=-1;
			if(((1<<j)-1)>i){
				continue;
			}
			if(dp2[j-1]!=-1){
				dp[i][j]=dp2[j-1]+it[i-1];
		//		cout<<i<<":"<<j<<":"<<dp[i][j]<<endl;
			}
		}
		for(llo j=1;j<=co;j++){
			if(dp[i][j]!=-1){
				if(dp2[j]==-1){
					dp2[j]=dp[i][j];
				}
				else{
					dp2[j]=min(dp[i][j],dp2[j]);
				}
			}
		}
	}
	cout<<dp[n-1][co]<<endl;


	return 0;
}