#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int a[1010][1010],b[1010][1010];
void solve(){
	int n,ans=0;cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>a[i][j];
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)b[i][j]=i?1^(j>0?b[i-1][j-1]:0)^(j<n-1?b[i-1][j+1]:0)^(i>1?b[i-2][j]:0):0;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(b[i][j])ans^=a[i][j];
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}