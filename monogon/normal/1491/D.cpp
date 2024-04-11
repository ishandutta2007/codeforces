
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

bool solve(ll u, ll v, int i) {
    if(u > v) return false;
    if(u == v) return true;
    else if(u == 0) return false;

    if(v >> i & 1) {
        v ^= (1LL << i);
        int j = i;
        while(j >= 0 && (~u >> j & 1)) {
            j--;
        }
        u ^= (1LL << j);
    }
    int j = i;
    while(u > v) {
        if(u >> j & 1) {
            u ^= (1LL << j);
        }
        j--;
    }
    return solve(u, v, i - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    while(q--) {
        ll u, v;
        cin >> u >> v;
        cout << (solve(u, v, 30) ? "YES" : "NO") << '\n';
    }
}