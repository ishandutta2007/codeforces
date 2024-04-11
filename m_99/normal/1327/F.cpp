#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x)+modulo)%modulo)
#define Inf 1000000000000


int main() {
	
	int n,k,m;
	scanf("%d %d %d",&n,&k,&m);
	
	vector<int> l(m),r(m),x(m);
	
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&l[i],&r[i],&x[i]);
	}
	
	int ans = 1;
	
	for(int i=0;i<k;i++){
		vector<int> imos(n+1,0),L(n+1,0);
		
		for(int j=0;j<m;j++){
			if((1<<i)&x[j]){
				imos[l[j]]++;
				if(r[j]!=n)imos[r[j]+1]--;
			}
			else{
				L[r[j]] = max(L[r[j]],l[j]);
			}
		}
		
		for(int j=1;j<=n;j++)imos[j] += imos[j-1];
		
		int last = 0;
		vector<int> dp(n+1,0);
		dp[0] = 1;
		
		for(int j=1;j<=n;j++){
			
			if(imos[j]!=0){
				dp[j] = mod(dp[j]+dp[j-1]);
			}
			else{
				dp[j] = dp[j-1];
				if(last!=0){
					dp[j] = mod(dp[j]-dp[last-1]);
				}
				dp[j] = mod(dp[j]+dp[j-1]);
			}
			last = max(last,L[j]);
		}
		
		int temp = dp.back();
		if(last!=0){
			temp = mod(temp - dp[last-1]);
		}
		/*
		for(int j=1;j<=n;j++)cout<<dp[j]-dp[j-1]<<',';
		cout<<endl;
		*/
		ans = mod(ans * temp);
	}
	
	cout<<ans<<endl;
	
    return 0;
}