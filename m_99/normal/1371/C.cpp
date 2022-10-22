#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long a,b,n,m;
		cin>>a>>b>>n>>m;
		if(m>min(a,b)){
			cout<<"No"<<endl;
			continue;
		}
		if(n>a+b-m){
			cout<<"No"<<endl;
			continue;
		}
		cout<<"Yes"<<endl;
	}
	
	return 0;
}