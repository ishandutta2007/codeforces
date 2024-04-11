#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001


int main(){
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		
		int n,m;
		scanf("%d %d",&n,&m);
		vector<string> S(n);
		rep(i,n)cin>>S[i];
		
		{
			vector<string> T(m,string(n,'.'));
			rep(i,n){
				rep(j,m){
					T[j][i] = S[i][j];
				}
			}
			swap(S,T);
			swap(n,m);
		}
		
		vector sum(n,vector<int>(m+1,0));
		rep(i,n){
			rep(j,m){
				sum[i][j+1] = S[i][j]-'0';
				sum[i][j+1] += sum[i][j];
			}
		}
		int ans = Inf;
		vector<int> dp(3,Inf);
		vector<int> ndp(3,Inf);
		rep(i,m){
			for(int j=i+4;j<m;j++){
				int l = i,r = j;
				dp.assign(3,Inf);
				rep(k,n){
					ndp.assign(3,Inf);
					
					ndp[0] = (r-l+1-2) - (sum[k][r] - sum[k][l+1]);
					int C = 0;
					if(S[k][l]=='0')C++;
					if(S[k][r]=='0')C++;
					//C += S[k][l]-'0' + S[k][r]-'0';
					
					ndp[1] = dp[0] + sum[k][r] - sum[k][l+1] + C;
					
					ndp[2] = min(dp[1] + sum[k][r] - sum[k][l+1], dp[2] + sum[k][r] - sum[k][l+1]) + C;					
					
					ans = min(ans,dp[2] + (r-l+1-2) - (sum[k][r]-sum[k][l+1]));
					swap(dp,ndp);		
					
				//	ans = min(ans,dp.back());					
				}
				
				
			}
		}
		
		printf("%d\n",ans);
		
		
		
	}
	
	return 0;
}