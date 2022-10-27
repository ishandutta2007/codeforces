#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> c(n);
    for(int i = 0; i < n; i++){
        cin >> c[i];
    }
    int ans = 0;
    for(int i = 1; i < n; i += 2){
        int minbal = 0;
        int bal = 0;
        ans += min(c[i], c[i - 1]);
        for(int j = i; j + 2 < n; j += 2){
            bal -= c[j];
            minbal = min(minbal, bal);
            bal += c[j + 1];
            int c1 = -minbal;
            int c2 = c1 + bal;
            //cout << c[i - 1] - c1 << " " << c[j + 2] - c2 << "\n";
            if(c2 <= c[j + 2] && c1 <= c[i - 1]){
                ans += min(c[j + 2] - c2, c[i - 1] - c1) + 1;
            }
        }
     //   cout << ans << "\n";
    }
    cout << ans;
    return 0;
}