#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	int sum = 0;
	
	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		sum += a;
	}
	
	if(sum % n == 0){
		cout<<n<<endl;
	}
	else{
		cout<<n-1<<endl;
	}
		
	
	return 0;
	
}