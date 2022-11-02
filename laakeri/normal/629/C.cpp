#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod=1e9+7;

ll dp[2020][5050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int c=0;
	string s;
	cin>>s;
	int mic=0;
	for (int i=0;i<m;i++){
		if (s[i]==')') c--;
		else c++;
		mic=min(mic, c);
	}
	if (abs(c)>n-m){
		cout<<0<<endl;
		return 0;
	}
	dp[0][0]=1;
	for (int i=0;i<=2000;i++){
		for (int ii=0;ii<=2000;ii++){
			if (ii>=1) {
				dp[i+1][ii-1]+=dp[i][ii];
				dp[i+1][ii-1]%=mod;
			}
			dp[i+1][ii+1]+=dp[i][ii];
			dp[i+1][ii+1]%=mod;
		}
	}
	n-=m;
	ll v=0;
	for (int i=0;i<=2000;i++){
		for (int ii=0;ii<=2000;ii++){
			if (i<=n){
				if (ii+mic>=0){
					v+=dp[i][ii]*dp[n-i][ii+c];
					v%=mod;
				}
			}
		}
	}
	cout<<v<<endl;
}