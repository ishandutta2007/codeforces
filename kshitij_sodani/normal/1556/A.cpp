//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'
llo t;

int main(){
	ios_base::sync_with_stdio(false);
	cin>>t;

	while(t--){
		int aa,bb;
		cin>>aa>>bb;
		if(aa==0 and bb==0){
			cout<<0<<endl;
		}
		else if(aa==bb){
			cout<<1<<endl;
		}
		else if((aa%2)==(bb%2)){
			cout<<2<<endl;
		}
		else{
			cout<<-1<<endl;
		}


	}


 
 
 
	return 0;
}