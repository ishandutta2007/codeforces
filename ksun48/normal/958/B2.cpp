#include<bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
int sub[100000];
int n;
multiset<int> ss;
pair<int, int> dfs(int now, int from){
    pair<int, int> ret = make_pair(0,now);
    for(int i = 0; i<adj[now].size(); i++){
        int to = adj[now][i];
        if(to!=from){
            ret = max(ret,dfs(to,now));
        }
    }
    ret.first++;
    return ret;
}
void go(int now, int from){
    int bel = 0;
    int maxim = 0;
    for(int i = 0; i<adj[now].size(); i++){
        if(adj[now][i]!=from){
            go(adj[now][i],now);
            bel++;
            maxim = max(maxim,sub[adj[now][i]]);
        }
    }
    if(bel==0){
        sub[now] = 1;
        ss.insert(1);
        return;
    }
    if(from==-1){
        int ans = 1;
        for(int i = 2; i<=n; i++){
            if(ss.size()==0){
                cout << " " << ans;
                continue;
            }
            ans += *ss.rbegin();
            ss.erase(ss.find(*ss.rbegin()));
            cout << " " << ans;
        }
    }
    else{
        sub[now] = maxim+1;
        ss.erase(ss.find(maxim));
        ss.insert(maxim+1);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    cout << 1;
    cin >> n ;
    for(int i = 1; i<n; i++){
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    go(dfs(dfs(0,-1).second,-1).second,-1);
    cout << endl;
    return 0;
}