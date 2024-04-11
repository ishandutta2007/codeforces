#include <bits/stdc++.h>
using namespace std;

const int MAXB = 1<<20;
const int inf = 1000000000;

int n,m,ans,len;
int p[100][100],p2[100][100],f[100][100];
int dp[1<<20];
string s[100];

int main(){
	cin >> n >> m;
	for (int i=0; i<n; i++)
		cin >> s[i];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++)
			cin >> p[i][j];
	for (int i=0; i<n; i++)
		for (int j=0; j<m; j++){
			p2[i][j] = 0;
			f[i][j] = 1<<i;
			for (int k=0; k<n; k++) if (i != k && s[i][j] == s[k][j]){
				p2[i][j]+= p[k][j];
				f[i][j] |= 1<<k;
			}
		}
	for (int i=0; i<MAXB; i++) dp[i] = inf;
	dp[0] = 0;
	for (int i=0; i<m; i++){
		for (int j=0; j<n; j++){
			for (int mask=(1<<n)-1; mask>=0; mask--){
				dp[mask|(1<<j)] = min(dp[mask|(1<<j)], dp[mask] + p[j][i]);
				dp[mask|f[j][i]]= min(dp[mask|f[j][i]],dp[mask] + p2[j][i]);
			}
		}
	}
	cout << dp[(1<<n)-1] << endl;
	return 0;
}