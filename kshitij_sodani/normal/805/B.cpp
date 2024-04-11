//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
//#define endl '\n'
/*mt19937 rng;
rng=mt19937(chrono::steady_clock::now().time_since_epoch().count());


#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define ord tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>*/


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		if(i%4<2){
			cout<<'a';
		}
		else{
			cout<<'b';
		}
	}
	cout<<endl;




 
 
	return 0;
}