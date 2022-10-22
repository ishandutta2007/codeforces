#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000


int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	
	long long sum = 0;
	long long maxi = 0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum += a[i];
		maxi = max(maxi,a[i]);
	}
	
	if(sum%2==1){
		cout<<"NO"<<endl;
		return 0;
	}
	
	if(maxi > sum/2){
		cout<<"NO"<<endl;
		return 0;
	}
	
	cout<<"YES"<<endl;
	
			
			
	
	
	return 0;
}