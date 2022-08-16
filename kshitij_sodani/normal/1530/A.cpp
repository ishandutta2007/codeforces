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
		llo ans=0;
		llo n;
		cin>>n;
		while(n){
			ans=max(ans,n%10);
			n/=10;
		}
		cout<<ans<<endl;
	}
 
 
 
 
 
 
 
	return 0;
}