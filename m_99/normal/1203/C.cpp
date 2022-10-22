#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf (long long)1000000000000000




int main(){
	
	int n;
	cin>>n;
	
	vector<long long> a(n);
	rep(i,n)scanf("%lld",&a[i]);
	
	long long g =0LL;
	
	rep(i,n)g = gcd(g,a[i]);
	
	
	int ans = 0;
	for(long long i=1;i*i<=g;i++){
		if(g%i==0){
			ans++;
			if(i*i!=g)ans++;
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}