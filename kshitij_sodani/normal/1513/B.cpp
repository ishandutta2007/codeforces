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
const llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		vector<llo> ss;
		for(llo i=0;i<30;i++){
			llo co=0;
			for(llo j=0;j<n;j++){
				if(it[j]&(1LL<<i)){
					co++;
				}
			}
			//cout<<i<<":"<<co<<endl;
			if(co<n and co>0){
				ss.pb(i);
			}
		}
		llo ans=1;
		for(llo i=1;i<=n-2;i++){
			ans=(ans*i)%mod;
		}
		/*for(auto j:ss){
			cout<<j<<",";
		}
		cout<<endl;*/
		llo cot=0;
		for(llo i=0;i<n;i++){
			llo co=0;
			for(auto j:ss){
				if((1<<j)&it[i]){
					co++;
				}
			}
			if(co==0){
				cot++;
			}
		}
		llo ans2=(ans*cot)%mod;
		ans2=(ans2*cot)%mod;
		llo ans3=(ans*cot)%mod;
		ans2=(ans2-ans3+mod)%mod;
		cout<<ans2<<endl;


	}



 
 
	return 0;
}