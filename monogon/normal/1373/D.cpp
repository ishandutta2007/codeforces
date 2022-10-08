
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

const int N = 2e5 + 5;
int t, n;
ll a[N];

ll solve(vector<ll> &v) {
    ll best = 0;
    int k = sz(v);
    ll s = 0;
    rep(i, 0, k) {
        s += v[i];
        if(s < 0) s = 0;
        best = max(best, s);
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll sum = 0;
        vector<ll> ve, vo;
        rep(i, 0, n) {
            cin >> a[i];
            if(i % 2 == 0) {
                sum += a[i];
            }
            if(i > 0 && i % 2 == 0) {
                vo.push_back(a[i - 1] - a[i]);
            }else if(i > 0 && i % 2 == 1) {
                ve.push_back(a[i] - a[i - 1]);
            }
        }
        cout << (sum + max(solve(ve), solve(vo))) << '\n';
    }
}