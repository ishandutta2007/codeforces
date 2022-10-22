#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	long long n,m,a;
	cin>>n>>m>>a;
	
	cout<<((n+a-1)/a) * ((m+a-1)/a)<<endl;
				
	
	
	return 0;
}