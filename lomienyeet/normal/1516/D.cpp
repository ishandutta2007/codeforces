#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxN=1e5+5,lg=20;
int spf[mxN],st[lg][mxN];
vector<int> adj[mxN];
signed main(){
    int n,q;
    cin>>n>>q;
    int arr[n+1];
    for(int i=2;i<100005;i++){
        if(spf[i])continue;
        for(int j=i;j<100005;j+=i)spf[j]=i;
    }
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        while(arr[i]>1){
            int z=spf[arr[i]];
            while(!(arr[i]%z))arr[i]/=z;
            adj[z].push_back(i);
        }
    }
    for(int i=1;i<=n;i++)st[0][i]=n+1;
    for(int i=2;i<100005;i++){
        if(adj[i].empty())continue;
        int ptr=adj[i][0];
        for(int j=1;j<adj[i].size();j++){
            st[0][ptr]=min(st[0][ptr],adj[i][j]);
            ptr=adj[i][j];
        }
    }
    for(int i=n-1;i>0;i--)st[0][i]=min(st[0][i],st[0][i+1]);
    for(int i=1;i<lg;i++){
        st[i-1][n+1]=n+1;
        for(int j=1;j<=n;j++)st[i][j]=st[i-1][st[i-1][j]];
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        int z=1;
        for(int i=lg-1;i>=0;i--){
            if(st[i][l]<=r){
                z+=(1<<i);
                l=st[i][l];
            }
        }
        cout<<z<<"\n";
    }
}