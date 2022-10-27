#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
int a[N];
int n, m;
bool funct1(int x, int y){
    int l = lower_bound(a, a + n, x) - a;
    if(l == n || a[l] > y){
        return 0;
    }
    return 1;
}
int nxt(int x, int y){
    int l = lower_bound(a, a + n, x) - a;
    if(l == n){
        return 1e10;
    }
    return a[l];
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        vector <pair <int, int> > lr(m);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        for(int i = 0; i < m; i++){
            cin >> lr[i].X >> lr[i].Y;
        }
        sort(a, a + n);
        sort(lr.begin(), lr.end());
        set <pair <int, int> > st;
        vector <bool> del(m);
        for(int i = 0; i < m; i++){
            while(sz(st) && st.rbegin() -> X >= lr[i].Y){
                del[st.rbegin() -> Y] = 1;
                st.erase(*st.rbegin());
            }
            st.insert({lr[i].Y, i});
        }
        vector <pair <int, int> > lr1;
        for(int i = 0; i < m; i++){
            if(!del[i] && !funct1(lr[i].X, lr[i].Y)){
                lr1.push_back(lr[i]);
            }
        }
        m = sz(lr1);
        lr = lr1;
        vector <vector <int> > dp(n + 1, vector <int> (4, 1e18));
        dp[0][0] = 0;
        int it = -1;
        for(int i = 0; i < n; i++){
            int it1 = it;
            while(it1 + 1 < m && lr[it1 + 1].X < a[i]){
                it1++;
            }
            int f = 0;
            if(it + 1 <= it1){
                f = a[i] - lr[it + 1].Y;
            }
            dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + f);
            dp[i + 1][1] = min(dp[i + 1][1], dp[i][0] + 2 * f - a[i]);
            dp[i + 1][2] = min(dp[i + 1][2], dp[i][0] + f - 2 * a[i]);
            for(int j = it + 1; j <= it1; j++){
                f =0;
                if(j + 1 <= it1){
                    f = a[i] - lr[j + 1].Y;
                }
                dp[i + 1][0] = min(dp[i + 1][0], lr[j].X + dp[i][1] + f);
                dp[i + 1][0] = min(dp[i + 1][0], dp[i][2] + 2 * lr[j].X + f);
                dp[i + 1][1] = min(dp[i + 1][1], lr[j].X + dp[i][1] + 2 * f - a[i]);
                dp[i + 1][1] = min(dp[i + 1][1], dp[i][2] + 2 * lr[j].X + 2 * f - a[i]);
                dp[i + 1][2] = min(dp[i + 1][2], lr[j].X + dp[i][1] + f - 2 * a[i]);
                dp[i + 1][2] = min(dp[i + 1][2], dp[i][2] + 2 * lr[j].X + f - 2 * a[i]);
            }
        //    cout << it << " " << it1 << "\n";
          //  cout << dp[i + 1][0] << " " << dp[i + 1][1] << " " << dp[i + 1][2] << "\n";
            it = it1;
        }
        if(it == m - 1){
            cout << min(dp[n][0], dp[n][1] + a[n - 1]) << "\n";
        }
        else{
            cout << min(dp[n][1] + lr[m - 1].X, dp[n][2] + 2 * lr[m - 1].X)  << "\n";
        }
    }
    return 0;
}