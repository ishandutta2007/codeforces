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
		int n;
		int x;
		cin>>n;
		int co=0;
		for(int i=0;i<2*n;i++){
			cin>>x;
			if(x%2==0){
				co++;
			}
		}
		if(co==n){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}

	return 0;
}