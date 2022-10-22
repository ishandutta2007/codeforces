#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		long long x;
		cin>>x;
		
		long long a = x/14;
		long long b = x%14;
		if(a<=0){
			cout<<"NO"<<endl;
			continue;
		}
		if(b>=1&&b<=6){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
	return 0;
}