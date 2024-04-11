#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ld eps=1e-7;

const int D=7500;
ld dp[D+20][1010];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int k,q;
	cin>>k>>q;
	dp[0][0]=1;
	for (int i=0;i<D;i++){
		for (int j=0;j<=min(i, k);j++){
			if (j==k){
				dp[i+1][j]+=dp[i][j];
			}
			else{
				ld p=(ld)(k-j)/(ld)k;
				dp[i+1][j+1]+=dp[i][j]*p;
				dp[i+1][j]+=dp[i][j]*((ld)1-p);
			}
		}
	}
	for (int qq=0;qq<q;qq++){
		int pp;
		cin>>pp;
		ld p=((ld)pp-eps)/(ld)2000;
		for (int i=0;i<D;i++){
			if (dp[i][k]>p){
				cout<<i<<'\n';
				break;
			}
		}
	}
}