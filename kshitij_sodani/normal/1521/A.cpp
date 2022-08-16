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
		llo aa,bb;
		cin>>aa>>bb;
		if(bb==1){
			cout<<"NO"<<endl;
		}
		else if(bb>2){
			cout<<"YES"<<endl;
			cout<<aa<<" "<<aa*(bb-1)<<" "<<aa*bb<<endl;
		}
		else{
			cout<<"YES"<<endl;
			cout<<aa<<" "<<2*aa*bb-aa<<" "<<2*aa*bb<<endl;
		}
	}







	return 0;
}