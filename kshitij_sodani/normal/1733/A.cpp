#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;

llo it[101];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n,k;
		cin>>n>>k;
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			if(i<k){
				ss[i]=it[i];
			}
			else{
				ss[i%k]=max(ss[i%k],it[i]);
			}
		}
		llo ans=0;
		for(auto j:ss){
			ans+=j.b;
		}
		cout<<ans<<endl;

	}




	return 0;
}