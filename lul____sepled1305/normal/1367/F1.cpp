#include<bits/stdc++.h>
using namespace std;
int T;

int main()
{
    cin>>T;
    while(T--)
    {
        int n,i,j,mini = 1e9;
        cin>>n;
        int a[n], ori[n], dp[n];
        for(i=0;i<n;i++)
        {
            cin>>a[i];
            ori[i] = a[i];
        }
        sort(ori,ori+n);
        map<int,int> mp;
        for(i=0;i<n;i++)
            mp.insert({ori[i],i});
        dp[0] = n-1;
        for(i=0;i<n;i++)
        {
            bool pass = false;
            int cur  = mp[a[i]];
            for(j=0;j<i;j++)
            {
                int here = mp[a[j]];
                if(here == cur-1)
                {
                    dp[i] = dp[j] - 1;
                    pass = true;
                }
            }
            if(!pass)
                dp[i] = n-1;
            if(dp[i]<mini)
                mini = dp[i];
        }
        cout<<mini<<"\n";
    }
    return 0;
}