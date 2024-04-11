#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 2000000000000000001



int main(){
	
	int _t;
	cin>>_t;
	rep(_,_t){
		
		int n;
		cin>>n;
		
		vector<int> a(n);
		rep(i,n)cin>>a[i];
		
		long long s = 0;
		rep(i,n){
			s += a[i];
		}
		vector<long long> y;
		for(long long i=1;i*i<=s;i++){
			if(s%i==0){
				y.push_back(i);
				y.push_back(s/i);
			}
		}
		
		long long ans = Inf64;
		rep(i,y.size()){
			
			long long cur = 0;
			bool f = true;
			int mx = 0;
			int last = -1;
			rep(j,n){
				cur += a[j];
				if(cur>y[i]){
					f = false;
					break;
				}
				if(cur==y[i]){
					cur = 0;
					mx = max(mx,j-last);
					last = j;
				}
			}
			if(f&&cur==0){
				ans = min(ans,(long long)mx);
			}
		}
			
		cout<<ans<<endl;
		
	}
	
	return 0;
}