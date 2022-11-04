#include<bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> v[100100];
int sz[100100], cnt, chk[100100];
int n, ans[100100];
queue<int> q;

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int a, b; scanf("%d %d",&a,&b);
        sz[a]++, sz[b]++;
        v[a].push_back({b, i});
        v[b].push_back({a, i});
    }

    for(int i=1;i<=n;i++) if(sz[i] == 1) q.push(i);

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(auto x : v[u]){
            if(!chk[x.second]){
                sz[x.first]--;
                ans[x.second] = ++cnt;
                chk[x.second] = 1;
                if(sz[x.first] == 1) q.push(x.first);
            }
        }
    }

    for(int i=1;i<n;i++) printf("%d\n",ans[i]-1);
}