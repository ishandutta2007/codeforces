#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod=1e9+7;

int dp[5050][5050];

int ne[5050][30];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	string t;
	for (int i=0;i<n;i++){
		if (t.size()==0||t.back()!=s[i]){
			t+=s[i];
		}
	}
	int m=t.size();
	for (int i=0;i<30;i++){
		ne[m][i]=m;
	}
	for (int i=m-1;i>=0;i--){
		for (int j=0;j<30;j++){
			ne[i][j]=ne[i+1][j];
			if ((t[i]-'a')==j){
				ne[i][j]=i;
			}
		}
	}
	dp[0][0]=1;
	for (int i=0;i<n;i++){
		for (int ii=0;ii<m;ii++){
			if (dp[i][ii]==0) continue;
			for (int c=0;c<26;c++){
				if (ne[ii][c]<m){
					dp[i+1][ne[ii][c]]+=dp[i][ii];
					dp[i+1][ne[ii][c]]%=mod;
				}
			}
		}
	}
	int v=0;
	for (int i=0;i<m;i++){
		v+=dp[n][i];
		v%=mod;
	}
	cout<<v<<endl;
}