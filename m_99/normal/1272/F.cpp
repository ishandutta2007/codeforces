#include <bits/stdc++.h>
using namespace std;
#define modulo 998244353
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 100000000

string s,t;
	
int value(int i,int j,int k){
	return i*(t.size()+1)*500+j*500+k;
}

int get_i(int x){
	x/=500;
	x/=t.size()+1;
	return x;
}

int get_j(int x){
	x/=500;
	return x%(t.size()+1);
}

int get_k(int x){
	return x%500;
}

int main(){
	
	cin>>s>>t;
	
	vector<vector<vector<int>>> dp(s.size()+1,vector<vector<int>> (t.size()+1,vector<int>(500,Inf)));
	
	vector<vector<pair<int,int>>> E((s.size()+1)*(t.size()+1)*500,vector<pair<int,int>>());
	
	dp[0][0][0] = 0;
	
	for(int i=0;i<=s.size();i++){
		for(int j=0;j<=t.size();j++){
			for(int k=0;k<500;k++){
				if(dp[i][j][k]==Inf)continue;
				if(i!=s.size()){
					int v = dp[i][j][k]+1;
					int ii = i+1;
					int jj = j;
					int kk = k;
					if(s[i]=='('){
						kk++;
					}
					else{
						if(kk==0)v++;
						else kk--;
					}
					E[value(ii,jj,kk)].emplace_back(value(i,j,k),v-dp[i][j][k]);
					dp[ii][jj][kk] = min(dp[ii][jj][kk],v);
				}
				if(j!=t.size()){
					int v = dp[i][j][k]+1;
					int ii = i;
					int jj = j+1;
					int kk = k;
					if(t[j]=='('){
						kk++;
					}
					else{
						if(kk==0)v++;
						else kk--;
					}
					E[value(ii,jj,kk)].emplace_back(value(i,j,k),v-dp[i][j][k]);
					dp[ii][jj][kk] = min(dp[ii][jj][kk],v);
				}
				
				if(i!=s.size()&&j!=t.size()){
					if(s[i]==t[j]){
						int v = dp[i][j][k]+1;
						int ii = i+1;
						int jj = j+1;
						int kk = k;
						if(s[i]=='('){
							kk++;
						}
						else{
							if(kk==0)v++;
							else kk--;
						}
						E[value(ii,jj,kk)].emplace_back(value(i,j,k),v-dp[i][j][k]);
						dp[ii][jj][kk] = min(dp[ii][jj][kk],v);
					}
				}
			}
		}
	}
	
	string ans = "";
	int now = -1;
	int mini = Inf;
	
	for(int i=0;i<500;i++){
		if(mini > dp[s.size()][t.size()][i] + i){
			mini = dp[s.size()][t.size()][i] + i;
			now = value(s.size(),t.size(),i);
		}
	}
	
	while(now != value(0,0,0)){
		for(int i=0;i<E[now].size();i++){
			int i1 = get_i(now),j1 = get_j(now),k1 = get_k(now);
			int i2 = get_i(E[now][i].first),j2 = get_j(E[now][i].first),k2 = get_k(E[now][i].first);
			if(dp[i2][j2][k2] + E[now][i].second == dp[i1][j1][k1]){
				if(i1==i2){
					ans += t[j2];
				}
				else{
					ans += s[i2];
				}
				now = value(i2,j2,k2);
			}
			else{
				continue;
			}
		}
	}
	
	reverse(ans.begin(),ans.end());
	
	mini = 0;
	now = 0;
	for(int i=0;i<ans.size();i++){
		if(ans[i]=='(')now++;
		else now--;
		mini = min(now,mini);
	}
	
	string A(-mini,'(');
	ans = A+ans;
	
	now=0;
	for(int i=0;i<ans.size();i++){
		if(ans[i]=='(')now++;
		else now--;
	}
	
	for(int i=0;i<now;i++){
		ans += ')';
	}
	
	cout<<ans<<endl;
	
	return 0;
}