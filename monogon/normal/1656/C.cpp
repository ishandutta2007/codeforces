
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
    vector<ll> a(n);
    bool one = false, zero = false;
    rep(i, 0, n) {
        cin >> a[i];
        one |= (a[i] == 1);
        zero |= (a[i] == 0);
    }
    if(!one) {
        cout << "YES\n";
        return;
    }
    sort(all(a));
    rep(i, 1, n) {
        if(a[i - 1] + 1 == a[i]) {
            cout << "NO\n";
            return;
        }
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