#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

string ss[3];

int dp[3][300];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int tcs;
	cin>>tcs;
	for (int tc=0;tc<tcs;tc++){
		int n,k;
		cin>>n>>k;
		cin>>ss[0]>>ss[1]>>ss[2];
		ss[0]+=".....";
		ss[1]+=".....";
		ss[2]+=".....";
		for (int i=0;i<300;i++){
			dp[0][i]=0;
			dp[1][i]=0;
			dp[2][i]=0;
		}
		if (ss[0][0]=='s') dp[0][0]=1;
		if (ss[1][0]=='s') dp[1][0]=1;
		if (ss[2][0]=='s') dp[2][0]=1;
		for (int i=0;i<n;i++){
			for (int j=0;j<3;j++){
				if (ss[j][i]=='.'||ss[j][i]=='s'){
					if (dp[j][i]==1){
						if (i%3==0){
							if (ss[j][i+1]=='.'){
								dp[j][i+1]=1;
								if (j==0||j==1){
									if (ss[0][i+1]=='.') dp[0][i+1]=1;
									if (ss[1][i+1]=='.') dp[1][i+1]=1;
								}
								if (j==1||j==2){
									if (ss[2][i+1]=='.') dp[2][i+1]=1;
									if (ss[1][i+1]=='.') dp[1][i+1]=1;
								}
							}
						}
						else if(i%3==1){
							if (ss[j][i+1]=='.'&&ss[j][i+2]=='.'){
								dp[j][i+2]=1;
							}
						}
					}
				}
			}
		}
		int ok=0;
		for (int i=n;i<n+3;i++){
			for (int j=0;j<3;j++){
				if (dp[j][i]==1){
					ok=1;
				}
			}
		}
		if (ok){
			cout<<"YES\n";
		}
		else{
			cout<<"NO\n";
		}
	}
}