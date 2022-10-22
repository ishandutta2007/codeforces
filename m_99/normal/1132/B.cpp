#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int main(){
	
	int n;
	scanf("%d",&n);
	vector<long long> a(n);
	long long ans = 0LL;
	rep(i,n){
		scanf("%lld",&a[i]);
		ans += a[i];
	}
	sort(a.rbegin(),a.rend());
	int m;
	scanf("%d",&m);
	
	rep(i,m){
		int d;
		scanf("%d",&d);
		printf("%lld\n",ans-a[d-1]);
	}
	
	return 0;
}