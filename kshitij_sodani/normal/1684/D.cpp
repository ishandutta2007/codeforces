#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo it[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		for(llo i=0;i<n;i++){
			cin>>it[i];
		}
		llo ans=0;
		for(llo i=1;i<=k;i++){
			ans+=(n-k+i);
		}
		for(llo i=0;i<n;i++){
			ans+=it[i];
		}
		vector<llo> ss;
		for(llo i=0;i<n;i++){
			ss.pb(-(i+1)-it[i]);
		}
		sort(ss.begin(),ss.end());
		for(llo i=0;i<k;i++){
			ans+=ss[i];
		}
		cout<<ans<<endl;

	}


	







	return 0;
}