#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 1e5 + 100;
const int mod1 = 1e9 + 7;
const int mod2 = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string s;
        cin >> s;
        map <int, int> mp;
        mp[0] = 0;
        int bal = 0;
        bool fl = 0;
        for(int i = 0; i < sz(s); i++){
            bal += (s[i] == 'a' ? 1 : -1);
            if(mp.count(bal))
            {
                fl = 1;
                cout << mp[bal] + 1 << " " << i + 1 << "\n";
                break;
            }
            mp[bal] = i + 1;
        }
        if(!fl){
            cout << -1 << " " << -1 << "\n";
        }
    }
    return 0;
}