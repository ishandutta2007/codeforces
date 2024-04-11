#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

ll dp[100][5][100][3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	dp[0][0][0][0]=1;
	for (int i=0;i<n*2-2;i++){
		for (int ii=0;ii<5;ii++){
			for (int iii=0;iii<n*2;iii++){
				for (int h=0;h<2;h++){
					for (int c=1;c<5;c++){
						if (c==ii){
							if (iii+1==n){
								dp[i+1][c][iii+1][max(1, h)]+=dp[i][ii][iii][h];
							}
							else if(iii+1>n){
								dp[i+1][c][iii+1][2]+=dp[i][ii][iii][h];
							}
							else{
								dp[i+1][c][iii+1][h]+=dp[i][ii][iii][h];
							}
						}
						else{
							dp[i+1][c][1][h]+=dp[i][ii][iii][h];
						}
					}
				}
			}
		}
	}
	ll v=0;
	for (int i=1;i<=4;i++){
		for (int ii=0;ii<100;ii++){
			v+=dp[n*2-2][i][ii][1];
		}
	}
	cout<<v<<endl;
}