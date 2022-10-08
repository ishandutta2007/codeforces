
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
    ll n; int m;
    cin >> n >> m;
    map<ll, int> ma;
    rep(i, 0, m) {
        int r; ll c;
        cin >> r >> c;
        ma[c] |= (1 << (r - 1));
    }
    #define NO {cout << "NO\n"; return;}
    if(m % 2 == 1) NO;
    int mask = 3;
    ll idx = 0;
    for(auto &pa : ma) {
        if(pa.second == 1) {
            if(mask == 1 && idx % 2 == pa.first % 2) NO
            else if(mask == 2 && idx % 2 != pa.first % 2) NO
            else if(mask == 3) mask = pa.second;
            else mask = 3;
        }else if(pa.second == 2) {
            if(mask == 2 && idx % 2 == pa.first % 2) NO
            else if(mask == 1 && idx % 2 != pa.first % 2) NO
            else if(mask == 3) mask = pa.second;
            else mask = 3;
        }else if(pa.second == 3) {
            if(mask != 3) NO
        }
        idx = pa.first;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}