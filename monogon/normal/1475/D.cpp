
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    ll m;
    cin >> n >> m;
    vector<ll> code(n), forces(n), is, dead;
    rep(i, 0, n) cin >> code[i];
    rep(i, 0, n) cin >> forces[i];
    rep(i, 0, n) {
        (forces[i] == 1 ? is : dead).push_back(code[i]); 
    }
    sort(all(is), greater<>());
    sort(all(dead), greater<>());
    int best = INT_MAX;
    ll sum = 0;
    int j = sz(is);
    for(ll x : is) sum += x;
    rep(i, 0, 1 + sz(dead)) {
        while(j > 0 && sum - is[j - 1] >= m) {
            j--;
            sum -= is[j];
        }
        if(sum >= m) {
            best = min(best, 2 * i + j);
        }
        if(i < sz(dead)) sum += dead[i];
    }
    cout << (best == INT_MAX ? -1 : best) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}