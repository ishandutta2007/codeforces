#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n,m;
		cin>>n>>m;
		
		if(n%m==0){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	
    return 0;
}