#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;

int dp[111];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	cin>>s;
	for (int i=0;i<=(int)s.size();i++) dp[i]=i+1;
	dp[0]=1;
	for (int i=0;i<(int)s.size();i++){
		if (s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'||s[i]=='Y'){
			for (int j=i+1;j<=(int)s.size();j++){
				dp[j]=min(dp[j], max(dp[i], j-i));
			}
		}
	}
	cout<<dp[s.size()]<<endl;
}