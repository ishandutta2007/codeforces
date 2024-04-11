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
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		vector<int> ind;
		for(int i=0;i<n;i++){
			if(s[i]=='1'){
				ind.pb(i);
			}
		}
		if(ind.size()==0){
			cout<<0<<endl;
			continue;
		}
		int ans=11;
		ans*=ind.size();
		if(ind.size()==1){
			int x=ind[0];
			if(n-x-1<=k){
				ans-=10;
			}
			else if(x<=k){
				ans-=1;
			}
		}
		else{

			if(n-ind.back()-1<=k){
				ans-=10;
				k-=(n-ind.back()-1);
			}
			if(ind[0]<=k){
				ans-=1;
			}

		}

		cout<<ans<<endl;
	}







	return 0;
}