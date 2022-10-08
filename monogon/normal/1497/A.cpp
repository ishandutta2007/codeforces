
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
    cin >> n;
    vector<bool> seen(101, false);
    vi ve;
    rep(i, 0, n) {
        int a;
        cin >> a;
        if(!seen[a]) {
            seen[a] = true;
        }else {
            ve.push_back(a);
        }
    }
    rep(i, 0, 101) {
        if(seen[i]) cout << i << ' ';
    }
    for(int x : ve) cout << x << ' ';
    cout << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}