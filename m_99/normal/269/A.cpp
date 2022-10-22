#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000



int main(){
	
	int n;
	cin>>n;
	
	long long ans = 0;
	set<long long> ks;
	for(int i=0;i<n;i++){
		int k,a;
		cin>>k>>a;
		ks.insert(k);
		a--;
		int log2 = 0;
		while(a!=0){
			a/=2;
			log2++;
		}
		
		long long x = (long long)2*k;
		x += log2;
		
		x = (x+1)/2;
		
		ans = max(ans,x);
	}
	
	while(ks.count(ans))ans++;
	
	cout<<ans<<endl;
		
	
	return 0;
	
}