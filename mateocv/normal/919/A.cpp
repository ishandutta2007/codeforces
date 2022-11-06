#include<bits/stdc++.h>
using namespace std;

int main(){
	
	double n, m; cin>>n>>m;
	
	double a, b;
	double min=100000;
	
	for(int i=0;i<n;i++){
		
		cin>>a>>b;
		if((a/b)<min){
			min=a/b;
		}
		
		
		
		
		
		
	};
	
	
	cout<<fixed<<setprecision(10)<<min*m;
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}