#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000000000000

int main(){
	
	int n;
	cin>>n;
	
	vector<long long> c(n);
	rep(i,n)cin>>c[i];
	long long ans = 0LL;
	for(int i=1;i<n;i+=2){
		
		long long mini = 0,cur = 0;
		for(int j=i;j<n;j++){
			if(j%2==1){
				cur -= c[j];
			}
			else{
				cur += c[j];
			}
			mini = min(mini,cur);
			
			if(j%2==0 && i!=0 && j!=n-1){
				long long x = -mini;
				long long y = x + cur;
				ans += max(0LL,min(c[i-1]+1-x,c[j+1]+1-y));				
			}
			//cout<<i<<','<<j<<','<<ans<<endl;
		}
	}
	rep(i,n){
		if(i%2==0 && i!=n-1){
			ans += min(c[i],c[i+1]);
		}
		
	}
	cout<<ans<<endl;
	
	return 0;
}