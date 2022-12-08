#include <bits/stdc++.h>
#define int long long

using namespace std;

int dp[12];

signed main()
{
    int n;
    cin>>n;
    for(int i=1; i<=9; i++)
    {
        dp[i]=-100000000000000000;
    }
    for(int ii=1; ii<=n; ii++)
    {
        int cnt;
        cin>>cnt;
        vector<int> a[4];
        for(int i=1; i<=cnt; i++)
        {
            int u, v;
            cin>>u>>v;
            a[u].push_back(v);
        }
        for(int i=1; i<=3; i++)
        {
            sort(a[i].begin(), a[i].end());
        }
        int dp1[12];
        for(int i=0; i<=9; i++) dp1[i]=-1000000000000000;
        int sm1=0, mx1=0;
        for(int t1=0; t1<=a[1].size(); t1++)
        {
            if(t1>3) break;
            if(t1>0)
            {
                sm1+=a[1][a[1].size()-t1];
                mx1=max(mx1, a[1][a[1].size()-t1]);
            }
            int sm2=0, mx2=0;
            for(int t2=0; t2<=a[2].size(); t2++)
            {
                if(t1+2*t2>3) break;
                if(t2>0)
                {
                    sm2+=a[2][a[2].size()-t2];
                    mx2=max(mx2, a[2][a[2].size()-t2]);
                }
                int sm3=0, mx3=0;
                for(int t3=0; t3<=a[3].size(); t3++)
                {
                    if(t1+2*t2+3*t3>3) break;
                    if(t3>0)
                    {
                        sm3+=a[3][a[3].size()-t3];
                        mx3=max(mx3, a[3][a[3].size()-t3]);
                    }
                    for(int j=0; j<=9; j++)
                    {
                        int nxt=(j+t1+t2+t3)%10;
                        if(nxt<j) dp1[nxt]=max(dp1[nxt], dp[j]+sm1+sm2+sm3+max(mx1, max(mx2, mx3)));
                        else dp1[nxt]=max(dp1[nxt], dp[j]+sm1+sm2+sm3);
                    }
                }
            }
        }
        for(int i=0; i<=9; i++)
        {
            dp[i]=dp1[i];
        }
    }
    int ans=0;
    for(int i=0; i<=9; i++)
    {
        ans=max(ans, dp[i]);
    }
    cout<<ans;
}