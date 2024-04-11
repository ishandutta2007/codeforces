#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000



int main(){
	
	int n,k;
	cin>>n>>k;
	
	cout<<2*n+(n-k)+(k-1)+1+min(n-k,k-1)<<endl;
	
    return 0;
}