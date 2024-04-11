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
		llo su=0;
		for(llo i=0;i<n;i++){
			llo x;
			cin>>x;
			su+=x;
		}
		if(su%n==0){
			cout<<0<<endl;
		}
		else{
			cout<<1<<endl;
		}
	}	






 
	return 0;
}