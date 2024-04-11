#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 1000000000000000000

int get(string &A,string &B){
	int ret = 0;
	for(int i=0;i<A.size();i++){
		if(A[i]=='1'&&B[i]=='0'){
			return 10000;
		}
		else{
			if(A[i]!=B[i])ret++;
		}
	}
	return ret;
}
		

int main(){
	
	int n,k;
	cin>>n>>k;
	
	vector<string> V = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	
	vector<string> S(n);
	for(int i=0;i<n;i++){
		cin>>S[i];
	}
	
	reverse(S.begin(),S.end());
	
	vector<vector<bool>> dp(n+1,vector<bool>(k+1,false));
	dp[0][0] = true;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++){
			if(dp[i][j]==false)continue;
			for(int d=0;d<10;d++){
				int to = j + get(S[i],V[d]);
				if(to>k)continue;
				dp[i+1][to] = true;
			}
		}
	}
	
	if(dp.back().back()==false){
		cout<<-1<<endl;
		return 0;
	}
	
	vector<int> ans(n);
	int now = k;
	
	for(int i=0;i<n;i++){
		for(int j=9;j>=0;j--){
			int c = get(S[n-1-i],V[j]);
			if(now-c>=0&&dp[n-1-i][now-c]){
				now -= c;
				ans[i] = j;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++)cout<<ans[i];
	cout<<endl;
	
	
	
	return 0;
}