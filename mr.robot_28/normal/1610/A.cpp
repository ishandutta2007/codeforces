#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
#define ll long long
const ll mod1 = 998244353;
const ll mod2 = 1e9 + 7;


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        if(max(n, m) == 1){
            cout << 0 << "\n";
        }
        else if(min(n, m) == 1){
            cout << 1 << "\n";
        }
        else{
            cout << 2 << "\n";
        }
    }
    return 0;
}