//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[300001];
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<pair<llo,llo>,null_type,less<pair<llo,llo>>,rb_tree_tag,tree_order_statistics_node_update>

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		ord xx;
		llo zz=-1;
		llo cur=0;
		llo ans=0;


		for(llo i=0;i<n;i++){
			zz*=-1;
			cin>>it[i];

			cur+=it[i]*zz;
			xx.insert({it[i]*zz-cur,i});

			
			if(i%2==0){
				while(xx.size()){
					auto j=xx.find_by_order(0);
					if(((*j).a+cur)<0){
						xx.erase(xx.begin());
					}
					else{
						break;
					}
				}
			}
			else{
				while(xx.size()){
					auto j=xx.find_by_order(xx.size()-1);
					
					if(((*j).a+cur)>0){
						xx.erase(j);
					}
					else{
						break;
					}
				}
			}
			ans+=xx.order_of_key({-cur+1,-1})-xx.order_of_key({-cur,-1});

			
		}
		cout<<ans<<endl;

	}





 
	return 0;
}