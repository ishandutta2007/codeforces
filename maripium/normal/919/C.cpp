#include<bits/stdc++.h>
#define int long long
#define double long double
#define pb push_back
#define sp ' '
#define endl '\n'
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const double pi=acos(-1);
const int dx[]={-1,0,0,1};
const int dy[]={0,-1,1,0};
signed main()
{
    cin.tie(0);
    cout.tie(0);
int n,m,k;
cin>>n>>m>>k;
int dp1[2005][2005],dp2[2005][2005];
char c[2005][2005];
memset(dp2,0,sizeof dp2);
memset(dp2,0,sizeof dp2);
int ans=0;
for(int i=1;i<=n;++i){
	for(int j=1;j<=m;++j){
		cin>>c[i][j];
		if(c[i][j]=='*')dp1[i][j]=dp2[i][j]=0;
		else dp1[i][j]=dp1[i][j-1]+1,dp2[i][j]=dp2[i-1][j]+1;
		if(dp1[i][j]>=k)ans++;
		if(dp2[i][j]>=k)ans++;
		}
	}
	if(k==1){
		int res=0;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				if(c[i][j]=='.')res++;
				}
			}
		cout<<res<<endl;
		}
	else cout<<ans;

}