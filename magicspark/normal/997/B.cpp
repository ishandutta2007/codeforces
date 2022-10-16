#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int n;
bool dp[505][505*50];
int res[505];
signed main(){
	dp[0][0]=true;
	for(int i=1;i<=500;i++)
		for(int j=1;j<=500*50;j++)
			if(dp[i-1][j-1]||(j>=5&&dp[i-1][j-5])||(j>=10&&dp[i-1][j-10])||(j>=50&&dp[i-1][j-50]))dp[i][j]=true;
	int lmt=1000;
	for(int i=1;i<=500;i++){
	int ans=0;
	for(int j=1;j<=i*50;j++){
		if(dp[i][j])ans++;
	}
	res[i]=ans;
	}
	cin>>n;
	cout<<(n<=500?res[n]:res[500]+(n-500)*49);
	return 0;
}