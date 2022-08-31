//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo it[101];
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
		llo ans=n-1;
		for(llo i=0;i<n;i++){
			for(llo j=i+1;j<n;j++){
				pair<llo,llo> xx={it[j]-it[i],j-i};
				llo co=n;
				for(llo x=0;x<n;x++){
					//it[i]+(x-i)*xx;
					pair<llo,llo> yy={(x-i)*xx.a,xx.b};
					yy.a+=yy.b*it[i];
					if((yy.a%yy.b)==0){
						if((yy.a/yy.b)==it[x]){
							co--;
						}
					}
				}
				ans=min(ans,co);
			}
		}
		cout<<ans<<endl;
	}







 
	return 0;
}