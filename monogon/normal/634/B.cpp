
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

ll s, x;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> s >> x;
    if(x > s || (s - x) % 2 != 0) {
        cout << "0\n";
        return 0;
    }
    ll a = (s - x) / 2;
    if((x & a) != 0) {
        cout << "0\n";
        return 0;
    }
    int cnt = 0;
    rep(i, 0, 60) {
        cnt += ((x >> i) & 1);
    }
    ll ans = (1LL << cnt);
    if(s == x) {
        ans -= 2;
        ans = max(ans, 0LL);
    }
    cout << ans << '\n';
}