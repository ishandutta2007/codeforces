#include <bits/stdc++.h>
using namespace std;
typedef long long LL;


int main(){
    int n;
    cin >> n;
    vector<vector<int> > edges(n);
    vector<pair<int,int> > e(n-1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        a--; b--;
        e[i] = {a,b};
    }
    vector<int> invperm(n);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        a--;
        invperm[a] = i;
    }
    for(int i = 0; i < n-1; i++){
        int a = invperm[e[i].first];
        int b = invperm[e[i].second];
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    if(invperm[0] != 0){
        cout << "No" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        sort(edges[i].begin(), edges[i].end());
    }
    vector<int> vis(n, 0);
    vector<int> bfs;
    bfs.push_back(0);
    int s = 0;
    vector<int> order;
    while(s < bfs.size()){
        int a = bfs[s];
        order.push_back(a);
        s++;
        vis[a] = 1;
        for(int x : edges[a]){
            if(vis[x]) continue;
            bfs.push_back(x);
        }
    }
    int ok = 1;
    for(int i = 0; i < n; i++){
        if(order[i] != i) ok = 0;
    }
    if(ok){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}