/** Ogiso Setsuna best girl **/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fi first
#define se second
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int MOD = 1e9+7;
const int chtholly = 0;
const int INF = 1e9+10;
int T;
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>T;
    while(T--)
    {
        int n,i,j;
        cin>>n;
        int a[n];
        int last[n];
        int dist[n];
        int ans[n];
        for(i=0;i<n;i++)
            cin>>a[i], a[i]--;
        for(i=0;i<n;i++)
            last[i] = -1, dist[i] = -1;
        for(i=0;i<n;i++)
        {
            int dis = i - last[a[i]];
            dist[a[i]] = max(dist[a[i]],dis);
            ans[i] = INF;
            last[a[i]] = i;
        }
        for(i=0;i<n;i++)
        {
            int dis = n - last[i];
            dist[i] = max(dist[i],dis);
        }
        for(i=0;i<n;i++)
        {
            if(dist[i] == n+1)
                continue;
 
            for(j = dist[i]-1; j<n;j++)
            {
                if(ans[j] == INF)
                    ans[j] = i+1;
                else
                    break;
            }
        }
        for(i=0;i<n;i++)
        {
            if(ans[i] == INF)
                cout<<-1<<' ';
            else
                cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    return chtholly;
}