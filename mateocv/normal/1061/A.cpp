#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,s,p=0; cin>>n>>s;
	
	p=(s-s%n)/n+1;
	
	if(s%n==0){
		cout<<s/n;
	}else{ cout<<p;
	}
	
	
	
	
	
	
	
	
	return 0;
}