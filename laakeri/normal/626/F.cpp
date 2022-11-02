#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

const ll mod=1e9+7;

ll dp[222][1010][111];

int a[222];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,k;
	cin>>n>>k;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a, a+n);
	a[n]=3000;
	dp[0][0][0]=1;
	for (int i=0;i<n;i++){
		for (int s=0;s<=k;s++){
			for (int g=0;g<=n/2;g++){
				if (dp[i][s][g]==0) continue;
				if (s+(a[i+1]-a[i])*g<=k){
					dp[i+1][s+(a[i+1]-a[i])*g][g]+=dp[i][s][g];
					dp[i+1][s+(a[i+1]-a[i])*g][g]%=mod;
				}
				if (g>0){
					if (s+(a[i+1]-a[i])*g<=k){
						dp[i+1][s+(a[i+1]-a[i])*g][g]+=dp[i][s][g]*(ll)g;
						dp[i+1][s+(a[i+1]-a[i])*g][g]%=mod;
					}
					
					if (s+(a[i+1]-a[i])*(g-1)<=k){
						dp[i+1][s+(a[i+1]-a[i])*(g-1)][g-1]+=dp[i][s][g]*(ll)g;
						dp[i+1][s+(a[i+1]-a[i])*(g-1)][g-1]%=mod;
					}
				}
				
				if (s+(a[i+1]-a[i])*(g+1)<=k){
					dp[i+1][s+(a[i+1]-a[i])*(g+1)][g+1]+=dp[i][s][g];
					dp[i+1][s+(a[i+1]-a[i])*(g+1)][g+1]%=mod;
				}
			}
		}
	}
	ll v=0;
	for (int i=0;i<=k;i++){
		v+=dp[n][i][0];
		v%=mod;
	}
	cout<<v<<endl;
}