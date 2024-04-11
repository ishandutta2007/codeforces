//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
vector<llo> pre[200001];
vector<llo> pre2[200001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		llo ans=(((n*(n-1)*(n-2))))/6;;
		for(llo i=0;i<n;i++){
			pre[i].clear();
			pre2[i].clear();
		}
		for(llo i=0;i<n;i++){
			llo aa,bb;
			cin>>aa>>bb;
			aa--;
			bb--;
			pre2[bb].pb(aa);
			pre[aa].pb(bb);
		}
		for(llo i=0;i<n;i++){
			llo y=pre[i].size();
			for(auto j:pre[i]){
				llo x=pre2[j].size();
				x--;
				ans-=x*(y-1);
			}
		}
		cout<<ans<<endl;
	}

	
 
 
	return 0;
}