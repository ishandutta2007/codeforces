#include<bits/stdc++.h>
using namespace std;

int suma(int x){
	
	int result=0;
	
	while(x>0){
		result+=x%10;
		x/=10;
	}
	
	return result;
	
	
}

int main(){
	
	int k,conteo=0;cin>>k;
	int n=1;
	
	do{if(suma(n)==10){
		conteo++;
	};
	n+=9;
		
	}while(conteo<k);
	
	cout<<n-9;
	
	
	
	
	
	
	
	
	
	return 0;
}