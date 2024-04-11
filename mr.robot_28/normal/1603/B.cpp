#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long

using namespace std;

const int N = 3e5 + 100;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c;
    cin >> c;
    while(c--){
        int x, y;
        cin >> x >> y;
        if(x > y){
            int n = (x + 1) * y;
            cout << (x + 1) * y << "\n"; 
        }
        else{
            x = (y / x) * x;
            cout << (x + y) / 2 << "\n";
        }
    }
    return 0;
}