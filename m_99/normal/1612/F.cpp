#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
#define Inf 1000000001



int main(){
	
	int n,m,q;
	cin>>n>>m>>q;
	
	vector<pair<int,int>> p(q);
	rep(i,q){
		scanf("%d %d",&p[i].first,&p[i].second);
	}
	sort(p.begin(),p.end());
	vector<int> X,Y;
	rep(i,p.size()){
		if(p[i].first==n&&p[i].second==m)continue;
		if(p[i].first==n)X.push_back(p[i].second);
		if(p[i].second==m)Y.push_back(p[i].first);
	}
	vector dp(50,vector<int>(n+1,-Inf));
	dp[0][1] = 1;
	
	rep(i,49){
		rep(j,n+1){
			if(dp[i][j]==-Inf)continue;
			
			int power = j + dp[i][j];
			if(binary_search(p.begin(),p.end(),make_pair(j,dp[i][j])))power++;
			dp[i+1][min(n,power)] = max(dp[i+1][min(n,power)], dp[i][j]);
			dp[i+1][j] = max(dp[i+1][j],min(m,power));
			
		}
	}
	int ans = Inf;
	{
		vector<int> ddp(n+1,Inf);
		
		rep(i,49){
			rep(j,n+1){
				if(dp[i][j]==m){
					ddp[j] = min(ddp[j],i);
				}
			}
		}
		rep(i,n){
			if(ddp[i]==Inf)continue;
			int power = i + m;
			if(binary_search(p.begin(),p.end(),make_pair(i,m)))power++;
			ddp[min(n,power)] = min(ddp[min(n,power)], ddp[i]+1);
		}
		ans = min(ans,ddp.back());
	}
	
	{
		vector<int> ddp(m+1,Inf);
		
		rep(i,49){
			rep(j,n+1){
				if(j==n&&dp[i][j]!=-Inf){
					ddp[dp[i][j]] = min(ddp[dp[i][j]],i);
				}
			}
		}
		rep(i,m){
			if(ddp[i]==Inf)continue;
			int power = n+i;
			if(binary_search(p.begin(),p.end(),make_pair(n,i)))power++;
			ddp[min(m,power)] = min(ddp[min(m,power)], ddp[i]+1);
		}
		ans = min(ans,ddp.back());
	}
	
	cout<<ans<<endl;
	
	return 0;
}