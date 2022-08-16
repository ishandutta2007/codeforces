#include <bits/stdc++.h>
#define a first
#define b second
#define pb push_back
using namespace std;
#define endl '\n'
typedef long long llo;



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1){
			cout<<2<<endl;
			continue;
		}
		if(n%3==0){
			cout<<(n/3)<<endl;
		}
		else if(n%3==2){
			cout<<((n+1)/3)<<endl;
		}
		else{
			cout<<(n+2)/3<<endl;
		}
	}








	return 0;
}