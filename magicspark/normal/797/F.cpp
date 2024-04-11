#include<bits/stdc++.h>
#define int long long
using namespace std;

int n,m;
int x[5005];
pair<int,int>hole[5005];
int dp[5005][5005];
//dp[i][j]:solve first i mice with first j holes
int f[5005];
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	int sum=0;
	for(int i=1;i<=m;i++){
		cin>>hole[i].first>>hole[i].second;sum+=hole[i].second;
	}
	if(sum<n){
		puts("-1");
		return 0;
	}
	sort(hole+1,hole+m+1);
	memset(dp,0x3f3f3f3f3f3f3f3f,sizeof dp);
	for(int i=0;i<=5000;i++)dp[i][0]=0;
	for(int i=1;i<=m;i++){
		deque<pair<int,int> >q;
		for(int j=1;j<=n;j++){
			f[j]=abs(x[j]-hole[i].first);
		}f[0]=0;
		for(int j=1;j<=n;j++)f[j]+=f[j-1];
		for(int j=0;j<=n;j++){
			while(!q.empty()&&q.front().second<j-hole[i].second)q.pop_front();
			while(!q.empty()&&q.back().first+f[j]-f[q.back().second]>dp[i-1][j])q.pop_back();
			q.push_back(make_pair(dp[i-1][j],j));
			dp[i][j]=q.front().first+f[j]-f[q.front().second];
//			cerr<<i<<" "<<j<<
			//" "<<q.front().first<<" "<<f[j]<<" "<<f[q.front().second]<<
//			" "<<dp[i][j]<<endl;
		}
	}
	cout<<dp[m][n]<<endl;
	return 0;
}