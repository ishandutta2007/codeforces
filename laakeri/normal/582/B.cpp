#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[1111];
int a[1111];
int f[1111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,t;
	cin>>n>>t;
	for (int i=0;i<n;i++){
		cin>>a[i];
		f[a[i]]++;
	}
	int v=0;
	if (t<=700){
		for (int i=0;i<t*n;i++){
			int tt=a[i%n];
			int m=0;
			for (int ii=1;ii<=tt;ii++){
				m=max(m, dp[ii]);
			}
			dp[tt]=m+1;
			v=max(v, dp[tt]);
		}
	}
	else{
		for (int i=0;i<300*n;i++){
			int tt=a[i%n];
			int m=0;
			for (int ii=1;ii<=tt;ii++){
				m=max(m, dp[ii]);
			}
			dp[tt]=m+1;
		}
		for (int i=0;i<1000;i++){
			dp[i]+=(t-600)*f[i];
			v=max(v, dp[i]);
		}
		for (int i=0;i<300*n;i++){
			int tt=a[i%n];
			int m=0;
			for (int ii=1;ii<=tt;ii++){
				m=max(m, dp[ii]);
			}
			dp[tt]=m+1;
			v=max(v, dp[tt]);
		}
	}
	cout<<v<<endl;
}