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
		int n,k;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			if(i%3==0){
				cout<<"a";
			}
			else if(i%3==1){
				cout<<"b";
			}
			else{
				cout<<"c";
			}
		}
		cout<<endl;
	}









 
	return 0;
}