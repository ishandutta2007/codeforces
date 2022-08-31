//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[500001];
llo co[101];
llo mod=1e9+7;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		for(llo i=0;i<60;i++){
			co[i]=0;
		}
		for(llo i=0;i<n;i++){
			cin>>it[i];
			for(llo j=0;j<60;j++){
				if(it[i]&(1LL<<j)){
					co[j]++;
				}
			}
		}
		llo ans=0;
		for(llo i=0;i<n;i++){
			llo val=0;
			llo val2=0;
			for(llo j=0;j<60;j++){
				llo cot=(1LL<<j)%mod;
				if(it[i]&(1LL<<j)){
					val=(val+co[j]*cot)%mod;
					val2=(val2+n*cot)%mod;
				}
				else{
					val2=(val2+co[j]*cot)%mod;
				}

			}
			//cout<<i<<":"<<val<<":"<<val2<<endl;
			ans=(ans+val*val2)%mod;
		}
		cout<<ans<<endl;
	}




 
	return 0;
}