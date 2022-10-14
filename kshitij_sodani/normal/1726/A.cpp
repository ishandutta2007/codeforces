#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;
llo it[2001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ma=0;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i>0){
				ma=max(ma,it[i]);
			}
		}
		llo ans=ma-it[0];
		llo mi=1e9;
		for(llo i=0;i<n-1;i++){
			mi=min(mi,it[i]);
		}
		ans=max(ans,it[n-1]-mi);
		for(llo i=0;i<n;i++){
			ans=max(ans,it[(i+n-1)%n]-it[i]);
		}
		cout<<ans<<endl;
	}






	return 0;
}