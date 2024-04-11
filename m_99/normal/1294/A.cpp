#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int a,b,c,n;
		cin>>a>>b>>c>>n;
		
		int s = a+b+c+n;
		
		if(s%3!=0){
			cout<<"NO"<<endl;
			continue;
		}
		
		s/=3;
		
		if(a>s||b>s||c>s){
			cout<<"NO"<<endl;
		}
		else{
			cout<<"YES"<<endl;
		}
	}
	
	return 0;
}