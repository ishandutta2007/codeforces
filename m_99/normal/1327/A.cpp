#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		long long n,k;
		cin>>n>>k;
		
		long long S = k*(k+1)-k;
		
		if(S>n)cout<<"NO"<<endl;
		else cout<<(((n-S)%2==0)?"YES":"NO")<<endl;
	}
	
    return 0;
}