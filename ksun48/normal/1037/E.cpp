#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<pair<int,int> > friends(m);
    vector<vector<pair<int,int> > > edges(n);
    for(int i = 0; i < m; i++){
        cin >> friends[i].first >> friends[i].second;
        friends[i].first--;
        friends[i].second--;
        edges[friends[i].first].push_back({friends[i].second, i});
        edges[friends[i].second].push_back({friends[i].first, i});
    }
    vector<int> deg(n, 0);
    for(int j = 0; j < m; j++){
        deg[friends[j].first]++;
        deg[friends[j].second]++;
    }
    vector<int> kill;
    vector<int> dead(n, 0);
    vector<int> vis(n, 0);
    int numdead = 0;
    int s = 0;
    for(int j = 0; j < n; j++){
        if(deg[j] < k){
            kill.push_back(j);
            vis[j] = 1;
        }
    }
    vector<int> answers(m, 0);
    for(int j = m-1; j >= 0; j--){
        while(s < kill.size()){
            int a = kill[s];
            s++;
            dead[a] = 1;
            numdead++;
            for(pair<int,int> x : edges[a]){
                int b = x.first;
                int id = x.second;
                if(id > j) continue;
                if(dead[b]) continue;
                if(deg[a] == k && !vis[a]){
                    kill.push_back(a);
                    vis[a] = 1;
                }
                if(deg[b] == k && !vis[b]){
                    kill.push_back(b);
                    vis[b] = 1;
                }
                deg[a]--;
                deg[b]--;
            }
        }

        answers[j] = n - numdead;
        
        if(dead[friends[j].first] || dead[friends[j].second]) continue;
        if(deg[friends[j].first] == k && !vis[friends[j].first]){
            kill.push_back(friends[j].first);
            vis[friends[j].first] = 1;
        }
        if(deg[friends[j].second] == k){
            kill.push_back(friends[j].second);
            vis[friends[j].second] = 1;
        }
        deg[friends[j].first]--;
        deg[friends[j].second]--;
    }
    for(int i = 0; i < m; i++){
        cout << answers[i] << '\n';
    }
}