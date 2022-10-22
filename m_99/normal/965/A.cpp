#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int k,n,s,p;
	cin>>k>>n>>s>>p;
	
	int x = (n+s-1)/s;
	
	cout<<(x*k+p-1)/p<<endl;
	
    return 0;
}