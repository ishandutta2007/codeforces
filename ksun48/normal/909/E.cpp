#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int deg[110000];
vector<int> dep[110000];
int which[110000];
vector<int> q[2];
int cur[2];


int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> which[i];
        deg[i] = 0;
    }
    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        dep[a].push_back(b);
        deg[b]++;
    }
    cur[0] = cur[1] = 0;
    for(int j = 0; j < n; j++){
        if(deg[j] == 0){
            q[which[j]].push_back(j);
        }
    }
    int ans = 0;
    while(1){
        if(cur[0] == q[0].size() && cur[1] == q[1].size()) break;
        for(int i = 0; i < 2; i++){
            int done = 0;
            while(cur[i] < q[i].size()){
                done = 1;
                int a = q[i][cur[i]];
                cur[i]++;
                for(int j = 0; j < dep[a].size(); j++){
                    int v = dep[a][j];
                    deg[v]--;
                    if(deg[v] == 0){
                        q[which[v]].push_back(v);
                    }
                }
            }
            if(i == 1 && done != 0) ans++;
        }
    }
    cout << ans << endl;
}