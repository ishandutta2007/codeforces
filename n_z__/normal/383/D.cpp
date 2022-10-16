#include<bits/stdc++.h>
using namespace std;
#define int long long
int dp[2][200001];
const int p=1e9+7;
main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
	int n;
    cin>>n;
    int ans=0,s=0;
    int m=0;
    for(int x=1;x<=n;x++)
    {
        int y;
        cin>>y;
        memset(dp[m],0,sizeof(dp[m]));
        dp[m][y+10000]++;
        dp[m][-y+10000]++;
        s+=y;
        for(int z=-s;z<=s;z++)
        {
            if(dp[m^1][z+y+10000])dp[m][z+10000]+=dp[m^1][z+y+10000];
            if(dp[m^1][z-y+10000])dp[m][z+10000]+=dp[m^1][z-y+10000];
            dp[m][z+10000]%=p;
        }
        ans+=dp[m][10000];
        m^=1;
        ans%=p;
    }
    cout<<ans<<endl;
}