#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000000001

int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n;
		cin>>n;
		long long x;
		cin>>x;
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		vector<long long> sum(n+1,-Inf);
		sum[0] = 0;
		rep(i,n){
			long long t = 0;
			for(int j=i;j<n;j++){
				t += a[j];
				sum[j-i+1] = max(sum[j-i+1],t);
			}
		}
		
		rep(i,n+1){
			long long ans= 0LL;
			rep(j,n+1){
				ans = max(ans,sum[j] + x * min(j,i));
			}
			if(i!=0)cout<<' ';
			cout<<ans;
		}
		cout<<endl;
		
	}
	
	return 0;
}