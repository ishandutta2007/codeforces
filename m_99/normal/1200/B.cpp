#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x))%modulo)
#define Inf 10000000000000000


int main(){
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++){
		long long n,m,k;
		cin>>n>>m>>k;
		
		vector<long long> h(n);
		for(int j=0;j<n;j++){
			cin>>h[j];
		}
		
		bool f = true;
		
		for(int i=0;i<n-1;i++){
			long long x = h[i+1]-k;
			if(x<0)x=0;
			
			if(h[i]>=x){
				m += h[i]-x;
				continue;
			}
			m -= x-h[i];
			if(m<0){
				f=false;
				break;
			}
		}
		
		if(f){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
		
	}
	
		
	
	return 0;
}