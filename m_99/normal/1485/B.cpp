#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n,q,k;
	scanf("%d %d %d",&n,&q,&k);
	
	vector<long long> a(n);
	rep(i,n)scanf("%lld",&a[i]);
	
	a.insert(a.begin(),0);
	a.push_back(k+1);
	
	vector<long long> sum(n+2,0LL);
	for(int i=1;i<=n;i++){
		
		sum[i] = a[i+1] - a[i-1] - 2;
		sum[i] += sum[i-1];
	}
	
	rep(i,q){
		int l,r;
		scanf("%d %d",&l,&r);
		
		if(l==r){
			printf("%d\n",k-1);
		}
		else{
			long long ans = 0LL;
			ans += k - a[r-1] - 1;
			ans += a[l+1] - 2;
			ans += sum[r-1] - sum[l];
			printf("%lld\n",ans);
		}
	}
		
	
	return 0;
}