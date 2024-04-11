#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
    int n, m;
    cin >> n >> m;
    string g[n];
    for(int i = 0; i < n; i++){
        cin >> g[i];
    }
    string ins;
    cin >> ins;

    pair<int,int> st, en;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(g[i][j] == 'S'){
                g[i][j] = '.';
                st = {i,j};
            } else if(g[i][j] == 'E'){
                g[i][j] = '.';
                en = {i,j};
            }
        }
    }
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};
    vector<int> p = {0,1,2,3};
    int ans = 0;
    while(1){
        int ok = 0;
        pair<int,int> cur = st;
        for(int j = 0; j < ins.size(); j++){
            cur.first += dx[p[ins[j]-'0']];
            cur.second += dy[p[ins[j]-'0']];
            if(cur.first < 0 || cur.second < 0 || cur.first >= n || cur.second >= m) break;
            if(g[cur.first][cur.second] == '#') break;
            if(cur == en){
                ok = 1;
                break;
            }
        }
        ans += ok;
        if(!next_permutation(p.begin(), p.end())) break;
    }
    cout << ans << endl;
}