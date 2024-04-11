#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 100000000000000000

array<int,4> dp[43][43][43][43];

int main(){
	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		int n,A,B;
		cin>>n>>A>>B;
		string s;
		cin>>s;
		
		
		//dp[0][0][0][0][0] = 0;
		rep(i,43){
			rep(j,43){
				rep(k,43){
					rep(l,43){
						dp[i][j][k][l] = {-1,-1,-1,-1};
					}
				}
			}
		}
		dp[0][0][0][0][0] = 0;
		rep(i,n){
			rep(j,A){
				rep(k,B){
					rep(l,43){
						
						if(dp[i][j][k][l][0]==-1)continue;
						int t = s[i]-'0';
						dp[i+1][(j*10+t)%A][k][l+1] = {0,j,k,l};
						dp[i+1][j][(k*10+t)%B][l] = {1,j,k,l};
						
					}
					
				}
			}
		}
		
		pair<int,int> p(-1,-100);
		rep(i,43){
			if(i==0||n-i<=0)continue;
			if(dp[n][0][0][i][0]==-1)continue;
			if(abs(p.first-p.second)>abs(i-(n-i))){
				p = make_pair(i,n-i);
			}
		}
		
		if(p.first==-1){
			printf("-1\n");
			continue;
		}
		else{
			string ans = "";
			array<int,4> temp = {0,0,0,p.first};
			for(int i=n;i>=1;i--){
				auto A = dp[i][temp[1]][temp[2]][temp[3]];
				if(A[0]==0)ans += 'R';
				else ans += 'B';
				temp = A;
			}
			reverse(ans.begin(),ans.end());
			cout<<ans<<endl;
			
		}
		
	}
	
	return 0;
}