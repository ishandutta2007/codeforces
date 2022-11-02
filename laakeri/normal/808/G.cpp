#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

int link[101010];
int g[101010][30];

vector<int> dp[101010];

int main(){
	string s,t;
	cin>>s>>t;
	int n=s.size();
	int m=t.size();
	t+='#';
	link[0]=-1;
	for (int i=0;i<m;i++){
		int l=link[i];
		while (l!=-1&&t[l]!=t[i]) l=link[l];
		if (l!=-1) link[i+1]=l+1;
	}
	link[0]=0;
	for (int i=0;i<=m;i++){
		for (int j=0;j<30;j++){
			if (t[i]==(char)('a'+j)){
				g[i][j]=i+1;
			}
			else{
				g[i][j]=g[link[i]][j];
			}
		}
	}
	for (int i=0;i<=n;i++){
		dp[i].resize(m+1);
		fill(dp[i].begin(), dp[i].end(), -1);
	}
	dp[0][0]=0;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<=m;ii++){
			if (dp[i][ii]!=-1){
				if (s[i]=='?'){
					for (int j=0;j<26;j++){
						int nx=g[ii][j];
						if (nx==m){
							dp[i+1][nx]=max(dp[i+1][nx], dp[i][ii]+1);
						}
						else{
							dp[i+1][nx]=max(dp[i+1][nx], dp[i][ii]);
						}
					}
				}
				else{
					int nx=g[ii][s[i]-'a'];
					if (nx==m){
						dp[i+1][nx]=max(dp[i+1][nx], dp[i][ii]+1);
					}
					else{
						dp[i+1][nx]=max(dp[i+1][nx], dp[i][ii]);
					}
				}
			}
		}
	}
	int v=0;
	for (int i=0;i<=m;i++){
		v=max(v, dp[n][i]);
	}
	cout<<v<<endl;
}