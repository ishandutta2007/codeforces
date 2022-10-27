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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        int s = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
        }
        bool fl = 0;
        for(int j = 2; j * j <= s; j++){
            if(s % j == 0){
                fl = 1;
            }
        }
        if(fl){
            cout << n << "\n";
            for(int i = 0; i < n; i++){
                cout << i + 1 << " ";
            }
        }
        else{
            cout << n - 1 << "\n";
            for(int i = 0; i < n; i++){
                if(fl || a[i] % 2 == 0){
                    cout << i + 1 << " ";
                }
                else{
                    fl = 1;
                }
            }
        }
        cout << "\n";
    }
    return 0;
}