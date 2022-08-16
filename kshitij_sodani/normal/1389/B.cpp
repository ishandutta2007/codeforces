

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

llo t;
llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n,k,z;
		cin>>n>>k>>z;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=0;i<=z;i++){
			llo cur=k-2*i;
			if(cur<0){
				continue;
			}
			llo co=it[0];
			llo ma=0;
			for(llo j=1;j<=cur;j++){
				co+=it[j];
				ma=max(ma,it[j]+it[j-1]);
			}
			co+=ma*i;
			ans=max(ans,co);
			if(i<z){
				if(cur>1){
					cur-=1;
					llo co2=it[0];
					llo ma2=0;
					for(llo j=1;j<=cur;j++){
						co2+=it[j];
						ma2=max(ma2,it[j]+it[j-1]);
					}
					co2+=ma*i;
					co2+=it[cur-1];
					ans=max(ans,co2);
				}
			}
		}
		cout<<ans<<endl;



	}


	return 0;
}