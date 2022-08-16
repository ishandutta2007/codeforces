//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo n,m;
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	vector<pair<pair<llo,llo>,llo>> ss;
	llo ans=1;

	for(llo i=0;i<n;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		if(bb==0 and cc==1000000){
			ans++;
		}
			ss.pb({{bb,-10000001},aa});
			ss.pb({{cc,1},aa});
		
	}
	//llo ans=0;
	for(llo i=0;i<m;i++){
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		if(bb==0 and cc==1000000){
			ans++;
		}
			ss.pb({{aa,-bb},cc});
		
	}

	/*if(ss.size()==0){
		cout<<1<<endl;
		return 0;
	}*/
	//ss.pb({{0,0},1e6});
	sort(ss.begin(),ss.end());
	ord tt;
	//tt.insert(0);
	//tt.insert(1e6);
	

	for(auto j:ss){
	//	tt.insert(0);
	//	tt.insert(1000000);

		if(j.a.b==-10000001){
			tt.insert(j.b);
		}
		else if(j.a.b==1){
			tt.erase(j.b);
		}
		else{
			/*for(auto jj:tt){
				cout<<jj<<",,";
			}
			cout<<endl;*/

			llo xx=tt.order_of_key(j.b+1)-tt.order_of_key(-j.a.b);
			//cout<<j.a.a<<","<<xx<<endl;
			if(xx>0){
				ans+=xx;
			}
		}
	}
	cout<<ans<<endl;








 
 
	return 0;
}