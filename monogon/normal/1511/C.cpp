
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vi a(n), pos(51);
    rep(i, 0, n) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) {
        pos[a[i]] = i + 1;
    }
    rep(i, 0, q) {
        int t;
        cin >> t;
        cout << pos[t] + i << ' ';
        rep(j, 1, 51) if(pos[j] > pos[t]) pos[j]--;
        pos[t] = -i;
    }
    cout << '\n';
}