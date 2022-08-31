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
		int aa,bb,cc;
		cin>>aa>>bb>>cc;
		if((aa+bb+cc)%9==0 and min(aa,min(bb,cc))>=((aa+bb+cc))/9){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}


	}






 
	return 0;
}