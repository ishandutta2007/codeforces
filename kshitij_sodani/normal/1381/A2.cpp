#include <bits/stdc++.h>
using namespace std;
typedef int64_t llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		string aa;
		string bb;
		cin>>aa>>bb;
		int st=0;
		int endd=n-1;
		vector<int> ans;
		

		for(int i=0;i<n;i++){
			if((aa[st]!=bb[n-i-1] and i%2==0) or(aa[st]==bb[n-i-1] and i%2==1)){
				ans.pb(n-i);
				swap(st,endd);
				if(st>endd){
					endd+=1;
				}
				else{
					endd-=1;
				}
			}
			else{
				ans.pb(1);
				ans.pb(n-i);
				swap(st,endd);
				if(st>endd){
					endd+=1;
				}
				else{
					endd-=1;
				}
			}
		}
		cout<<ans.size()<<" ";
		for(auto i:ans){
			cout<<i<<" ";
		}
		cout<<endl;
	}

	





	return 0;
}