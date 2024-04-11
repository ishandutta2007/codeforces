//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[200001];
const llo mod=998244353;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<llo,null_type,less<llo>,rb_tree_tag,tree_order_statistics_node_update>
llo su=0;
llo ans=0;
llo pre[200001];
void solve(llo n){
	ord ss;
//	llo su=0;
	llo cot=0;
	for(llo i=n-1;i>=0;i-=2){
		if(i<n-1){
			cot+=it[i];
		}
		ss.insert(pre[n]-pre[i]-cot);
		//x+su>0
		//x>-su
		ans=(ans+(llo)(ss.size())-ss.order_of_key((-su)+1-cot))%mod;
		//for()
		//cout<<i<<":"<<ans<<endl;
		/*if(i==2){
			cout<<cot<<endl;
			for(auto j:ss){
				cout<<j<<".";
			}
			cout<<endl;
		}*/
		if(i>2){
			ans=(ans+(llo)(ss.size())-ss.order_of_key((-su-it[0])+1-cot))%mod;
		}
		//cout<<i<<":"<<ans<<endl;
	}
	ss.clear();
	cot=0;
	for(llo i=n-2;i>=0;i-=2){
		if(i<n-1){
			cot+=it[i];
		}
		ss.insert(pre[n]-pre[i]-cot);
		//x+su>0
		//x>-su
		ans=(ans+(llo)(ss.size())-ss.order_of_key((-su)+1-cot))%mod;
		//for()
		//cout<<i<<":"<<ans<<endl;

		if(i>2){
			ans=(ans+(llo)(ss.size())-ss.order_of_key((-su-it[0])+1-cot))%mod;
		}
	}




}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		ans=0;
		su=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			su+=(-it[i]);
			it[i]*=2;
			pre[i+1]=pre[i]+it[i];
		}

		solve(n);
		if(n-1>0){
			solve(n-1);
		}
		llo su2=0;
		for(int i=0;i<n;i++){
			su2+=it[i];
			if(su2+su>0){
				if(i<n-2){
					ans=(ans+1)%mod;
					//cout<<i<<endl;
				}
			}
		}
		cout<<ans<<endl;



	}


 
 
	return 0;
}