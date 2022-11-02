#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

ld dp[2][111010];
ld dd[111010];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	if (m==1){
		cout<<"1.0"<<endl;
		return 0;
	}
	ld k=(ld)1/(ld)(m-1);
	dp[0][0]=1;
	int sc=0;
	for (int i=0;i<n;i++){
		int i2=i%2;
		int i2p=(i+1)%2;
		for (int a=0;a<=m*(i+3);a++){
			dp[i2p][a]=0;
			dd[a]=0;
		}
		int x;
		cin>>x;
		sc+=x;
		for (int j=0;j<=m*i;j++){
			dd[j+1]+=dp[i2][j]*k;
			dd[j+m+1]-=dp[i2][j]*k;
			dp[i2p][j+x]-=dp[i2][j]*k;
		}
		ld s=0;
		for (int j=0;j<=m*(i+1);j++){
			s+=dd[j];
			dp[i2p][j]+=s;
		}
	}
	ld v=0;
	for (int i=0;i<sc;i++){
		v+=dp[n%2][i]*(ld)(m-1);
	}
	cout<<setprecision(15)<<(ld)1.0+v<<endl;
}