//#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define mp make_pair
#define pb push_back
#define a first 
#define b second
#define endl '\n'

int t;
int dp[2001][2001];
int pre[26][2001];
int pre2[26][2001];
int co[30];
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<26;i++){
			co[i]=0;
		}
		string s;
		string ss;
		cin>>s>>ss;
		int st=1;
		for(int i=0;i<n;i++){
			co[s[i]-'a']++;
			co[ss[i]-'a']--;
		}
		for(int i=0;i<26;i++){
			for(int j=1;j<=n;j++){
				pre[i][j]=pre[i][j-1];
				if(s[j-1]-'a'==i){
					pre[i][j]++;
				}
				/*if(ss[j-1]-'a'==i){
					pre[i][j]++;
				}*/
			}
		}
		for(int i=0;i<26;i++){
			for(int j=1;j<=n;j++){
				pre2[i][j]=pre2[i][j-1];
				if(ss[j-1]-'a'==i){
					pre2[i][j]++;
				}
				/*if(ss[j-1]-'a'==i){
					pre[i][j]++;
				}*/
			}
		}
		for(int i=0;i<26;i++){
			if(co[i]!=0){
				st=0;
			}
		}
		if(st==0){
			cout<<-1<<endl;
			continue;
		}
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				dp[i][j]=n;
				if(i==0){
					dp[i][j]=0;
				}
			}
		}

		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(s[i-1]==ss[j-1]){
					dp[i][j]=min(dp[i][j],dp[i-1][j-1]);
				}
				if(pre[ss[j-1]-'a'][n]-pre[ss[j-1]-'a'][i]>pre2[ss[j-1]-'a'][n]-pre2[ss[j-1]-'a'][j]){
					dp[i][j]=min(dp[i][j],dp[i][j-1]);
				}
				dp[i][j]=min(dp[i][j],dp[i-1][j]+1);
				/*if(i>0){
					dp[i][j]=max(dp[i][j],dp[i-1][j]);
				}
				if(j>0){
					dp[i][j]=max(dp[i][j],dp[i][j-1]);
				}
				if(i>0 and j>0 and i<=j){
					if(s[i-1]==ss[j-1]){
						dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
					}
				}*/
			}
		}
		cout<<dp[n][n]<<endl;
	}




 
	return 0;
}