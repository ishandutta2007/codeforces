
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

// we can delete any a[i] > m
// for each possible LCM from 1 to m, we should count number of divisors
// for each element x from 1 to m, add cnt[x] to all multiples

const int N = 1e6 + 5;
int n, m;
ll a[N], b[N], cnt[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> a[i];
        if(a[i] <= m) {
            cnt[a[i]]++;
        }
    }
    rep(i, 1, m + 1) {
        for(int x = i; x <= m; x += i) {
            b[x] += cnt[i];
        }
    }
    int mx = 1;
    rep(l, 1, m + 1) {
        if(b[l] > b[mx]) mx = l;
    }
    cout << mx << ' ' << b[mx] << '\n';
    rep(i, 0, n) {
        if(mx % a[i] == 0) {
            cout << i + 1 << ' ';
        }
    }
    cout << '\n';
}