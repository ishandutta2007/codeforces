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
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		set<int> ss;
		for(int i=0;i<n;i++){
			int aa;
			cin>>aa;
			ss.insert(aa);
		}
		int ans=0;
		for(int i=0;i<m;i++){
			int aa;
			cin>>aa;
			if(ss.find(aa)!=ss.end()){
				ans++;
			}

		}
		cout<<ans<<endl;
	}






 
 
	return 0;
}