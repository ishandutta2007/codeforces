
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

const int N = 2e5 + 5;
int n, pr[N];
ll a[N];
vector<pii> vec;

void check(int idx) {
    rep(i, 1, n + 1) pr[i] = i - 1;
    pr[idx + 1] = idx - 1;
    set<int> s;
    rep(i, 1, n + 1) {
        if(i != idx && pr[i] > 0) {
            s.insert(a[pr[i]] - a[i]);
        }
    }
    if(sz(s) <= 1) {
        cout << vec[idx - 1].se << '\n';
        exit(0);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
        vec.emplace_back(a[i], i);
    }
    sort(vec.begin(), vec.end());
    rep(i, 1, n + 1) {
        a[i] = vec[i - 1].fi;
    }
    // check if we delete first, check if we delete second, otherwise difference is (max - min) / (n - 1)
    check(1);
    check(n);
    if((a[n] - a[1]) % (n - 2) != 0) {
        cout << "-1\n";
        return 0;
    }
    ll dif = (a[n] - a[1]) / (n - 2);
    rep(i, 1, n + 1) {
        if(a[i] != a[1] + dif * (i - 1)) {
            check(i);
            break;
        }
    }
    cout << "-1\n";
}