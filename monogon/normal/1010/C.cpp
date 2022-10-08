
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
    int n, k;
    cin >> n >> k;
    int g = k;
    rep(i, 0, n) {
        int a;
        cin >> a;
        a %= k;
        g = gcd(g, a);
    }
    g %= k;
    vi ans = {0};
    int x = g;
    while(x != 0) {
        ans.push_back(x);
        x = (x + g) % k;
    }
    cout << sz(ans) << '\n';
    for(int x : ans) cout << x << ' ';
    cout << '\n';
}