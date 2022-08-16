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
		llo aa,bb,cc;
		cin>>aa>>bb>>cc;
		cc*=2;
		aa+=bb;
		if((aa%3)==(cc%3)){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}



 
	return 0;
}