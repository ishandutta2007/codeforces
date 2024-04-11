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
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		vector<llo> aa;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			aa.pb(it[i]);
		}
		llo ans=0;
		for(llo i=0;i<n-1;i++){
			llo co=2;
			llo ind=i+1;
			llo su=it[i+1]-it[i];
			if(i>0){
				if(it[i]==it[i-1]){
					continue;
				}
			}
			while(ind+1<n){

				if(aa.back()<it[ind]+su){
					break;
				}
				//if(i==0){
				//	cout<<ind<<":"<<su<<endl;
				//}
				//cout<<it[ind]+su<<endl;
				llo x=lower_bound(aa.begin(),aa.end(),it[ind]+su)-aa.begin();
				
			//	cout<<x<<endl;
				//cout<<aa[x]<<endl;
				x=max(x,ind+1);
				su=it[x]-it[i];
				ind=x;
				co++;
			}
			/*if(co==n){
				cout<<i<<endl;
			}*/
			ans=max(ans,co);
		}

		
		cout<<n-ans<<endl;
	}



 
	return 0;
}