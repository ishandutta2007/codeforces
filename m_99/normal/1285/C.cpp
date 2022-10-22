#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int main(){

	long long X;
	cin>>X;
	
	vector<long long> V;
	
	for(long long i=2;i*i<=X;i++){
		if(X%i!=0)continue;
		
		V.push_back(1);
		while(X%i==0){
			V.back() *= i;
			X /= i;
		}
	}
	
	if(X!=1){
		V.push_back(X);
	}
	
	long long a = Inf,b = Inf;
	
	for(int i=0;i<(1<<V.size());i++){
		long long x = 1,y = 1;
		for(int j=0;j<V.size();j++){
			if((1<<j)&i){
				x *= V[j];
			}
			else{
				y *= V[j];
			}
		}
		
		if(max(a,b) > max(x,y)){
			a = x;
			b = y;
		}
	}
	
	cout<<a<<' '<<b<<endl;
	
	return 0;
}