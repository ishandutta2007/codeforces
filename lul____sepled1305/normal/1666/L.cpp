//
// Created by 54173 on 4/17/2022.
//
#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2e5+10;
vector<int> G[N];
int p[N];
int dp[N];
vector<pii> e;

void bfs(int nd) {
    queue<int> qu;
    dp[nd] = -1;
    int ct = 1;
    for(auto it: G[nd]) {
        dp[it] = ct++;
        p[it] = nd;
        qu.push(it);
    }
    while(!qu.empty()) {
        nd = qu.front();
        qu.pop();
        for(auto it: G[nd]) {
            if(dp[it] == 0) {
                dp[it] = dp[nd];
                p[it] = nd;
                qu.push(it);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i=0;i<N;i++) p[i] = -1;
    int n,m,s; cin>>n>>m>>s; s--;
    for(int i=0;i<m;i++) {
        int a,b; cin>>a>>b; a--,b--;
        G[a].push_back(b);
        e.push_back({a,b});
    }
    bfs(s);
    bool found = false;
    for(auto it: e) {
        if(it.second == s || it.first == s) continue;
        if(dp[it.first] == 0 || dp[it.second] == 0 || dp[it.first] == dp[it.second]) continue;
        found = true;
        cout<<"Possible\n";
        vector<int> v1, v2;
        int runner = it.second;
        while(runner != s) {
            v1.push_back(runner);
            runner = p[runner];
        }
        runner = it.first;
        while(runner != s) {
            v2.push_back(runner);
            runner = p[runner];
        }
        cout<<v1.size()+1<<'\n'<<s+1<<' ';
        while(!v1.empty()) {
            cout<<v1.back()+1<<' ';
            v1.pop_back();
        }
        cout<<'\n';
        cout<<v2.size()+2<<'\n'<<s+1<<' ';
        while(!v2.empty()) {
            cout<<v2.back()+1<<' ';
            v2.pop_back();
        }
        cout<<it.second+1<<'\n';
        break;
    }
    if(!found) {
        cout<<"Impossible";
    }
    return 0;
}