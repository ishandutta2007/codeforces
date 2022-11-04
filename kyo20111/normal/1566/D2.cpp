#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, a[90090], bx[90090], by[90090], c[303][303];

pair<int, int> f(int x){
    return {x/m, x%m};
}

void solve(){
    cin >> n >> m;
    for(int i=0;i<n*m;i++) cin >> a[i];

    vector<pair<int, int>> v;
    for(int i=0;i<n*m;i++) v.push_back({a[i], i});
    sort(v.begin(), v.end());

    for(int i=0;i<v.size();i++){
        int j = i;
        while(j+1 < v.size() && v[j+1].first == v[i].first) j++;

        auto [lx, ly] = f(i);
        auto [rx, ry] = f(j);

        if(lx == rx){
            for(int k=j;k>=i;k--) bx[v[k].second] = lx, by[v[k].second] = ly++;
        }else{

            int x = lx, y = m-1;
            for(int k=i;k<=j;k++){
                bx[v[k].second] = x, by[v[k].second] = y--;

                if(x == lx && y < ly) x++, y = m-1;
                else if(y < 0) x++, y = m-1;

                if(x == rx) y = min(y, ry);
            }
        }

        i = j;
    }

    for(int i=0;i<n;i++) for(int j=0;j<m;j++) c[i][j] = 0;

    int ans = 0;
    for(int k=0;k<n*m;k++){
        // cout << bx[k] << " " << by[k] << "\n";
        for(int j=0;j<by[k];j++) ans += c[bx[k]][j];
        c[bx[k]][by[k]] = 1;
    }

    cout << ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}