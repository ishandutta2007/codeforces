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
            a[i].Y = i;
        }
        sort(a.begin(), a.end());
        vector <vector <pair <int, int> > > res(n, vector <pair <int, int> > (m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                res[i][j] = a[i * m + j];
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                int j1 = j;
                while(j1 + 1 < m && res[i][j].X == res[i][j1 + 1].X){
                    j1++;
                }
                for(int k = 0; k < (j1 - j + 1) / 2; k++){
                    swap(res[i][k + j], res[i][j1 - k]);
                }
                j = j1;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                for(int j1 = j + 1; j1 < m; j1++){
                    if(res[i][j].Y < res[i][j1].Y){
                        ans++;
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}