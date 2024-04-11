#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2010;
const int M = 1e6+10;
int n,m,i,mini = M,j,rx =0;
pii rob[N];
pii light[N];
int ans[M];

int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        rob[i] = {a,b};
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        light[i] = {a,b};
    }

    for(i=0;i<n;i++)
    {
        int cur_max = 0;
        for(j=0;j<m;j++)
        {
            if(rob[i].first <= light[j].first)
            {
                ans[light[j].first - rob[i].first] = max(ans[light[j].first - rob[i].first],light[j].second - rob[i].second+1);
            }
        }
    }
    for(i=M-1;i>=0;i--)
    {
        rx=max(rx,ans[i]);
        mini = min(mini,i+rx);
    }
    cout<<mini;
    return 0;
}