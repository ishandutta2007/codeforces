//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
//llo it[1001];
vector<pair<llo,llo>> pre[200002];
vector<llo> mi[200002];
llo dp[200002];//next is type 2
llo dp2[200002];//next is type 1
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,m;
		cin>>n>>m;
		set<llo> ss;
		vector<llo> tt;
		for(llo i=0;i<n;i++){
			llo x;
			cin>>x;
			ss.insert(x);

		}
		for(llo i=0;i<=n;i++){
			pre[i].clear();
			mi[i].clear();
		}
		for(auto j:ss){
			tt.pb(j);
		}
		pre[0].pb({tt[0],tt[0]});
		for(llo i=1;i<=tt.size();i++){
			pre[i].pb({tt[i-1],tt[i-1]});
		}

		for(llo j=0;j<m;j++){
			llo aa,bb;
			cin>>aa>>bb;

			auto jj=ss.lower_bound(aa);
			if(jj!=ss.end()){
				if((*jj)<=bb){
					continue;
				}
			}
			if(jj==ss.end()){	
				pre[tt.size()].pb({aa,bb});
			}
			else if(jj==ss.begin()){
				pre[0].pb({aa,bb});
			}
			else{
				llo ind=lower_bound(tt.begin(),tt.end(),*jj)-tt.begin();
				pre[ind].pb({aa,bb});
			}
		}
		for(llo i=0;i<=tt.size();i++){
			sort(pre[i].begin(),pre[i].end());
			llo mi2=pre[i].back().b;
			for(llo j=pre[i].size()-1;j>=0;j--){
				mi2=min(mi2,pre[i][j].b);
				mi[i].pb(mi2);
			}
			reverse(mi[i].begin(),mi[i].end());

		}
		if(tt.size()==1){
			llo co=tt[0]-mi[0][0];
			llo co2=pre[1].back().a-tt[0];
			llo ans=co+co2;
			ans+=min(co,co2);
			cout<<ans<<endl;
		}
		else{
			for(llo i=0;i<=tt.size();i++){
				dp[i]=1e18;
				dp2[i]=1e18;
			}
			for(llo i=0;i+1<tt.size();i++){

				if(i>0){

					for(llo j=0;j<pre[i+1].size();j++){
						llo ne;
						if(j+1<pre[i+1].size()){
							ne=mi[i+1][j+1];
						}
						else{
							ne=tt[i+1];
						}
						dp[i]=min(dp[i],dp[i-1]+(pre[i+1][j].a-tt[i])+2*(tt[i+1]-ne));
						dp[i]=min(dp[i],dp2[i-1]+2*(pre[i+1][j].a-tt[i])+2*(tt[i+1]-ne));
						dp2[i]=min(dp2[i],dp[i-1]+(pre[i+1][j].a-tt[i])+(tt[i+1]-ne));
						dp2[i]=min(dp2[i],dp2[i-1]+2*(pre[i+1][j].a-tt[i])+(tt[i+1]-ne));
					}
				}
				else{
					for(llo j=0;j<pre[i+1].size();j++){
						llo ne;
						if(j+1<pre[i+1].size()){
							ne=mi[i+1][j+1];
						}
						else{
							ne=tt[i+1];
						}
						llo co=tt[0]-mi[0][0];
						llo co2=pre[i+1][j].a-tt[0];
						llo co3=co+co2+min(co,co2);
						dp[i]=min(dp[i],co3+2*(tt[i+1]-ne));
						dp[i]=min(dp[i],co3+2*(tt[i+1]-ne));
						dp2[i]=min(dp2[i],co3+(tt[i+1]-ne));
						dp2[i]=min(dp2[i],co3+(tt[i+1]-ne));
					}
				}
			}
			llo ans=min(dp[tt.size()-2]+pre[tt.size()].back().a-tt.back(),dp2[tt.size()-2]+2*(pre[tt.size()].back().a-tt.back()));
			cout<<ans<<endl;
		}


	}


 
 
 
	return 0;
}