#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		long long l,r,k;
		int n;
		cin>>n;
		scanf("%lld %lld %lld",&l,&r,&k);
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		sort(a.begin(),a.end());
		int ans = 0;
		rep(i,n){
			if(a[i]>=l&&a[i]<=r&&a[i]<=k){
				k -= a[i];
				ans++;
			}
		}
		cout<<ans<<endl;
		
	}
		
	return 0;
}