#include<bits/stdc++.h>
#define X first
#define Y second
#define ll long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector <pair <int, int> > a(n * m);
        for(int i = 0; i < n * m; i++){
            cin >> a[i].X;
            a[i].Y = -i;
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for(int i = 0; i < n * m; i++){
            for(int j = i + 1; j < n * m; j++){
                if(a[i].Y > a[j].Y){
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}