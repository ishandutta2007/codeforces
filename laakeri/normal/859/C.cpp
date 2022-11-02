#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[55][2];
int a[55];


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int su=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		su+=a[i];
	}
	for (int i=n-1;i>=0;i--){
		dp[i][0]=max(a[i]+dp[i+1][1], dp[i+1][0]);
		dp[i][1]=min(dp[i+1][1]+a[i], dp[i+1][0]);
	}
	cout<<dp[0][1]<<" "<<su-dp[0][1]<<endl;
}