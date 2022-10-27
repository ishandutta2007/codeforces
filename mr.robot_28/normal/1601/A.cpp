#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;

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
        vector <int> cnt(30);
        for(int i = 0; i < n; i++){
            cin >> a[i];
            for(int j = 0; j < 30; j++){
                if((1 << j) & a[i]){
                    cnt[j]++;
                }
            }
        }
        vector <int> coun(n + 1);
        for(int i = 0; i < 30; i++){
            for(int j = 1; j <= n; j++){
                if(cnt[i] % j == 0){
                    coun[j]++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            if(coun[i] == 30){
                cout << i << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}