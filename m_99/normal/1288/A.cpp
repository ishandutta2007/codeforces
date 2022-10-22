#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

long long d;

long long func(long long x){
	return x + (d + x)/(x+1);
}

int main(){

	int T;
	cin>>T;
	
	for(int _=0;_<T;_++){
		long long n;
		cin>>n>>d;
		
		long long sq_d = sqrt(d);
		long long mini = Inf;
		for(long long i=max((long long)0,sq_d - 100000);i<sq_d + 100000;i++){
			mini = min(mini,func(i));
		}
		
		if(mini<=n)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	
	return 0;
}