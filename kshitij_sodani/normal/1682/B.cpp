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
		llo n;
		cin>>n;
		vector<llo> tt;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(it[i]!=i){
				tt.pb(it[i]);
			}
		}
		llo x=tt[0];
		for(auto j:tt){
			x=(x&j);
		}
		cout<<x<<endl;
	}










	return 0;
}