#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
void solve(){
    int n;
    cin >> n;
    vector<ll> b(n);
    for(ll& x : b){
        cin >> x;
    }
    ll bsum = 0;
    for(ll x : b) bsum += x;
    ll contrib = ll(n) * ll(n+1) / 2;
    ll asum = bsum / contrib;
    if(asum * contrib != bsum){
        cout << "NO" << '\n';
        return;
    }
    vector<ll> a_guess(n);
    for(ll x = 0; x < n; x++){
        ll n_times = -(b[x] - b[(x-1+n)%n] - asum);
        if(n_times % n != 0){
            cout << "NO" << '\n';
            return;
        }
        a_guess[x] = n_times / n;
        if(a_guess[x] <= 0 || a_guess[x] > ll(1e9)){
            cout << "NO" << '\n';
            return;
        }
    }
    ll a_guess_sum = 0;
    for(ll x : a_guess) a_guess_sum += x;
    if(a_guess_sum == asum){
        cout << "YES" << '\n';
        for(ll x : a_guess){
            cout << x << ' ';
        }
        cout << '\n';
    } else {
        cout << "NO" << '\n';
        return;
    }
}

int main(){
    cin.tie(nullptr); cin.sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--) solve();
}