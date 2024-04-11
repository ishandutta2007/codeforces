#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int a,b,c; cin>>a>>b>>c;
	
	if((a<=b-1)&&(a<=c-2)){
		cout<<3*a+3;
	}else if((b-1<=a)&&(b-1<=c-2)){
		cout<<3*b;
	}else{
		cout<<3*c-3;
	}
	
	
	
	
	
	
	
	
	
	return 0;
}