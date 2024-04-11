#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main() {
   
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		string s;
		cin>>s;
		int n;
		cin>>n;
		vector<string> t(n);
		rep(i,n){
			cin>>t[i];
		}
		
		vector<int> dp(s.size()+1,Inf);
		dp[0] = 0;
		vector<int> pp(s.size()+1,-1);
		vector<int> pi(s.size()+1,-1);
		rep(i,s.size()){
			if(dp[i]==Inf)continue;
			rep(j,n){
				if(s.substr(i,t[j].size())==t[j]){
					rep(k,t[j].size()){
						if(dp[i+k+1]>dp[i]+1){
							dp[i+k+1] = dp[i]+1;
							pi[i+k+1] = j;
							pp[i+k+1] = i;
						}
					}
				}
			}
		}
		int ans = dp.back();
		if(ans==Inf){
			cout<<-1<<endl;
			continue;
		}
		cout<<ans<<endl;
		
		int cur = s.size();
		while(cur!=0){
			cout<<pi[cur]+1<<' '<<pp[cur]+1<<endl;
			cur = pp[cur];
		}
		
	}
	
    return 0;
}