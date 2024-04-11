#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long

using namespace std;

const int N = 5e5 + 100;
const int T = 350;
const int mod = 998244353;
int fact[N], ifact[N];

int cnk(int n, int k){
    return 1LL * fact[n] * ifact[n - k] % mod * ifact[k] % mod;
}
int n, m;
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
pair <int, int> a[N];

int fenv[N];
void up(int x, int val){
    while(x < N){
        fenv[x] += val;
        x = x | (x + 1);
    }
}
int get(int x){
    int res = 0;
    while(x >= 0){
        res += fenv[x];
        x = (x & (x + 1)) - 1;
    }
    return res;
}
int pos[N];
void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i].X >> a[i].Y;
    }
    sort(a, a + m);
    int mag = m + 1;
    vector <pair <int, int> > t;
    vector <int> cl;
    for(int i = m - 1; i >= 0; i--){
        int need = a[i].Y;
        int vl = 0, vr = 4e5 + 7;
        while(vr - vl > 1){
            int vm = (vl + vr) / 2;
            if(vm - get(vm) < need){
                vl = vm;
            }
            else{
                vr = vm;
            }
        }
        pos[i] = vr;
        up(vr, 1);
        cl.push_back(vr);
        t.push_back(make_pair(pos[i], i));
    }
    for(auto x : cl){
        up(x, -1);
    }
    sort(t.begin(), t.end());
    for(int i = 0; i + 1 < sz(t); i++){
        if(t[i].X == t[i + 1].X - 1 && t[i].Y < t[i + 1].Y){
            mag--;
        }
    }
    cout << cnk(n  + (n - mag), n - mag) << "\n";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    fact[0] = 1;
    for(int i = 1; i < N; i++){
        fact[i] = 1LL * fact[i - 1] * i % mod;
    }
    ifact[N - 1] = power(fact[N - 1], mod - 2);
    for(int i = N - 2; i >= 0; i--){
        ifact[i] = 1LL * ifact[i + 1] * (i + 1) % mod;
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}