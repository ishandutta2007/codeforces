#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll a[500500], s[500500], cnt[101], sum[101], mod = 1e9 + 7;

void solve_tc(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i], s[i] = 0;
    for(int i=0;i<60;i++) cnt[i] = sum[i] = 0;

    for(int i=1;i<=n;i++) for(int b=0;b<60;b++) if(a[i] & (1ll << b)) cnt[b]++;
    for(int i=1;i<=n;i++) for(int b=0;b<60;b++){
        if(!(a[i] & (1ll << b))) (s[i] += ((1ll << b) % mod) * cnt[b]) %= mod;
        else (s[i] += ((1ll << b) % mod) * n) %= mod;
    }

    ll ans = 0;
    for(int i=1;i<=n;i++) for(int b=0;b<60;b++) if(a[i] & (1ll << b)) (sum[b] += s[i]) %= mod;

    for(int i=1;i<=n;i++){
        for(int b=0;b<60;b++) if(a[i] & (1ll << b)){
            (ans += ((1ll << b) % mod) * sum[b]) %= mod;
        }
    }
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);

    int tc = 1;
    cin >> tc;

    while(tc--){
        solve_tc();
        cout << "\n";
    }
}