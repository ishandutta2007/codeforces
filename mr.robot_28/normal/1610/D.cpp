#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
#define int long long
#define ll long long
const ll mod = 1e9 + 7;
const ll mod2 = 1e9 + 7;




signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;        
    vector <int> pow1(n + 1);
    pow1[0] = 1;
    for(int i = 1; i <= n; i++){
        pow1[i] = 1LL * 2 * pow1[i - 1] % mod;
    }
    vector <int> a(n);
    vector <int> c(40);
    for(int i = 0; i < n;i++){
        cin >> a[i];
        int it = 0;
        while(a[i] % 2 == 0){
            it++;
            a[i] /= 2;
        }
        c[it]++;
    }
    int ans = 1LL * (pow1[c[0]] - 1) * pow1[n - c[0]] % mod;
    int s = n - c[0];
    if(c[0] != n){
        for(int i = 1; i < 40; i++){
            if(c[i] == 0){
                continue;
            }
            int pw1 = 1LL * (pow1[c[i] - 1] - 1) * pow1[s - c[i]] % mod;
            ans = (ans + pw1) % mod;
            s -= c[i];
        }
    }
    cout << ans;
    return 0;
}