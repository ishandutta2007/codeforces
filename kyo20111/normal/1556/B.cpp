#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100100];

void solve(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];

    vector<int> v[2];
    for(int i=1;i<=n;i++) v[a[i]%2].push_back(i);

    if(abs(int(v[0].size()) - int(v[1].size())) > 1){
        cout << -1;
        return;
    }

    if(v[0].size() > v[1].size()) swap(v[0], v[1]);

    if(v[0].size() < v[1].size()){
        int ans = 0;
        for(int i=0;i<v[1].size();i++){
            ans += abs(v[1][i] - (i*2+1));
        }
        cout << ans;
        return;
    }

    int ans1 = 0, ans2 = 0;
    for(int i=0;i<v[1].size();i++){
        ans1 += abs(v[0][i] - (i*2+1));
        ans2 += abs(v[1][i] - (i*2+1));
    }
    cout << min(ans1, ans2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int tc = 1; cin >> tc;
    while(tc--) solve(), cout << "\n";
}