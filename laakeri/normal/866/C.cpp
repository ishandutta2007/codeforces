#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef double ld;

int n,r;

ld dp[55][5555];

int f[55];
int s[55];
ld p[55];

ld go(ld t){
	for (int i=n-1;i>=0;i--){
		for (int ii=0;ii<r;ii++){
			ld v1=min(t, dp[i+1][ii+f[i]])+(ld)f[i];
			ld v2=min(t, dp[i+1][ii+s[i]])+(ld)s[i];
			dp[i][ii]=p[i]*v1+((ld)1-p[i])*v2;
		}
	}
	return dp[0][0];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>r;
	for (int i=0;i<n;i++){
		cin>>f[i]>>s[i]>>p[i];
		p[i]/=(ld)100;
	}
	for (int i=0;i<=n+1;i++){
		for (int ii=0;ii<=r+222;ii++){
			dp[i][ii]=1e90;
		}
	}
	for (int i=0;i<=r;i++){
		dp[n][i]=0;
	}
	ld mi=1;
	ld ma=1e15;
	for (int it=0;it<150;it++){
		ld mid=(mi+ma)/(ld)2;
		ld x=go(mid);
		if (x>mid){
			mi=mid;
		}
		else{
			ma=mid;
		}
	}
	cout<<setprecision(15)<<(mi+ma)/(ld)2<<endl;
}