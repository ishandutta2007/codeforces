#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001



int main(){
	
	int t;
	cin>>t;
	
	
	for(int _=0;_<t;_++){
		int n,m;
		scanf("%d %d",&n,&m);
		if(m%2==0){
			swap(n,m);
		}
		
		if(n%2==0){
			printf("%d\n",n/2 * m);
			continue;
		}
		else {
			printf("%d\n",(n*m-1)/2 + 1);
		}
	}
	
	return 0;	
}