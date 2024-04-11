#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000


int main(){

	int n;
	cin>>n;
	vector<long long> A(n);
	
	for(int i=0;i<n;i++){
		cin>>A[i];
	}
	
	bool f = false;
	long long ans = 0;
	int k = 1;
	for(int i=0;i<n;i++){
		if(A[i]==0)f=true;
		
		if(A[i]>=0){
			ans += abs(A[i]-1);
			A[i]=1;
		}
		else{
			ans += abs(A[i]+1);
			A[i]=-1;
		}
		k *= A[i];
		
	}
	
	if(k==1){
		cout<<ans<<endl;
	}
	else{
		if(f){
			cout<<ans<<endl;
		}
		else{
			cout<<ans+2<<endl;
		}
	}
		
		
	return 0;
}