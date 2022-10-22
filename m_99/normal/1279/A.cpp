#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		long long r,g,b;
		cin>>r>>g>>b;
		
		long long s = r+g+b;
		
		long long m = max({r,g,b});
		
		if((s+1)/2>=m){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	

    return 0;
}