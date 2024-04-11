#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,z;
		cin>>n>>z;
		llo ans=0;
		for(llo i=0;i<n;i++){
			llo aa;
			cin>>aa;
			ans=max(ans,(aa|z));
		}
		cout<<ans<<endl;
	}





	return 0;
}