#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef double ld;

pair<ld, int> dp[2020][2020];
ld p[2020];
ld u[2020];

int n,a,b;

pair<ld, int> get(ld c){
	for (int i=0;i<=n;i++){
		for (int j=0;j<=b;j++){
			dp[i][j]={0, 0};
		}
	}
	for (int i=0;i<n;i++){
		for (int j=0;j<=b;j++){
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]);
			dp[i+1][j]=max(dp[i+1][j], {dp[i][j].F+p[i]-c, dp[i][j].S+1});
			dp[i+1][j+1]=max(dp[i+1][j+1], {dp[i][j].F+u[i], dp[i][j].S});
			dp[i+1][j+1]=max(dp[i+1][j+1], {dp[i][j].F+1-(1-p[i])*(1-u[i])-c, dp[i][j].S+1});
		}
	}
	return dp[n][b];
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>a>>b;
	for (int i=0;i<n;i++){
		cin>>p[i];
	}
	for (int i=0;i<n;i++){
		cin>>u[i];
	}
	ld mi=-1;
	ld ma=2;
	int lk=0;
	ld lv=0;
	int hk=n+1;
	ld hv=0;
	for (int it=0;it<40;it++){
		ld mid=(mi+ma)/2;
		auto t=get(mid);
		if (t.S>a){
			if (t.S<=hk){
				hk=t.S;
				hv=t.F+mid*t.S;
			}
			mi=mid;
		}
		else{
			ma=mid;
			if (t.S>=lk){
				lk=t.S;
				lv=t.F+mid*t.S;
			}
		}
	}
	ld v=lv+(hv-lv)/(ld)(hk-lk)*(a-lk);
	cout<<setprecision(15)<<v<<endl;
}