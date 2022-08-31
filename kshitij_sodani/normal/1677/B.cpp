#include <bits/stdc++.h>
using namespace std;
typedef long long llo;
#define a first
#define b second
#define pb push_back
#define endl '\n'

llo t;
int it[1000001];
int dp[1000001];
int pre[1000001];
int pre2[1000001];
int pre3[1000001];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		string s;
		cin>>s;
		for(int i=0;i<n*m;i++){
			it[i]=s[i]-'0';
			pre[i+1]=pre[i]+it[i];
		}
		for(int i=0;i<n*m;i++){
			if(i<m){
				pre2[i]=0;
				if(it[i]==1){
					pre2[i]=1;
				}
			}
			else{
				pre2[i]=pre2[i-m];
				if(it[i]==1){
					pre2[i]=1;
				}
			}
			pre3[i+1]=pre3[i]+pre2[i];
		}
		for(int i=0;i<n*m;i++){
			if(i<m){
				dp[i]=0;
				if(pre[i+1]>=1){
					dp[i]=1;
				}
			}
			else{
				dp[i]=dp[i-m];
				if(pre[i+1]-pre[i-m+1]>=1){
					dp[i]+=1;
				}
			}
			llo su=dp[i]+pre3[i+1];
			if(i-m>=0){
				su-=pre3[i-m+1];
			}
			cout<<su<<" ";
		}
		cout<<endl;





	}







	return 0;
}