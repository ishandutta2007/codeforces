#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int tc, n, a[300300], mn[300300], INF = 1e9;
vector<int> v[300300];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> tc;
    while(tc--){
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];

        for(int i=1;i<=n;i++) v[i].clear(), mn[i] = INF;

        for(int i=1;i<=n;i++) v[i].push_back(0);
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        for(int i=1;i<=n;i++) v[i].push_back(n+1);

        for(int i=1;i<=n;i++){
            int c = 0;
            for(int j=0;j<v[i].size()-1;j++) c = max(c, v[i][j+1] - v[i][j]);
            mn[c] = min(mn[c], i);
        }

        for(int i=2;i<=n;i++) mn[i] = min(mn[i], mn[i-1]);

        for(int i=1;i<=n;i++){
            if(mn[i] == INF) cout << -1;
            else cout << mn[i];
            cout << " ";
        }
        cout << "\n";
    }
}