#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int n,m,i,j;
int val[2000][2000];
queue<pair<int,int>> qu;
string a[2000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>n>>m;
    for(i=0; i<n; i++)
        cin>>a[i];

    /**Pre-assign all value to infinity**/
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            val[i][j] = INF;

    /** Finding all square which val[i][j] == 1 and push that into queue for BFS **/
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(i==0 || i==n-1 || j==0 || j==m-1)
                qu.push({i,j}),val[i][j] = 1;
            else
            {
                if(a[i-1].at(j)!=a[i].at(j) || a[i+1].at(j)!=a[i].at(j) || a[i].at(j-1)!=a[i].at(j) || a[i].at(j+1)!=a[i].at(j))
                    qu.push({i,j}),val[i][j] = 1;
            }
        }
    }

    /** BFS **/
    while(!qu.empty())
    {
        pair<int,int> cur = qu.front();
        qu.pop();
        int x = cur.first, y = cur.second;

        if(val[x][y] == 1 || val[x][y]==INF)
        {

            /** Since we already push all val == 1 we don't have to check the four square around it anymore.
            it's guarantee that it must be the same. Otherwise, we would push into queue in the earlier stage.
            Also, if some of them is not assign yet, it does not affect since the value is INF. **/
            if(val[x][y]==INF)
            {
                val[x][y] = min(min(val[x-1][y],val[x+1][y]),min(val[x][y-1],val[x][y+1]))+1;
            }

            /** Normal BFS **/
            if(x!=0 && val[x-1][y]==INF)
                qu.push({x-1,y});
            if(x!=n-1 && val[x+1][y]==INF)
                qu.push({x+1,y});
            if(y!=0 && val[x][y-1]==INF)
                qu.push({x,y-1});
            if(y!=m-1 && val[x][y+1]==INF)
                qu.push({x,y+1});

        }
    }
    long long ans = 0;
    for(i=0; i<n; i++)
        for(j=0; j<m; j++)
            ans+=val[i][j];
    cout<<ans;
}