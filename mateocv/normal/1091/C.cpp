#include<bits/stdc++.h>
using namespace std;

int main(){
	
	long long n; cin>>n;
	long long r=0;
	
	for(int i=1;i<=sqrt(n);i++){
		if(n%i==0){r=i*(1+n-n/i+1)/2;cout<<r<<" ";
		}
	};
	
	for(int i=ceil(sqrt(n))-1;i>0;i--){
		if(n%i==0){r=(n/i)*(1+n-i+1)/2;cout<<r<<" ";
		}
	};
	
	
	
	
	
	
	
	return 0;
}