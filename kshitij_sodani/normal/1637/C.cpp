//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo st=1;
		llo co=0;
		llo ma=0;
		for(llo i=1;i+1<n;i++){
			ans=(ans+(it[i]+1)/2);
			if(it[i]%2==0){
				st=0;
			}
			ma=max(ma,it[i]);
			
			co+=(it[i]/2);
		}
		if(st==0 ){
			cout<<ans<<endl;	
		}
		else if(n-2>1 and ma>1){
			cout<<ans<<endl;
		}
		else{
			cout<<-1<<endl;
		}
		

	}



	


 
	return 0;
}