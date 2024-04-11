#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	llo t;
	cin>>t;
	while(t--){
		llo n;
		cin>>n;
		if(n%3==0){
			for(llo i=0;i<(n/3);i++){
				cout<<21;
			}
			cout<<endl;
		}
		else if(n%3==1){
			cout<<1;
			for(llo i=0;i<(n/3);i++){
				cout<<21;
			}
			cout<<endl;
		}
		else{
			cout<<2;
			for(llo i=0;i<(n/3);i++){
				cout<<12;
			}
			cout<<endl;
		}
	}





	return 0;
}