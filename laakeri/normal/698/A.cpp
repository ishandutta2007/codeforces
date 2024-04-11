#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[111][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		for (int j=0;j<3;j++){
			dp[i+1][0]=max(dp[i+1][0], dp[i][j]);
			if ((j==0||j==2)&&(a&1)>0){
				dp[i+1][1]=max(dp[i+1][1], dp[i][j]+1);
			}
			if ((j==0||j==1)&&(a&2)>0){
				dp[i+1][2]=max(dp[i+1][2], dp[i][j]+1);
			}
		}
	}
	int v=max(dp[n][0], dp[n][1]);
	v=max(v, dp[n][2]);
	cout<<n-v<<endl;
}