#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
const lli SIZE = 6e5;
#define loop(x,n) for(lli x = 0; x < n; ++x)
vector<lli> adj[SIZE];

lli ans[SIZE] = {0}, visited[SIZE] = {0};
set<lli> ele;

lli dfs(lli v, lli val) { 
    ele.insert(v);
    visited[v] = 1; 
    val += 1;
    vector<lli>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
        if (!visited[*i])
            val = dfs(*i, val); 
    return val;
} 
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    lli n, m, k, inp;
    cin >> n >> m;
    lli root;
    while(m--){
        cin >> k;
        loop(i, k){
            cin >> inp;
            inp--;
            if(i==0)
                root = inp;
            else{
                adj[root].push_back(inp);
                adj[inp].push_back(root);
                root = inp;
            } 
        }
    }

    lli val;
    loop(i, n){
        val = 0;
        if(!visited[i]){
            val = dfs(i, 0);
            for(auto itr:ele){
                ans[itr] = val;
            }
            ele.clear();
        }
    }
    
    loop(i, n)
        cout << ans[i] << " ";
    return 0;
}