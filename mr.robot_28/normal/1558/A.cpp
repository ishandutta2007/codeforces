#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

const int N = 1e5 + 100;
const int T = 350;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        int t1 = (a + b + 1) / 2;
        int t2 = (a + b) / 2;
        vector <int> ans;
        for(int k = 0; k <= a + b; k++)
        {
            if(t1 >= (t1 - a + k) / 2 && t2 >= (k - (t1 - a + k) / 2) && t1 - a + k >= 0 && (t1 - a + k) % 2 == 0 && k - (t1 - a + k) / 2 >= 0 && t2 - (k - (t1 - a + k) / 2) + (t1 - a + k) / 2  == b){
                ans.push_back(k);
            }
            else if(a - t2 + k >= 0 && (a - t2 + k) % 2 == 0 && t2 >= k - (a - t2 + k) / 2 && t1 >= (a - t2 + k) / 2 && k - (a - t2 + k) / 2 >= 0 && t1 - (a - t2 + k) / 2 + k - (a - t2 + k) / 2 == b){
               // cout << k << " ";
      //          cout << (t2 - a + k) /2 << " " << k - (t2 - a + k) /2  << "\n";
                ans.push_back(k);
            }
        }
        cout << sz(ans) << "\n";
        for(auto v : ans){
            cout << v << " ";
        }
        cout << "\n";
    }
    return 0;
}