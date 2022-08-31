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
		llo n;
		cin>>n;
		if(n%2050>0){
			cout<<-1<<endl;
			continue;
		}
		llo x=n/2050;
		llo ans=0;
		while(x>0){
			ans+=(x%10);
			x/=10;
		}
		cout<<ans<<endl;
	}


 
 
	return 0;
}