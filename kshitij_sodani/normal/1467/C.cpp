//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
llo it[3];
vector<llo> pre[3];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	for(llo i=0;i<3;i++){
		cin>>it[i];
	}
	for(llo i=0;i<3;i++){
		llo aa;
		for(llo j=0;j<it[i];j++){
			cin>>aa;
			pre[i].pb(aa);
		}
		sort(pre[i].begin(),pre[i].end());
	}
	llo ans=-(llo)1e18;
	for(llo i=0;i<3;i++){
		llo cur=0;
		vector<llo> ss;
		for(llo j=0;j<3;j++){
			for(auto jj:pre[j]){
				cur+=jj;
			}
			if(j!=i){
				ss.pb(j);
				cur-=2*pre[j][0];
			}
		}
		ans=max(ans,cur);
		for(auto j:ss){
			cur=0;
			for(llo ii=0;ii<3;ii++){
				if(ii!=j){
					for(auto jj:pre[ii]){
						cur+=jj;
					}
				}
				else{
					for(auto jj:pre[ii]){
						cur-=jj;
					}
				}
			}
			ans=max(ans,cur);
		}
	}
	cout<<ans<<endl;
 
 
 
 
 
 
	return 0;
}