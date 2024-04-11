#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

string s[22];
int a[101010];
int dp[22][(1<<20)];

int n,m;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	
	for (int i=0;i<n;i++){
		cin>>s[i];
	}
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++){
			if (s[j][i]=='1') a[i]|=(1<<j);
		}
	}
	for (int i=0;i<m;i++){
		dp[0][a[i]]++;
		dp[0][a[i]^((1<<n)-1)]++;
	}
	for (int b=0;b<n;b++){
		for (int i=n;i>=1;i--){
			for (int bb=0;bb<(1<<n);bb++){
				dp[i][bb]+=dp[i-1][bb^(1<<b)];
			}
		}
	}
	int v=m*n;
	for (int b=0;b<(1<<n);b++){
		int t=0;
		for (int i=0;i<=n/2;i++){
			if (i*2==n){
				t+=i*dp[i][b]/2;
			}
			else{
				t+=i*dp[i][b];
			}
		}
		v=min(v, t);
	}
	cout<<v<<endl;
}