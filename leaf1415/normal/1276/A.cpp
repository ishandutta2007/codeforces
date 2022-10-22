#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T;
string s;
llint dp[150005][5];
llint nx[5][26];
P rec[150005][5];
vector<llint> ans;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	for(int i = 0; i < 5; i++){
		nx[i]['t'-'a'] = 1;
		if(i==1)nx[i]['w'-'a'] = 2;
		nx[i]['o'-'a'] = 3;
		if(i==3)nx[i]['n'-'a'] = 4;
	}
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> s;
		int n = s.size();
		s = "#" + s;
		
		for(int i = 0; i <= n; i++){
			for(int j = 0; j < 5; j++){
				dp[i][j] = -inf;
			}
		}
		dp[0][0] = 0;
		for(int i = 0; i < n; i++){
			int c = s[i+1]-'a';
			for(int j = 0; j < 5; j++){
				if(dp[i+1][j] < dp[i][j]){
					dp[i+1][j] = dp[i][j];
					rec[i+1][j] = P(i, j);
				}
				if(j==2&&c=='o'-'a') continue;
				if(j==4&&c=='e'-'a') continue;
				if(dp[i+1][nx[j][c]] < dp[i][j]+1){
					dp[i+1][nx[j][c]] = dp[i][j]+1;
					rec[i+1][nx[j][c]] = P(i, j);
				}
			}
		}
		
		
		llint i = n, j = 0;
		for(int k = 1; k < 5; k++){
			if(dp[n][j] < dp[n][k]) j = k;
		}
		//cout << "*" << dp[n][j] << endl;
		ans.clear();
		while(i > 0){
			//cout << i << " " << j << endl;
			
			int ni = rec[i][j].first, nj = rec[i][j].second;
			if(dp[ni][nj] == dp[i][j]) ans.push_back(i);
			i = ni, j = nj;
		}
		cout << ans.size() << endl;
		for(int i = 0; i < ans.size(); i++) cout<< ans[i] << " "; cout << endl;
	}
	
	return 0;
}