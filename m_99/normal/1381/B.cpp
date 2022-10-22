#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000002


int main(){
	
	int t;
	cin>>t;
	
	for(int _=0;_<t;_++){
		
		int n;
		scanf("%d",&n);
		
		vector<int> p(2*n);
		for(int i=0;i<2*n;i++){
			cin>>p[i];
		}
		
		int maxi = 0;
		vector<int> cnt(2*n,0);
		vector<int> w;
		for(int i=0;i<2*n;i++){
			if(maxi>p[i]){
				cnt[i] = cnt[i-1]+1;
			}
			else{
				maxi = max(maxi,p[i]);
				cnt[i] = 1;
				if(i!=0)w.push_back(cnt[i-1]);
			}
			if(i==2*n-1){
				w.push_back(cnt[i]);
			}
		}
		vector<vector<bool>> dp(w.size()+1,vector<bool>(n+1,false));
		dp[0][0] = true;
		for(int i=0;i<w.size();i++){
			for(int j=0;j<=n;j++){
				if(!dp[i][j])continue;
				dp[i+1][j] = true;
				int k = j + w[i];
				if(k<=n){
					dp[i+1][k] = true;
				}
			}
		}
		
		if(dp.back().back())cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	return 0;
}