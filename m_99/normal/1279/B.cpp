#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000000000000



int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		int n,s;
		cin>>n>>s;
		
		vector<long long> a(n);

		for(int j=0;j<n;j++){
			cin>>a[j];
		}
		
		long long sum = 0;
		int k = n;
		for(int j=0;j<n;j++){
			sum+=a[j];
			if(sum>s){
				k=j;
				break;
			}
		}

		
		if(k==n){
			cout<<0<<endl;
			continue;
		}
		
		int ind = -1;
		int maxi = 0;
		for(int j=0;j<=k;j++){
			if(maxi<a[j]){
				ind = j;
				maxi = a[j];
			}
		}
		
		sum = 0;
		int k2 = n;
		for(int j=0;j<n;j++){
			if(j==ind)continue;
			sum += a[j];
			if(sum > s){
				k2 = j;
				break;
			}
		}
		
		if(k2>k){
			cout<<ind+1<<endl;
		}
		else{
			cout<<0<<endl;
		}
		
	}
	

    return 0;
}