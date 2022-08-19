#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 250000;
LL solve(vector<pair<int,int> > v){
    vector<int> pts[MAXN];
    pair<int,int> up[MAXN];
    pair<int,int> down[MAXN];
    for(int i = 0; i < MAXN; i++){
        up[i] = make_pair(1234567, -1234567);
        down[i] = make_pair(1234567, -1234567);
    }
    for(pair<int,int> a : v){
        int b = a.first;
        int c = a.second;
        up[b].first = min(c, up[b].first);
        up[b].second = max(c, up[b].second);
        down[b].first = min(c, down[b].first);
        down[b].second = max(c, down[b].second);
    }
    for(int i = 1; i < MAXN; i++){
        up[i].first =  min(up[i-1].first, up[i].first);
        up[i].second = max(up[i-1].second, up[i].second);
    }
    for(int i = MAXN - 2; i > 0; i--){
        down[i].first =  min(down[i+1].first, down[i].first);
        down[i].second = max(down[i+1].second, down[i].second);
    }

    LL ans = 0;
    for(int i = 0; i + 1 < MAXN; i++){
        int minv = max(up[i].first, down[i+1].first);
        int maxv = min(up[i].second, down[i+1].second);
        if(minv >= maxv) continue;
        ans += (LL)(maxv - minv);
    }
    return ans;
}

int main(){
    cin.sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int> > g[2];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        int par = 0;
        if(((a + b) % 2) != 0){
            par = 1;
            b--;
        }
        int c = (a+b)/2;
        int d = (a-b)/2;
        g[par].push_back(make_pair(c + 110000, d + 110000));
    }
    LL ans = solve(g[0]) + solve(g[1]);
    cout << ans << endl;
}