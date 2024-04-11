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
		
		int n;
		cin>>n;
		
		int c0  = 0,c1 = 0;
		rep(i,n){
			int a;
			scanf("%d",&a);
			if(a%2==0)c0 ++;
			else c1++;
		}
		
		vector dp(c0+1,vector(c1+1,vector<bool>(2,false)));
		dp[0][0][0] = true;
		dp[0][0][1] = false;
		
		rep(i,c0+1){
			rep(j,c1+1){
				if(i==0&&j==0)continue;
				rep(k,2){
					
					if((i+j)%2==n%2){
						//Alice
						bool f = false;
						if(i>0){
							if(dp[i-1][j][k])f = true;
						}
						if(j>0){
							if(dp[i][j-1][k^1])f = true;
						}
						dp[i][j][k] = f;
					}
					else{
						//Bob
						bool f = true;
						if(i>0){
							if(!dp[i-1][j][k])f = false;
						}
						if(j>0){
							if(!dp[i][j-1][k])f = false;
						}
						dp[i][j][k] = f;
					}
					
				}
			}
		}
		if(dp[c0][c1][0])cout<<"Alice"<<endl;
		else cout<<"Bob"<<endl;
	}
	
	return 0;
}