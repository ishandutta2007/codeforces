#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"
const int maxn=5e3+20;
pair<pair<int,int>,int>wh[maxn];
int ww,hh;
int n;
int previ22[maxn];
int dp[maxn];
int bestend = -1;
int _max = -1;
stack<int>st;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> ww >> hh;
    for(int i = 0; i < n; i++)
    {
        cin >> wh[i].first.first >> wh[i].first.second;
        wh[i].second = i;
    }
    sort(wh,wh+n);
    int ii = 0;
    while(ww >= wh[ ii ].first.first && ii < n)
        ii++;
    while(hh >= wh[ ii ].first.second && ii < n)
        ii++;
    if(ii == n)
    {
        cout << 0;
        return 0;
    }
    dp[ii]=1;
    _max=1;
    previ22[ii]=-1;
    bestend = ii;
    for(int i = ii+1 ; i < n ;i++)
    {
        dp[i] = 1;
        previ22[i] = -1;
        for(int j = i-1 ; j >= ii; j--)
        {
            if (dp[j] + 1 > dp[i] && wh[j].first.second < wh[i].first.second && wh[i].first.second > hh && wh[j].first.second > hh && wh[j].first.first < wh[i].first.first)
            {
                dp[i] = dp[j] + 1;
                previ22[i] = j;
            }
        }
        if(dp[i] > _max)
        {
            bestend = i;
            _max=dp[i];
        }
    }
    ii = bestend;
    while(ii != -1)
    {
        st.push(ii);
        ii = previ22[ii];
    }
    cout << st.size() << endl;
    while(!st.empty())
    {
        cout << wh[st.top()].second +1 << " ";
        st.pop();
    }
}