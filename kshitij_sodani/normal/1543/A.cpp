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
		if(aa>bb){
			swap(aa,bb);
		}
		if(aa==bb){
			cout<<"0 0"<<endl;
			continue;
		}
		llo xx=(bb-aa);
		llo mi=min(bb%xx,(xx-(bb%xx))%xx);
		cout<<xx<<" "<<mi<<endl;
	}



 
 
 
 
 
 
 
	return 0;
}