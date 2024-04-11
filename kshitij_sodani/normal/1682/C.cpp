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
		map<llo,llo> ss;
		for(llo i=0;i<n;i++){
			cin>>it[i];
			ss[it[i]]++;
		}
		llo ans=0;
		llo co=0;
		for(auto j:ss){
			if(j.b>=2){
				ans++;
			}
			else{
				co++;
			}
		}
		ans+=((co+1)/2);
		cout<<ans<<endl;
	}











	return 0;
}