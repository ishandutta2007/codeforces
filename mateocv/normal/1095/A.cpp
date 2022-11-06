#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;cin>>n;
	char palabra[n];
	
	for(int i=0;i<n;i++){
		
		cin>>palabra[i];
		
	};
	
	for(int j=1;j<11;j++){
		
		if((j*(j+1)/2)<n+1){cout<<palabra[((j*(j+1))/2)-1];
		};
		
		
	};
	
	
	
	
	
	
	
	
	
	return 0;
}

/*#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n;cin>>n;
	char palabra[n];
	
	for(int i=0;i<n;i++){
		
		cin>>palabra[i];
		
	};
	
	for(int i=0;i<n;i++){
		for(int j=0;j<i+1;j++){
		
		
		cout<<palabra[i];}
		
	};
	
	
	
	
	
	
	
	
	
	return 0;
}*/