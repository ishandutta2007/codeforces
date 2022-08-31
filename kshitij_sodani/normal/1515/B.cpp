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
		if(n%2==1){
			cout<<"NO"<<endl;
			continue;
		}
		n/=2;
		while(n%2==0){
			n/=2;
		}
		llo x=sqrt(n);
		if(x*x==n){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}

	}










	return 0;
}