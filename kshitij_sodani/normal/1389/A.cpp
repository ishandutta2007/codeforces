

#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo a,b;
		cin>>a>>b;
		if(2*a>b){
			cout<<"-1 -1"<<endl;
		}
		else{
			cout<<a<<" "<<2*a<<endl;
		}
	}


	return 0;
}