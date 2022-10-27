#include<bits/stdc++.h>
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
using namespace std;
const int N = 2e5 + 100;
const int mod1 = 1e9 + 7;
const int mod = 998244353;
int fact[N], ifact[N];
int power(int a, int b){
    if(b == 0){
        return 1;
    }
    if(b % 2 == 0){
        int t = power(a, b / 2);
        return 1LL * t * t % mod;
    }
    return 1LL * a * power(a, b - 1) % mod;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    ifact[N - 1] = power(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
    }
    while(t--){
        int n;
        cin >> n;
        vector <int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(a[n - 1] > a[n - 2] + 1){
            cout << 0 << "\n";
            continue;
        }
        if(a[n - 1] == a[n - 2]){
            cout << fact[n] << "\n";
            continue;
        }
        int c = 0;
        for(int i = 0; i < n; i++){
            if(a[i] == a[n - 2]){
                c++;
            }
        }
        cout << 1LL * fact[n] * ifact[c + 1] % mod * (fact[c + 1] - fact[c] + mod) % mod << "\n";
    }
    return 0;
}