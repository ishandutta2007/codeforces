#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

long long gcd(long long a, long long b){
	if (b == 0) return a;
	return gcd(b, a % b);
}


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int a,b;
		cin>>a>>b;
		
		if(a==1||b==1){
			cout<<"Finite"<<endl;
			continue;
		}
		
		if(gcd(a,b)==1){
			cout<<"Finite"<<endl;
		}
		else{
			cout<<"Infinite"<<endl;
		}
	}
		
	
    return 0;
}