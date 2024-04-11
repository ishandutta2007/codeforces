#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		long long k;
		cin>>n>>k;
		k++;
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		vector<long long> maxi(n,0);
		rep(i,n-1){
			maxi[i] = 1LL;
			rep(j,a[i+1]-a[i])maxi[i]*=10;
		}
		maxi.back() = Inf;
		long long ans = 0LL;
		rep(i,n){
			long long c = 1LL;
			rep(j,a[i])c *= 10;
			if(k<maxi[i]){
				ans += k * c;
				break;
			}
			ans += c * (maxi[i]-1);
			k -= maxi[i]-1;
		}
		
		cout<<ans<<endl;
	}
	
	return 0;
	
}