#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {

	int n;
	cin>>n;
	
	vector<long long> b(n);
	for(int i=0;i<n;i++)scanf("%lld",&b[i]);
	
	long long maxi = 0;
	vector<long long> a(n);
	
	for(int i=0;i<n;i++){
		a[i] = b[i]+maxi;
		maxi = max(maxi,a[i]);
	}
	
	for(int i=0;i<n;i++){
		if(i!=0)cout<<" ";
		printf("%lld",a[i]);
	}
	cout<<endl;
	
    return 0;
}