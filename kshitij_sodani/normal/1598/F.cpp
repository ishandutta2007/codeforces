//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>


vector<llo> pre[21];
map<llo,llo> ind[21];
vector<ord> pre2[21];
vector<llo> ma[21];
llo dp[1<<21][2];
llo tt[21];
llo mi[21];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo n;
	cin>>n;
	ord pp;
	for(llo i=0;i<n;i++){
		string s;
		cin>>s;
		llo su=0;
		llo xx=0;
		for(llo j=0;j<s.size();j++){
			if(s[j]=='('){
				su++;
			}
			else{
				su--;
			}
			if(ind[i].find(su)!=ind[i].end()){

			}
			else{
				ind[i][su]=xx;
				xx++;
				pre2[i].pb(pp);
			}

			//pre[i][su]++;
			mi[i]=min(mi[i],su);
			pre[i].pb(su);
			ma[i].pb(su);
			pre2[i][ind[i][su]].insert(j);
			if(ma[i].size()>1){
				ma[i][j]=min(ma[i][j],ma[i][j-1]);
			}
		}
		tt[i]=su;

	}
	llo ans=0;
	//return 0;
	for(llo i=1;i<(1<<n);i++){
		vector<llo> ss;
		llo kk=0;
		for(llo j=0;j<n;j++){
			if((1<<j)&i){
				ss.pb(j);
				kk+=tt[j];
			}
		}
		dp[i][0]=-1;
		dp[i][1]=0;
		for(auto j:ss){
			llo cur=kk-tt[j];
			if(dp[i-(1<<j)][0]==-1){
				continue;
			}
			if(cur+pre[j][0]<0){
				continue;
			}
			//continue;
		//	continue;
			llo low=0;
			for(int k=19;k>=0;k--){
				if(low+(1<<k)<ma[j].size()){
					if(ma[j][low+(1<<k)]+cur>=0){
						low+=(1<<k);
					}
				}

			}
			//find number of -cur in low;
			llo cot=0;
			if(ind[j].find(-cur)!=ind[j].end()){
				cot+=pre2[j][ind[j][-cur]].order_of_key(low+1);
			}
			/*
			if(pre[j].find(-cur)!=pre[j].end()){
				cot=pre[j][-cur];
			}*/

			

			if(low+1<ma[j].size()){
				dp[i][1]=max(dp[i][1],dp[i-(1<<j)][0]+cot);
			}
			else{
				dp[i][0]=max(dp[i][0],dp[i-(1<<j)][0]+cot);
			}
		}
		dp[i][1]=max(dp[i][1],dp[i][0]);
		ans=max(ans,dp[i][1]);
	}
	cout<<ans<<endl;



	
 
 
	return 0;
}