
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

// A[p[1]] <= x
// A[p[2]] <= x + 1
// A[p[i]] <= x + i - 1

const int N = 1e5 + 5;
int n, p;
ll a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> p;
    rep(i, 0, n) {
        cin >> a[i];
    }
    sort(a, a + n);
    ll low = 0, high = LLONG_MAX;
    rep(i, 0, n) {
        low = max(low, a[i] - i);
        if(i >= p - 1) {
            high = min(high, a[i] + p - i - 1);
        }
    }
    high = max(high, low);
    cout << high - low << '\n';
    for(ll x = low; x < high; x++) {
        cout << x << ' ';
    }
    cout << '\n';
}