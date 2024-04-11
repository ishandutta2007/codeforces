#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int t, n, m, p[200200], c[200200];
queue<int> q;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&m);
        vector<int> v[n+1], ans;
        for(int i=1;i<=n;i++) p[i] = c[i] = 0;
        for(int i=1;i<=m;i++){
            int a, b; scanf("%d %d",&a,&b);
            v[a].push_back(b);
            p[b]++;
        }
        for(int i=1;i<=n;i++) if(!p[i]) q.push(i);

        while(!q.empty()){
            int u = q.front(); q.pop();

            if(c[u] == 2) ans.push_back(u);
            else for(auto x : v[u]) c[x] = max(c[x], c[u]+1);
            for(auto x : v[u]) if(--p[x] == 0) q.push(x);
        }

        printf("%d\n",ans.size());
        for(auto x : ans) printf("%d ",x);
        puts("");
    }
}