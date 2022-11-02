#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp1[555][10];
ll dp2[555][10];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	dp1[0][5]=1;
	dp2[0][3]=1;
	for (int i=0;i<n;i++){
		for (int j=0;j<=5;j++){
			for (int t=0;t<=j;t++){
				dp1[i+1][j-t]+=dp1[i][j];
				dp2[i+1][j-t]+=dp2[i][j];
			}
		}
	}
	cout<<dp1[n][0]*dp2[n][0]<<endl;
}