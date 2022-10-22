#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000


int main(){
	
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n){
		scanf("%d",&p[i]);
		p[i]--;
	}
	p.insert(p.begin(),0);
	vector<int> ans(n+1,0);
	ans[0] = 1;
	
	vector<int> dp(n+1,0);
	vector<pair<int,int>> ind(n+1,make_pair(-1,-1));
	
	rep(i,n){
		int cur = i+1;
		dp[cur] = 1;
		while(cur!=0){
			int ncur = p[cur];
			int pre = dp[ncur];
			if(ind[ncur].first==-1){
				ind[ncur].first = cur;
			}
			else if(ind[ncur].first==cur){
			}
			else if(ind[ncur].second == -1){
				ind[ncur].second = cur;
				
			}
			else{
				if(ind[ncur].second==cur){
				}
				else{
					if(dp[ind[ncur].first]<dp[cur]){
						ind[ncur].second = ind[ncur].first;
						ind[ncur].first = cur;
					}
					else if(dp[ind[ncur].second]<dp[cur]){
						ind[ncur].second = cur;
					}
				}
					
			}
			if(ind[ncur].second!=-1&&dp[ind[ncur].first]<dp[ind[ncur].second]){
				swap(ind[ncur].first,ind[ncur].second);
			}
			if(ind[ncur].first!=-1)dp[ncur] = dp[ind[ncur].first];
			if(ncur==0)break;
			if(ind[ncur].second!=-1){
				dp[ncur] = max(dp[ncur],dp[ind[ncur].second]+1);
			}
			
			if(dp[ncur]!=pre){
				cur = ncur;
			}
			else break;
		}
		ans[i+1] = dp[0];

	}
	
	rep(i,ans.size()){
		if(i==0)continue;
		if(i!=1)printf(" ");
		printf("%d",ans[i]);
	}
	cout<<endl;
	
    return 0;
}