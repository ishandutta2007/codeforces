#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000001

int dp[255][255][255];

int main(){
	
	int n,q;
	cin>>n>>q;
	
	string ss;
	cin>>ss;
	
	vector<vector<int>> nxt(n+1,vector<int>(26,Inf));
	{	
		vector<int> tmp(26,Inf);
		for(int i=n;i>=0;i--){
			nxt[i] = tmp;
			if(i!=0){
				tmp[ss[i-1]-'a'] = i;
			}
		}
	}
	
	rep(i,255){
		rep(j,255){
			rep(k,255){
				dp[i][j][k] = Inf;
			}
		}
	}
	
	vector<string> s(3,"");
	dp[0][0][0] = 0;
	
	rep(_,q){
		
		char op;
		int t;
		char c;
		cin>>op>>t;
		t--;
		if(op=='+'){
			cin>>c;
			
			if(t==0){
				rep(i,255){
					rep(j,255){
						if(dp[s[0].size()][i][j]==Inf)continue;
						dp[s[0].size()+1][i][j] = min(dp[s[0].size()+1][i][j],nxt[dp[s[0].size()][i][j]][c-'a']);
					}
				}
				s[t] += c;
				rep(i,s[1].size()+1){
					rep(j,s[2].size()+1){
						if(dp[s[0].size()][i][j]==Inf)continue;
						if(i!=s[1].size())dp[s[0].size()][i+1][j] = min(dp[s[0].size()][i+1][j],nxt[dp[s[0].size()][i][j]][s[1][i]-'a']);
						if(j!=s[2].size())dp[s[0].size()][i][j+1] = min(dp[s[0].size()][i][j+1],nxt[dp[s[0].size()][i][j]][s[2][j]-'a']);
						
					}
				}
				
			}
			
			if(t==1){
				rep(i,255){
					rep(j,255){
						if(dp[i][s[1].size()][j]==Inf)continue;
						dp[i][s[1].size()+1][j] = min(dp[i][s[1].size()+1][j],nxt[dp[i][s[1].size()][j]][c-'a']);
					}
				}
				s[t] += c;
				rep(i,s[0].size()+1){
					rep(j,s[2].size()+1){
						if(dp[i][s[1].size()][j]==Inf)continue;
						if(i!=s[0].size())dp[i+1][s[1].size()][j] = min(dp[i+1][s[1].size()][j],nxt[dp[i][s[1].size()][j]][s[0][i]-'a']);
						if(j!=s[2].size())dp[i][s[1].size()][j+1] = min(dp[i][s[1].size()][j+1],nxt[dp[i][s[1].size()][j]][s[2][j]-'a']);
						
					}
				}
				
				
			}
			
			if(t==2){
				rep(i,255){
					rep(j,255){
						if(dp[i][j][s[2].size()]==Inf)continue;
						dp[i][j][s[2].size()+1] = min(dp[i][j][s[2].size()+1],nxt[dp[i][j][s[2].size()]][c-'a']);
					}
				}
				s[t] += c;
				rep(i,s[0].size()+1){
					rep(j,s[1].size()+1){
						if(dp[i][j][s[2].size()]==Inf)continue;
						if(i!=s[0].size())dp[i+1][j][s[2].size()] = min(dp[i+1][j][s[2].size()],nxt[dp[i][j][s[2].size()]][s[0][i]-'a']);
						if(j!=s[1].size())dp[i][j+1][s[2].size()] = min(dp[i][j+1][s[2].size()],nxt[dp[i][j][s[2].size()]][s[1][j]-'a']);
						
					}
				}
				
			}
			
			
			
		}
		else{
			
			
			if(t==0){
				rep(i,255){
					rep(j,255){
						dp[s[0].size()][i][j] = Inf;
					}
				}
			}
			if(t==1){
				rep(i,255){
					rep(j,255){
						dp[i][s[1].size()][j] = Inf;
					}
				}
			}
			if(t==2){
				rep(i,255){
					rep(j,255){
						dp[i][j][s[2].size()] = Inf;
					}
				}
			}
			s[t].pop_back();
			
		}
		
		if(dp[s[0].size()][s[1].size()][s[2].size()]==Inf)printf("NO\n");
		else printf("YES\n");
		
	}
	
	
	
	return 0;
}