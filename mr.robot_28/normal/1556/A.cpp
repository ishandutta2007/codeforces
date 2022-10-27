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
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if((a + b) % 2 != 0){
            cout << -1 << "\n";
        }
        else if(a == 0 && b == 0){
            cout << 0 << "\n";
        }
        else if(a == b){
            cout << 1 << "\n";
        }
        else{
            cout << 2 << "\n";
        }
    }
    return 0;
}