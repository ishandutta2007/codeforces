
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 3e5 + 5;
int n, k;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    ll sum = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        sum += a[i];
    }
    reverse(a + 1, a + n + 1);
    rep(i, 1, n + 1) {
        a[i] += a[i - 1];
    }
    sort(a + 1, a + n, greater<>());
    ll ans = sum + accumulate(a + 1, a + k, 0LL);
    cout << ans << '\n';
}