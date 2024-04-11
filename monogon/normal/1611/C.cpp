
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
    vi a(n);
    rep(i, 0, n) cin >> a[i];
    int l = 0, r = n - 1;
    if(a[0] == n) {
        l++;
    }else if(a[n - 1] == n) {
        r--;
    }else {
        cout << -1 << '\n';
        return;
    }
    deque<int> D;
    D.push_back(n);
    while(l <= r) {
        if(a[l] > a[r]) {
            D.push_front(a[l++]);
        }else {
            D.push_back(a[r--]);
        }
    }
    rep(i, 0, n) {
        cout << D[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}