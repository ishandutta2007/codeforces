//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[1000001];
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		/*for(llo i=0;i<n;i++){
			cin>>it[i];
		}*/

		if(n==1){
			cout<<1<<endl;
		}
		else{
			llo ans=1;
			for(llo j=0;j<k;j++){
				ans=(ans*n)%mod;
			}
			cout<<ans<<endl;
		}
	}



 
 
	return 0;
}