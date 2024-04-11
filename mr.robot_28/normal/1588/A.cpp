#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
#define int long long
const int N = 1e5 + 100;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n), b(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < n; i++){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ans = 1;
        for(int i = 0; i < n; i++){
            if(b[i] < a[i] || b[i] > a[i] + 1){
                ans = 0;
            }
        }
        if(ans){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }
    return 0;
}