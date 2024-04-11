#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int beki(int a,int b){
	int x = 1;
	while(b!=0){
		if(b&1){
			x=mod(x*a);
		}
		a=mod(a*a);
		b>>=1;
	}
	return x;
}

int main(){
	
	int w,h;
	cin>>w>>h;
	
	cout<<mod(4 * beki(2,w+h-2))<<endl;
	
    return 0;
}