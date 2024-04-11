#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000

int main(){
	
	int N,S;
	cin>>N>>S;
	
	if(S<2*N){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;

	for(int i=0;i<N-1;i++){
		printf("1 ");
	}
	printf("%d\n",S-(N-1));
	
	cout<<N<<endl;
	
	return 0;
}