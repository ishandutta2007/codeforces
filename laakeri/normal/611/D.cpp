#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
const ll mod=1e9+7;

ll dp[5555][5555];
int ys[5555][5555];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for (int i=n-1;i>=0;i--){
		for (int ii=n-1;ii>=0;ii--){
			if (s[i]==s[ii]){
				ys[i][ii]=ys[i+1][ii+1]+1;
			}
			else{
				ys[i][ii]=0;
			}
		}
	}
	dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int ii=i;ii<n;ii++){
			if (dp[i][ii]>0){
				if (i!=0||ii!=0) dp[i][ii+1]+=dp[i][ii];
				dp[i][ii+1]%=mod;
				if (s[ii]!='0'){
					//cout<<i<<" "<<ii<<" "<<dp[i][ii]<<" "<<ys[i][ii]<<endl;
					int ele=ii-i;
					if (ys[i][ii]>=ele){
						if (ii+ele+1<=n){
							//cout<<"t1"<<endl;
							dp[ii][ii+ele+1]+=dp[i][ii];
							dp[ii][ii+ele+1]%=mod;
						}
					}
					else{
						if (s[i+ys[i][ii]]>=s[ii+ys[i][ii]]){
							if (ii+ele+1<=n){
								//cout<<"taa1"<<endl;
								dp[ii][ii+ele+1]+=dp[i][ii];
								dp[ii][ii+ele+1]%=mod;
							}
						}
						else{
							if (ii+ele<=n){
								//cout<<"taa2"<<endl;
								dp[ii][ii+ele]+=dp[i][ii];
								dp[ii][ii+ele]%=mod;
							}
						}
					}
				}
			}
		}
	}
	ll v=0;
	for (int i=0;i<n;i++){
		//cout<<i<<" "<<dp[i][n]<<endl;
		v+=dp[i][n];
		v%=mod;
	}
	cout<<v<<endl;
}