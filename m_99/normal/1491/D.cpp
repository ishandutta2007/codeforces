#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001

int main(){
	
	int q;
	cin>>q;
	
	rep(_,q){
		
		int u,v;
		scanf("%d %d",&u,&v);
		
		vector<int> ind0,ind1;
		
		rep(i,30){
			if((u>>i)&1)ind0.push_back(i);
			if((v>>i)&1)ind1.push_back(i);
		}
		
		vector dp(ind0.size()+1,vector<bool>(ind1.size()+1,false));
		dp[0][0] = true;
		
		rep(i,ind0.size()+1){
			rep(j,ind1.size()+1){
				if(dp[i][j]==false)continue;
				if(i==ind0.size()||j==ind1.size())continue;
				if(ind0[i]<=ind1[j]){
					dp[i+1][j+1] = true;
				}
				rep(k,100){
					if(i+k>=ind0.size())break;
					if(ind0[i+k]>=ind1[j])break;
					dp[i+1+k][j+1] = true;
				}
			}
		}
		
		if(dp.back().back())printf("Yes\n");
		else printf("No\n");
		
	}
		
		
	
    return 0;
}