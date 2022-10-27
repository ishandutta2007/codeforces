#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        vector <int> x(n);
        for(int i = 0; i < n; i++){
            cin >> x[i];
        }
        vector <int> y(m);
        for(int i = 0; i < m; i++)
        {
            cin >> y[i];
        }
        vector <vector <int> > vec1(n), vec2(m);
        for(int i = 0; i < k; i++)
        {
            int p, q;
            cin >> p >> q;
            int i1 = lower_bound(x.begin(), x.end(), p) - x.begin();
            int j1 = lower_bound(y.begin(), y.end(), q) - y.begin();
            if(x[i1] != p){
                vec1[i1].push_back(j1);
            }
            if(y[j1] != q){
                vec2[j1].push_back(i1);
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int j = 0;
            sort(vec1[i].begin(), vec1[i].end());
            for(int p = 0; p < sz(vec1[i]); p++){
                while(j < sz(vec1[i]) && vec1[i][j] < vec1[i][p]){
                    j++;
                }
                ans += j;
            }
        }
        for(int i = 0; i < m; i++){
            int j = 0;
            sort(vec2[i].begin(), vec2[i].end());
            for(int p = 0; p < sz(vec2[i]); p++){
                while(j < sz(vec2[i]) && vec2[i][j] < vec2[i][p]){
                    j++;
                }
                ans += j;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}