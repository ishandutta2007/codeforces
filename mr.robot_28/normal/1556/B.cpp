#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;
int funct(vector <int> a, int p){
    int n = sz(a);
    int ans = 0;
    int j1 = 0, j2 = 0;
    for(int i = 0; i < n; i++){
        while(j1 < n && a[j1] % 2 != p){
            j1++;
        }
        while(j2 < n && a[j2] % 2 != 1 - p){
            j2++;
        }
        if(i % 2 == 0){
            if(j1 > i){
                ans += j1 - i;
            }
            j1++;
        }
        else{
            if(j2 > i){
                ans += j2 - i;
            }
            j2++;
        }
    }
    return ans;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        int c1 = 0, c2 = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i] % 2 == 1){
                c1++;
            }
            else{
                c2++;
            }
        }
        if(c1 > c2 + 1 || c2 > c1 + 1){
            cout << -1 << "\n";
            continue;
        }
        if(c1 == c2 + 1){
            cout << funct(a, 1) << "\n";
        }
        else if(c2 == c1 + 1){
            cout << funct(a, 0) << "\n";
        }
        else{
            cout << min(funct(a, 0), funct(a, 1)) << "\n";
        }
    }
    return 0;
}