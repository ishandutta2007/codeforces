#include<bits/stdc++.h>

using namespace std;

int main(){
	
	long long n; cin>>n;
	
	if(n==0){ cout<<0;
	}else
	
	if(n%2==0){
		cout<<n+1;
	}else{
		cout<<(n+1)/2;
	}
	
	
	
	
	return 0;
}