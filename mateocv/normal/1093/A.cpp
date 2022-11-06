#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int t; cin>>t;
	
	for(int i=1;i<t+1;i++){
		
		int n; cin>>n;
		
		if(n%2==0){
			cout<<n/2<<"\n";
		}else{
			
			cout<<(n-1)/2<<"\n";
		}
		
	}
	
	
	
	
	return 0;
}