#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000001



int main(){	
	
	int _t;
	cin>>_t;
	
	for(int _=1;_<=_t;_++){
		
		int n,m;
		cin>>n>>m;
		
		vector<string> s(n);
		rep(i,n)cin>>s[i];
		vector<vector<int>> cnt(n,vector<int>(m,0));
		
		rep(i,n){
			rep(j,m){
				int ii = i,jj = j;
				if(s[i][j]=='U')ii--;
				if(s[i][j]=='R')jj++;
				if(s[i][j]=='L')jj--;
				if(s[i][j]=='D')ii++;
				if(ii<0||ii>=n||jj<0||jj>=m)continue;
				cnt[ii][jj]++;
			}
		}
		
		queue<pair<int,int>> Q;
		rep(i,cnt.size()){
			rep(j,m){
				if(cnt[i][j]==0)Q.emplace(i,j);
			}
		}
		
		while(Q.size()>0){
			int i = Q.front().first,j = Q.front().second;
			Q.pop();
			int ii = i,jj = j;
			if(s[i][j]=='U')ii--;
			if(s[i][j]=='R')jj++;
			if(s[i][j]=='L')jj--;
			if(s[i][j]=='D')ii++;
			if(ii<0||ii>=n||jj<0||jj>=m)continue;
			cnt[ii][jj]--;
			if(cnt[ii][jj]==0)Q.emplace(ii,jj);
		}
		
		vector<vector<int>> dp(n,vector<int>(m,-Inf));
		
		rep(i,n){
			rep(j,m){
				if(cnt[i][j]==0)continue;
				if(dp[i][j]!=-Inf)continue;
				vector<pair<int,int>> t;
				t.emplace_back(i,j);
				while(true){
					int ii = t.back().first,jj = t.back().second;
					if(s[t.back().first][t.back().second]=='U')ii--;
					if(s[t.back().first][t.back().second]=='R')jj++;
					if(s[t.back().first][t.back().second]=='L')jj--;
					if(s[t.back().first][t.back().second]=='D')ii++;
					if(t[0]==make_pair(ii,jj))break;
					t.emplace_back(ii,jj);
				}
				rep(k,t.size()){
					dp[t[k].first][t[k].second] = t.size();
				}
			}
		}
	//	cout<<'a'<<endl;
		stack<pair<int,int>> S;
		rep(i,n){
			rep(j,m){
				if(dp[i][j]!=-Inf)continue;
				S.emplace(i,j);
				while(S.size()>0){
					int y = S.top().first,x = S.top().second;
					//cout<<y<<','<<x<<endl;
					S.pop();
					int ii = y,jj = x;
					if(s[y][x]=='U')ii--;
					if(s[y][x]=='R')jj++;
					if(s[y][x]=='L')jj--;
					if(s[y][x]=='D')ii++;
					
					if(ii<0||ii>=n||jj<0||jj>=m){
						dp[y][x] = 1;
					}
					else{
						if(dp[ii][jj]==-Inf){
							S.emplace(y,x);
							S.emplace(ii,jj);
						}
						else{
							dp[y][x] = dp[ii][jj]+1;
						}
					}
				}
					
			}
		}
		
		int ai=0,aj=0;
		rep(i,n){
			rep(j,m){
				if(dp[i][j]>dp[ai][aj]){
					ai = i;
					aj = j;
				}
			}
		}
		printf("%d %d %d\n",ai+1,aj+1,dp[ai][aj]);
	}
	
	return 0;
	
}