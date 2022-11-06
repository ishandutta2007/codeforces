#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n; cin>>n;
	
	int array[n];
	
	for(int i=0;i<n;i++){
		
		cin>>array[i];
		
	};
	
	
	cout<<(n+1)<<endl<<"1 "<<n<<" 900000"<<endl;
	
	for(int i=0;i<n;i++){
		
		cout<<"2 "<<i+1<<" "<<array[i]+900000-i<<endl;
		
	};
	
	
	
	
	
	return 0;
}