#include <bits/stdc++.h>
using namespace std;

long long a[100010][2],b[100010],dp[100010][2],c[1000010],d[100010];
vector <int> v[100010],u[100010];

void dfs(int i) {
    c[i]=1;
    for(int j=0;j<b[i];j++) {
        if (c[v[i][j]]==0) {
            dfs(v[i][j]);
            if (abs(a[i][0]-a[v[i][j]][0])+dp[v[i][j]][0]<abs(a[i][0]-a[v[i][j]][1])+dp[v[i][j]][1]) dp[i][0]+=abs(a[i][0]-a[v[i][j]][1])+dp[v[i][j]][1];
            else dp[i][0]+=abs(a[i][0]-a[v[i][j]][0])+dp[v[i][j]][0];
            if (abs(a[i][1]-a[v[i][j]][0])+dp[v[i][j]][0]<abs(a[i][1]-a[v[i][j]][1])+dp[v[i][j]][1]) dp[i][1]+=abs(a[i][1]-a[v[i][j]][1])+dp[v[i][j]][1];
            else dp[i][1]+=abs(a[i][1]-a[v[i][j]][0])+dp[v[i][j]][0];
        }
    }
    c[i]=0;
}

int main(){
    std::ios::sync_with_stdio(false);
    long long i,j,k,l,m,n,t;
    int stack[100010];
    map <int,int> p;
    queue <int> q;
    cin>>t;
    memset(c,0,sizeof(c));
    for(i=0;i<t;i++) {
        cin>>n;
        for(j=1;j<=n;j++) {
            cin>>a[j][0];
            cin>>a[j][1];
            b[j]=0;
            dp[j][0]=dp[j][1]=0;
            d[j]=0;
        }
        for(j=1;j<n;j++) {
            cin>>k>>l;
            v[k].push_back(l);
            v[l].push_back(k);
            b[k]++;
            b[l]++;
        }
        dfs(1);

        if (dp[1][1]<dp[1][0]) cout<<dp[1][0]<<endl;
        else cout<<dp[1][1]<<endl;
        for(j=1;j<=n;j++) {
            v[j].clear();
            c[j]=0;
        }
    }
    return 0;
}