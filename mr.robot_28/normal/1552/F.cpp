#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;
const int N =  3e5;
const int M =  2e5;
const int mod = 998244353;
int pref[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector <int> x(n), y(n), s(n);
    for(int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i] >> s[i];
    }
    int ans = (x[n - 1] + 1) % mod;
    pref[0] = 0;
    for(int i = 0; i < n; i++)
    {
        int val =  (x[i] - y[i]) % mod;
        int j = lower_bound(x.begin(), x.end(), y[i]) - x.begin();
        val = (val + pref[i] - pref[j] + mod) % mod;
        pref[i + 1] = (pref[i] + val) % mod;
     //   cout << val << " ";
        if(s[i] == 1)
        {
            ans = (ans + val) % mod;
        } 
    }
    cout << ans  % mod<< "\n";
    return 0;
}