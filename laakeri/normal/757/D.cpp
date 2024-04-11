#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
int mod=1e9+7;

const int m=20;
int dp[80][1<<m];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin>>n>>s;
	for (int i=0;i<n;i++){
		dp[i][0]=1;
	}
	for (int i=0;i<n;i++){
		for (int b=0;b<(1<<m);b++){
			if (dp[i][b]==0) continue;
			int t=0;
			for (int j=i;j<n;j++){
				t*=2;
				t+=(s[j]-'0');
				if (t>=1&&t<=m){
					dp[j+1][b|(1<<(t-1))]+=dp[i][b];
					dp[j+1][b|(1<<(t-1))]%=mod;
				}
				if (t>m) break;
			}
		}
	}
	int v=0;
	for (int i=0;i<=n;i++){
		for (int j=1;j<=m;j++){
			v+=dp[i][(1<<j)-1];
			v%=mod;
		}
	}
	cout<<v<<endl;
}