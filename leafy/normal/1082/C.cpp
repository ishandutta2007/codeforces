#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=100005;
int s[N],r[N];int n,m;
vector<int> G[N];
priority_queue<int> q[N];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&s[i],&r[i]);
        G[s[i]].push_back(-r[i]);
    }
    for(int i=1;i<=m;i++){
        sort(G[i].begin(),G[i].end());
        if(G[i].size()){
            int s=0;
            for(int j=0;j<G[i].size();j++){
                s-=G[i][j];
                if(s>0) q[j+1].push(s);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int s=0;
        while(!q[i].empty()){
            s+=q[i].top();
            q[i].pop();
        }
        ans=max(ans,s);
    }
    printf("%d",ans);
    return 0;
}