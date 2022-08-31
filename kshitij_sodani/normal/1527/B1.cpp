
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

llo it[100001];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		string s;
		cin>>s;
		int co=0;
		for(int i=0;i<n;i++){
			if(s[i]=='0'){
				co++;
			}
		}
		if(co==1){
			cout<<"BOB"<<endl;
			continue;
		}
		if(n%2==1){
			if(s[n/2]=='0'){

				cout<<"ALICE"<<endl;
				continue;
			}
		}
		if(co>0){
			cout<<"BOB"<<endl;
		}
		else{
			cout<<"DRAW"<<endl;
		}






	}






	return 0;
}