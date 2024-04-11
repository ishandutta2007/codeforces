
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

const int N = 2e6 + 5;
int n;
ll h[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll sum = 0;
    rep(i, 0, n) {
        cin >> h[i];
        sum += h[i];
    }
    rep(i, 0, n - 1) {
        ll x = (sum - (1LL * n - i - 1) * (n - i) / 2 + n - i - 1) / (n - i);
        ll dif = x - h[i];
        h[i] += dif;
        h[i + 1] -= dif;
        sum -= h[i];
        cout << h[i] << ' ';
    }
    cout << h[n - 1] << '\n';
}