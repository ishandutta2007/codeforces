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
		int n,m;
		cin>>n>>m;
		if(n==1 and m==1){
			cout<<0<<endl;
			continue;
		}
		if(n==1 or m==1){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}



 
	return 0;
}