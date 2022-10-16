#include<bits/stdc++.h>
using namespace std;
int cnt[233][233];
int dp[1<<20];
int n,m;
string s;
int f(int x,int y){
	return cnt[x][y]+cnt[y][x];
}
int main(){
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<s.size();i++){
		cnt[s[i-1]-'a'][s[i]-'a']++;
	}
	memset(dp,0x3f3f3f3f,sizeof dp);
	dp[0]=0;
	for(int i=0;i<(1<<m);i++){
		int add=0;
		for(int k=0;k<m;k++){
				if(i&(1<<k))
					for(int l=0;l<m;l++)if(!(i&(1<<l)))add+=f(l,k);
			}
		for(int nxt=0;nxt<m;nxt++){
			if(i&(1<<nxt))continue;
			dp[i|(1<<nxt)]=min(dp[i|(1<<nxt)],dp[i]+add);
		}
	}
	cout<<dp[(1<<m)-1]<<endl;
	return 0;
}