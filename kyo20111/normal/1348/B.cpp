#include<bits/stdc++.h>
using namespace std;
using ll = long long;
ll t, n, k, a[111], chk[10101];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i=1;i<=n;i++) cin >> a[i];
        for(int i=1;i<=100;i++) chk[i] = 0;

        int fl = 0;
        vector<int> v;
        for(int i=1;i<=n;i++){
            if(!chk[a[i]]){
                chk[a[i]] = 1;
                fl++;
                v.push_back(a[i]);
            }
        }

        if(fl > k){
            cout << -1 << '\n';
            continue;
        }
        for(int i=1;i<=n;i++){
            if(v.size() == k) break;
            if(!chk[i]) v.push_back(i);
        }
        sort(v.begin(), v.end());

        cout << n * v.size() << '\n';
        for(int i=1;i<=n;i++){
            for(int x : v) cout << x << ' ';
        }
        cout << '\n';
    }
}