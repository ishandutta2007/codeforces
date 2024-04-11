//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	llo t;
	cin>>t;
	while(t--){
		llo n,x;
		cin>>n>>x;
		vector<pair<llo,llo>> ss;
		for(llo i=0;i<n;i++){
			llo aa;
			cin>>aa;
			ss.pb({aa,1});
		}
		llo ind=0;
		while(ind<ss.size()){
			if(ss[ind].a%x==0){
				ss.pb({ss[ind].a/x,x*ss[ind].b});
				ind++;
			}
			else{
				break;
			}
		}
		llo ans=0;
		for(auto j:ss){
			ans+=j.a*j.b;
		}
		cout<<ans<<endl;

	}




 
	return 0;
}