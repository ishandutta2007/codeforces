#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000
int f[2000005];
int sum[2000005];
int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n;
		cin>>n;
		
		vector<long long> a(n);
		rep(i,n)cin>>a[i];
		
		
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j])continue;
				long long y = abs(a[i]-a[j]);
				for(int k=1;k*k<=y;k++){
					if(y%k==0){
						f[k] = 1;
						f[y/k] = 1;
					}
					
				}
			}
		}
		
		
		int ans = 0;
		for(int i=1;i<=2000003;i++){
			if(f[i]==0 && i!=2000002)continue;
			rep(j,n){
				sum[(a[j] % i + i)%i]++;
			}
			rep(j,n){
				if(sum[(a[j] % i + i)%i]>=(n+1)/2){
					ans = i;
				}
					
			}
			rep(j,n){
				sum[(a[j] % i + i)%i]--;
			}
		}
		rep(i,n){
			for(int j=i+1;j<n;j++){
				if(a[i]==a[j])continue;
				long long y = abs(a[i]-a[j]);
				for(int k=1;k*k<=y;k++){
					if(y%k==0){
						f[k] = 0;
						f[y/k] = 0;
					}
					
				}
			}
		}
		
		if(ans > 2000000)ans = -1;
		cout<<ans<<endl;
		
	}
	
	return 0;
}