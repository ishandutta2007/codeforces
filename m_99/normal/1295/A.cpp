#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000

int main(){

	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		int n;
		cin>>n;
		
		if(n%2==1){
			printf("7");
			n-=3;
		}
		for(int i=0;i<n/2;i++)printf("1");
		printf("\n");
	}
	
	return 0;
}