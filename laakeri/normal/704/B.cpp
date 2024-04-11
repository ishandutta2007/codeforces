#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[2][5050][2][2];

ll x[5050];
ll a[5050];
ll b[5050];
ll c[5050];
ll d[5050];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,s,e;
	cin>>n>>s>>e;
	s--;
	e--;
	for (int i=0;i<n;i++){
		cin>>x[i];
	}
	for (int i=0;i<n;i++){
		cin>>a[i];
	}
	for (int i=0;i<n;i++){
		cin>>b[i];
	}
	for (int i=0;i<n;i++){
		cin>>c[i];
	}
	for (int i=0;i<n;i++){
		cin>>d[i];
	}
	for (int i=0;i<2;i++){
		for (int ii=0;ii<=5040;ii++){
			for (int j=0;j<2;j++){
				for (int jj=0;jj<2;jj++){
					dp[i][ii][j][jj]=1e18;
				}
			}
		}
	}
	dp[0][0][0][0]=0;
	for (int i=0;i<n;i++){
		int ti=i%2;
		int ni=(i+1)%2;
		for (int ii=0;ii<=5040;ii++){
			for (int j=0;j<2;j++){
				for (int jj=0;jj<2;jj++){
					dp[ni][ii][j][jj]=1e18;
				}
			}
		}
		for (int j=0;j<=n;j++){
			for (int v=0;v<2;v++){
				for (int o=0;o<2;o++){
					if (dp[ti][j][v][o]>1e17) continue;
					//cout<<i<<" "<<j<<" "<<v<<" "<<o<<" "<<dp[i][j][v][o]<<endl;
					ll tv=dp[ti][j][v][o];
					if (i==s){
						dp[ni][j][1][o]=min(dp[ni][j][1][o], tv-x[i]+d[i]);
						if (j>1){
							dp[ni][j-2][1][o]=min(dp[ni][j-2][1][o], tv+x[i]+c[i]);
						}
						if (o>0&&i==n-1){
							dp[ni][j][0][0]=min(dp[ni][j][0][0], tv+x[i]+c[i]);
						}
					}
					else if(i==e){
						dp[ni][j][v][1]=min(dp[ni][j][v][1], tv-x[i]+b[i]);
						if (j>1){
							dp[ni][j-2][v][1]=min(dp[ni][j-2][v][1], tv+x[i]+a[i]);
						}
						if (v>0&&i==n-1){
							dp[ni][j][0][0]=min(dp[ni][j][0][0], tv+x[i]+a[i]);
						}
					}
					else{
						dp[ni][j+2][v][o]=min(dp[ni][j+2][v][o], tv-2*x[i]+b[i]+d[i]);
						if (j>0){
							dp[ni][j][v][o]=min(dp[ni][j][v][o], tv+a[i]+d[i]);
							dp[ni][j][v][o]=min(dp[ni][j][v][o], tv+b[i]+c[i]);
						}
						if (v>0&&o>0&&i==n-1){
							dp[ni][j][0][0]=min(dp[ni][j][0][0], tv+2*x[i]+a[i]+c[i]);
						}
						if (v>0){
							dp[ni][j][v][o]=min(dp[ni][j][v][o], tv+a[i]+d[i]);
						}
						if (o>0){
							dp[ni][j][v][o]=min(dp[ni][j][v][o], tv+b[i]+c[i]);
						}
						if ((v>0||o>0)&&j>0){
							dp[ni][j-2][v][o]=min(dp[ni][j-2][v][o], tv+2*x[i]+a[i]+c[i]);
						}
						if (j>3){
							//cout<<2*x[i]+a[i]+c[i]<<" "<<tv<<endl;
							dp[ni][j-2][v][o]=min(dp[ni][j-2][v][o], tv+2*x[i]+a[i]+c[i]);
						}
					}
				}
			}
		}
	}
	cout<<dp[n%2][0][0][0]<<endl;
}