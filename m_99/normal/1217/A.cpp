#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000

int main(){
	
	int T;
	cin>>T;
	
	for(int i=0;i<T;i++){
		int S,I,E;
		cin>>S>>I>>E;
		
		S+=E;
		int dif = S-I;
		if(dif<=0){
			cout<<0<<endl;
		}
		else{
			cout<<min((dif+1)/2,E+1)<<endl;
		}
	}
	
	return 0;
}