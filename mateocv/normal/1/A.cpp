#include<bits/stdc++.h>
using namespace std;

int main(){
	
	int n,m,a; cin>>n>>m>>a;
	long long largo=0, ancho=0;
	
	if(n%a==0){largo=n/a;
	}else{
		largo=n/a+1;
	};
	
	if(m%a==0){ancho=m/a;
	}else{
		ancho=m/a+1;
	};
	
	long long resp;
	resp=ancho*largo;
	cout<<resp;
	
	
	
	
	
	return 0;
}