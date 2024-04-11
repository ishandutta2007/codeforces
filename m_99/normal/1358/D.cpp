#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

long long get(long long n){
	return n * (n+1) / 2;
}

int main(){
	
	int n;
	cin>>n;
	
	long long x;
	cin>>x;
	
	vector<long long> d(3*n);
	
	for(int i=0;i<n;i++){
		scanf("%lld",&d[i]);
		d[n+i] = d[i];
		d[2*n+i] = d[i];
	}
	
	long long ans = 0;
	long long S0 = 0,S1 = 0;
	int l = 0;
	for(int i=0;i<3*n;i++){
		S0 += d[i];
		S1 += get(d[i]);
		if(S0<x)continue;
		while(S0-d[l]>x){
			S0-=d[l];
			S1-=get(d[l]);
			l++;
		}
		ans = max(ans,S1 - get(S0-x));
	}
	
	cout<<ans<<endl;
	
	return 0;
}