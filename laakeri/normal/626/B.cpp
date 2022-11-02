#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[333][333][333];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string ss;
	cin>>ss;
	int b=0;
	int r=0;
	int g=0;
	for (int i=0;i<n;i++){
		if (ss[i]=='B') b++;
		if (ss[i]=='R') r++;
		if (ss[i]=='G') g++;
	}
	dp[b][g][r]=1;
	for (int s=300;s>1;s--){
		for (int i=300;i>=0;i--){
			for (int ii=300;ii>=0;ii--){
				int iii=s-i-ii;
				if (iii>=0){
					if (dp[i][ii][iii]){
						if (i>0&&ii>0){
							dp[i-1][ii-1][iii+1]=1;
						}
						if (i>0&&iii>0){
							dp[i-1][ii+1][iii-1]=1;
						}
						if (ii>0&&iii>0){
							dp[i+1][ii-1][iii-1]=1;
						}
						if (i>1) dp[i-1][ii][iii]=1;
						if (ii>1) dp[i][ii-1][iii]=1;
						if (iii>1) dp[i][ii][iii-1]=1;
					}
				}
			}
		}
	}
	if (dp[1][0][0]) cout<<'B';
	if (dp[0][1][0]) cout<<'G';
	if (dp[0][0][1]) cout<<'R';
	cout<<endl;
}