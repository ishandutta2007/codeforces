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
		cin>>n;
		if(n==1){
			cout<<"a"<<endl;
			continue;
		}
		else if(n==2){
			cout<<"ab"<<endl;
			continue;
		}
		else if(n==3){
			cout<<"abc"<<endl;
			continue;
		}

		string ans="";
		int x,y;

		if(n%2==1){
			x=((n-2)/2);
			y=x+1;
		}
		else{
			x=((n-1)/2);
			y=x+1;
		}
		for(int i=0;i<x;i++){
			ans+="a";
		}
		ans+="b";
		if(n%2==1){
			ans+="c";
		}
		for(int i=0;i<y;i++){
			ans+="a";
		}
		cout<<ans<<endl;

	}
 
 
 

 
	return 0;
}