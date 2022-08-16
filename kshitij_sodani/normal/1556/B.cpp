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
		vector<llo> aa;

		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]%2==0){
				aa.pb(i);
			}
		}
		llo ans=-1;
		if(aa.size()==((n+1)/2)){
			vector<llo> bb;
			for(llo j=0;j<n;j+=2){
				bb.pb(j);
			}
			llo su=0;
			for(llo j=0;j<aa.size();j++){
				su+=abs(aa[j]-bb[j]);
			}
			ans=su;
		}
		if(aa.size()==(n/2)){
			vector<llo> bb;
			for(llo j=1;j<n;j+=2){
				bb.pb(j);
			}
			llo su=0;
			for(llo j=0;j<aa.size();j++){
				su+=abs(aa[j]-bb[j]);
			}
			if(ans==-1){
				ans=su;
			}
			ans=min(ans,su);
		}
		cout<<ans<<endl;



	}



 
 
 
	return 0;
}