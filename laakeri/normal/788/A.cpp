#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[101010][2];
ll a[101010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	ll inf=1e9;
	for (int i=0;i<n;i++){
		dp[i][1]=-inf;
	}
	ll v=-inf;
	for (int i=0;i+1<n;i++){
		for (int k=0;k<2;k++){
			ll tv=abs(a[i]-a[i+1]);
			if (k==1) tv=-tv;
			tv+=dp[i][k];
			v=max(v, tv);
			dp[i+1][k^1]=max(dp[i+1][k^1], tv);
		}
	}
	cout<<v<<endl;
}