#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, p[111], r[111], ans[111]; // p[i] = p_i +1   index  

int a[111];

int query(vector<int> &v){
    cout << "?";
    for(auto x : v) cout << " " << x;
    cout << "\n";
    cout.flush();
    
    int re; cin >> re;
    return re;
}


// int query(vector<int> v){
//     for(int i=1;i<=n;i++) v[i-1] += a[i];

//     map<int, int> mp;

//     for(int i=0;i<n;i++){
//         if(mp.count(v[i])) return mp[v[i]];
//         mp[v[i]] = i+1;
//     }
//     return 0;
// }

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    // for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=n;i>=1;i--){
        {
            vector<int> v;
            for(int j=1;j<=n;j++) v.push_back(i == j ? 2 : 1);
            int re = query(v);
            // cout << re << "\n";
            if(re && re != i) p[i] = re, r[re] = i;
        }

        {
            vector<int> v;
            for(int j=1;j<=n;j++) v.push_back(i == j ? 1 : 2);
            int re = query(v);
            // cout << " " << re << "\n";
            if(re && re != i) r[i] = re, p[re] = i;
        }
    }

    // for(int i=1;i<=n;i++) cout << p[i] << " ";
    // cout << "\n";
    // for(int i=1;i<=n;i++) cout << r[i] << " ";
    // cout << "\n";

    for(int i=1;i<=n;i++) if(p[i] == 0) r[0] = i;

    int u = 0;
    for(int i=1;i<=n;i++){
        u = r[u];
        ans[u] = n-i+1;
    }

    cout << "!";
    for(int i=1;i<=n;i++) cout << " " << ans[i];
    cout << "\n";
    
    cout.flush();
}