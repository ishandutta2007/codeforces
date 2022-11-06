#include<bits/stdc++.h>
using namespace std;

int esprimo(long long p){
	
	for(int i=2;i<=sqrt(p);i++){
		if(p%i==0){
			return 0;
		}
	}
	
	return 1;
	
}



int main(){
	
	int t; cin>>t;
	long long a,b,medida=0;
	for(int i=0;i<t;i++){
		cin>>a>>b;
		medida=a*a-b*b;
		if(a-b==1){
		if(esprimo(medida)==1){cout<<"YES\n";
		}else{cout<<"NO\n";};
		}else{cout<<"NO\n";};
		
	};
	
	
	
	
	return 0;
}