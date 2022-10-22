#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000



int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,k;
		cin>>n>>k;
		
		vector<long long> a(n);
		rep(i,n)scanf("%lld",&a[i]);
		long long ans = 0;
		for(int i=30;i>=0;i--){
			int cnt = n;
			rep(j,n){
				if((a[j]>>i)&1)cnt--;
			}
			if(cnt>k)continue;
			k -= cnt;
			ans |= 1LL<<i;
		}
		cout<<ans<<endl;
			
		
		
	}
	
	
    return 0;
}