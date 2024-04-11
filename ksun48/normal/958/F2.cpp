#include<bits/stdc++.h>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> pos[m];
    int want[m];
    int all = m;
    for(int i = 0; i<n; i++){
        int x;
        cin >> x;
        x--;
        pos[x].push_back(i);
    }
    int su = 0;
    for(int i = 0; i<m; i++){
        int x;
        cin >> x;
        want[i] = x;
        if(x==0){
            all--;
        }
        su += x;
    }
    for(int i = 0; i<m; i++){
        if(want[i]>pos[i].size()){
            cout << -1 << endl;
            return 0;
        }
    }
    vector<int> st[n];
    vector<int> en[n];
    int ans = n;
    for(int i = 0; i<m; i++){
        for(int j = 0; j+want[i]-1<pos[i].size(); j++){
            int l = 0;
            int r = pos[i][j+want[i]-1];
            if(j>0){
                l = pos[i][j-1]+1;
            }
            st[l].push_back(r);
            en[pos[i][j]].push_back(r);
        }
    }
    multiset<int> ss;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<st[i].size(); j++){
            ss.insert(st[i][j]);
        }
        if(ss.size()==all){
            ans = min(ans,(*ss.rbegin())-i+1-su);
        }
        for(int j = 0; j<en[i].size(); j++){
            ss.erase(ss.find(en[i][j]));
        }
    }
    cout << ans << endl;
    return 0;
}