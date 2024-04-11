#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 1e3+10;
const int INF = 1e9;
int dp[N][N][3];
int arr[N][N];
char prv[N][N][3];
bool visit[N][N];
int n,i,j;
vector<char> ve;

int extract(int num, int p)
{
    int counti = 0;
    while(num%p==0)
        num/=p, counti++;
    return counti;
}

int main()
{
    scanf("%d",&n);
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]), dp[i][j][0]=INF, dp[i][j][1] = INF, dp[i][j][2]=INF, visit[i][j] = false;
    queue<pii> qu;
    qu.push({0,0});
    if(arr[0][0]!=0)
    {
        dp[0][0][0] = extract(arr[0][0],2);
        dp[0][0][1] = extract(arr[0][0],5);
    }
    else
    {
        dp[0][0][3] = 1;
    }
    while(!qu.empty())
    {
        pii node = qu.front();
        int u = node.first, v = node.second;
        qu.pop();
        if(arr[u][v]!=0)
        {
            int a = extract(arr[u][v],2), b = extract(arr[u][v],5);
            if(u>0)
            {
                if(dp[u][v][0] > a + dp[u-1][v][0])
                    dp[u][v][0] = dp[u-1][v][0]+a, prv[u][v][0] = 'U';
                if(dp[u][v][1] > b + dp[u-1][v][1])
                    dp[u][v][1] = dp[u-1][v][1]+b, prv[u][v][1] = 'U';

            }
            if(v>0)
            {
                if(dp[u][v][0] > a + dp[u][v-1][0])
                    dp[u][v][0] = dp[u][v-1][0]+a, prv[u][v][0] = 'L';
                if(dp[u][v][1] > b + dp[u][v-1][1])
                    dp[u][v][1] = dp[u][v-1][1]+b, prv[u][v][1] = 'L';
            }
            if(u>0 && dp[u-1][v][2]==1)
                dp[u][v][2] = 1, prv[u][v][2] = 'U';
            else if(v>0 && dp[u][v-1][2]==1)
                dp[u][v][2] = 1, prv[u][v][2] = 'L';
            else if(v>0)
                prv[u][v][2] = 'L';
            else if(u>0)
                prv[u][v][2] = 'U';
        }
        else
        {
            prv[u][v][2] = 'L';
            dp[u][v][2] = 1;
        }
        if(u<n-1 && !visit[u+1][v])
            qu.push({u+1,v}),visit[u+1][v] = true;
        if(v<n-1 && !visit[u][v+1])
            qu.push({u,v+1}), visit[u][v+1] = true;
    }
    int mini = min(dp[n-1][n-1][0],dp[n-1][n-1][1]);
    mini = min(mini,dp[n-1][n-1][2]);
    if(mini!=dp[n-1][n-1][2])
        printf("%d\n",min(dp[n-1][n-1][0],dp[n-1][n-1][1]));
    else
        printf("1\n");
    int des;
    if(mini == dp[n-1][n-1][0])
        des = 0;
    else if(mini == dp[n-1][n-1][1])
        des = 1;
    else
        des = 2;
    pii cur={n-1,n-1};
    pii fi = {0,0};
    while(cur != fi)
    {
        int a = cur.first, b = cur.second;
        if(a<0 || b<0)
        {
            cout<<"BUG\n"; break;
        }
        ve.push_back(prv[a][b][des]);
        if(prv[a][b][des]=='U')
            cur={a-1,b};
        else
            cur={a,b-1};
    }
    while(!ve.empty())
    {
        if(ve.back()=='U')
            printf("D");
        else
            printf("R");
        ve.pop_back();
    }
}