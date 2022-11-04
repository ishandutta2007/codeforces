#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n, m, a[200200], s[200200], e[200200], sz[200200], chk[200200], chk2[200200];
vector<pair<int,int>> v[200200];
queue<int> q;
stack<int> ans;
int main(){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++) scanf("%d",a+i);
    for(int i=1;i<=m;i++){
        scanf("%d %d",s+i,e+i);
        v[s[i]].push_back({i, e[i]});
        v[e[i]].push_back({i, s[i]});
    }

    for(int i=1;i<=n;i++){
        if(v[i].size() <= a[i]) q.push(i), chk[i] = 1;
    }

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto [x, y] : v[u]) if(!chk2[x]){
            chk2[x] = 1;
            ans.push(x);
            sz[y]++;
            if(v[y].size() - sz[y] <= a[y] && !chk[y]) q.push(y), chk[y] = 1;
        }
    }

    if(ans.size() == m){
        printf("ALIVE\n");
        while(!ans.empty()){
            int u = ans.top(); ans.pop();
            printf("%d ",u);
        }
    }else{
        printf("DEAD");
    }
}