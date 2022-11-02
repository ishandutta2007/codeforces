/**
    Ithea Myse Valgulious
**/
 
#include<bits/stdc++.h>
#define ll long long
#define x first
#define y second
using namespace std;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
int T;
 
void solve()
{
    int n,m,i;
    vector<pii> rooks;
    cin>>n>>m;
    int xx[n],yy[n];
    bool visit[n],used[n];
    for(i=0;i<n;i++)
    {
        xx[i] = -1, yy[i] = -1;
        visit[i] = false, used[i] = false;
    }
    for(i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        rooks.push_back({a,b});
        xx[a] = i;
        yy[b] = i;
    }
    int ans = 0;
    for(i=0;i<n;i++)
    {
        if(visit[i])
            continue;
 
        visit[i] = true;
        bool compute = false;
        if(!(xx[i] == -1 || used[xx[i]]))
        {
            if(rooks[xx[i]].y == i)
                continue;
            ans++;
            int runner = rooks[xx[i]].y;
            while(!visit[runner])
            {
                visit[runner] = true;
                if(xx[runner]==-1 || used[xx[runner]])
                    break;
                runner = rooks[xx[runner]].y;
                ans++;
            }
            if(runner == i)
                ans++;
            compute = true;
        }
 
        if(!compute && yy[i] !=-1 && !used[yy[i]])
        {
            used[yy[i]] = true;
            ans++;
        }
 
    }
    cout<<ans<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>T;
    while(T--)
        solve();
    return 0;
}