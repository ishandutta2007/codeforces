#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000



int main(){

	int T;
	cin>>T;
	
	for(int _=0;_<T;_++){
		long long A,B;
		cin>>A>>B;
		
		long long x = 1;
		for(int i=0;true;i++){
			x *= 10;
			if(B>=x-1)continue;
			cout<<i*A<<endl;
			break;
		}
	}
	
	return 0;
}