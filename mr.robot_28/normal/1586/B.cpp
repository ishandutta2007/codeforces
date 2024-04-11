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
        int n, m; 
        cin >> n >> m;
        vector <int> cnt(n);
        for(int i = 0; i < m; i++){
            int a, b, c;
            cin >> a >> b >> c;
            cnt[b - 1]++;
        }
        for(int i = 0; i < n; i++){
            if(cnt[i] == 0){
                for(int j = 0; j < n; j++){
                    if(j != i){
                        cout << j + 1 << " " << i + 1 << "\n";
                    }
                }
                break;
            }
        }
    }
    return 0;
}