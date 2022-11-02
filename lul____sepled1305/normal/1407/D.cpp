#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 1e9+10;
const int N = 3e5+10;
int n,i;
int h[N];
stack<pii> st_high, st_low;
int dp[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n;
    for(i=0;i<n;i++)
        cin>>h[i], dp[i] = INF;

    st_high.push({h[0],0});
    st_low.push({h[0],0});
    dp[0] = 0;

    for(i=1;i<n;i++)
    {
        pii u = st_high.top();
        int height = u.first;
        int node = u.second;

        while(!st_high.empty() && height < h[i])
        {
            dp[i] = min(dp[i],dp[node]+1);
            st_high.pop();
            if(!st_high.empty())
            {
                pii u = st_high.top();
                height = u.first;
                node = u.second;
            }
        }

        while(!st_high.empty() && height == h[i])
        {
            st_high.pop();
            if(!st_high.empty())
            {
                pii u = st_high.top();
                height = u.first;
            }
        }
        dp[i] = min(dp[i],dp[node]+1);

        u = st_low.top();
        height = u.first;
        node = u.second;

        while(!st_low.empty() && height > h[i])
        {
            dp[i] = min(dp[i],dp[node]+1);
            st_low.pop();
            if(!st_low.empty())
            {
                pii u = st_low.top();
                height = u.first;
                node = u.second;
            }
        }
        while(!st_low.empty() && height == h[i])
        {
            st_low.pop();
            if(!st_low.empty())
            {
                pii u = st_low.top();
                height = u.first;
            }
        }
        dp[i] = min(dp[i],dp[node]+1);

        st_high.push({h[i],i});
        st_low.push({h[i],i});
    }
    cout<<dp[n-1]<<endl;
    return 0;
}