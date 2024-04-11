#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[1010101];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a,b,c;
	cin>>a>>b>>c;
	dp[0]=1;
	for (int i=0;i<=c;i++){
		if (dp[i]){
			dp[i+a]=1;
			dp[i+b]=1;
		}
	}
	if (dp[c]==1){
		cout<<"Yes\n";
	}
	else{
		cout<<"No\n";
	}
}