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
llo pre[200001*30][2];
llo dp[200001*30];
llo co=0;
void insert(llo i){
	llo cur=0;
	for(llo j=29;j>=0;j--){
		llo x=0;
		if(i&(1LL<<j)){
			x=1;
		}
		if(pre[cur][x]==0){
			co++;
			pre[cur][x]=co;
		}
		cur=pre[cur][x];
	}
	dp[cur]=1;
//	cout<<cur<<"..."<<endl;
}
void dfs(llo no){
	llo co=0;
	
	for(llo j=0;j<2;j++){
		if(pre[no][j]>0){
			co+=1;
			//cout<<no<<":"<<pre[no][j]<<":"<<j<<endl;
			dfs(pre[no][j]);
			dp[no]=max(dp[no],dp[pre[no][j]]);
		}
	}
	if(co==2){
		dp[no]+=1;
	}
	//cout<<no<<":"<<dp[no]<<endl;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n;
	for(llo i=0;i<n;i++){
		cin>>it[i];
		insert(it[i]);


	}

	dfs(0);
	cout<<n-dp[0]<<endl;



 
 
	return 0;
}