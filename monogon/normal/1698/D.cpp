
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

int ask(int l, int r) {
    cout << "? " << l << ' ' << r << endl;
    int parity = 0;
    rep(i, 0, r - l + 1) {
        int x;
        cin >> x;
        assert(x != -1);
        parity += (x >= l && x <= r);
    }
    return parity;
}

void solve() {
    int n;
    cin >> n;
    assert(n != -1);
    int l = 1, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        int cnt = ask(l, m);
        if(cnt % 2 == 0) {
            l = m + 1;
        }else {
            r = m;
        }
    }
    cout << "! " << l << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}