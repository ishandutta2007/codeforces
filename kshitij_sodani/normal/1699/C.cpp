#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

const llo mod=1e9+7;
llo it[100001];
llo ind[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=1;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ind[it[i]]=i;
		}
		llo mi=ind[0];
		llo ma=ind[0];
		for(llo i=1;i<n;i++){
			if(ind[i]<mi){
				mi=ind[i];
				continue;
			}
			if(ind[i]>ma){
				ma=ind[i];
				continue;
			}
			ans=(ans*((ma-mi+1)-i))%mod;
		}
		cout<<ans<<endl;
	}






	return 0;
}