#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int color = 1;
    int cur = k;
    while(cur < n){
        color++;
        cur *= k;
    }
    cout << color << "\n";
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            int color1 = 1;
            int cur1 = k;
            while(i / cur1 != j / cur1){
                color1++;
                cur1 *= k;
            }
            cout << color1 << " ";
        }
    }
    return 0;
}