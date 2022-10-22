#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf32 1000000001
#define Inf64 4000000000000000001


int main(){	
	
	int _t;
	cin>>_t;
	
	rep(_,_t){
		long long n,m;
		cin>>n>>m;
		vector dp(2,vector(2,vector<long long>(2,0)));
		dp[0][0][0] = 1;
		rep(i,63){
			vector ndp(2,vector(2,vector<long long>(2,0)));
			rep(j,2){
				rep(k,2){
					rep(l,2){
						if(dp[j][k][l]==0)continue;
						rep(lm,2){
							long long b = (n>>i)&1;
							b += k;
							b += lm;
							int jj = j,kk = k,ll = l;
							if(((m>>i)&1)&&lm==0)jj = 1;
							if(((m>>i)&1)==0&&lm==1)jj = 0;
							if(b>=2)kk = 1;
							else kk = 0;
							b &= 1;
							if(lm!=b)ll^=1;
							ndp[jj][kk][ll] += dp[j][k][l];
						}
						
					}
				}
			}
			swap(dp,ndp);
			/*
			rep(j,2){
				rep(k,2){
					rep(l,2){
						cout<<dp[j][k][l]<<',';
					}
				}
			}
			cout<<endl;
			*/
		}
		
		cout<<dp[1][0][1]<<endl;
	}
	
	return 0;
	
}