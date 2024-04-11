
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

const int N = 1e5 + 5;
int n;
ll k, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k;
    if(k == 1) {
        cout << 1LL * (n + 1) * n / 2 << '\n';
        return 0;
    }
    map<int, int> ma;
    for(ll i = 2; i * i <= k; i++) {
        if(k % i == 0) {
            int cnt = 0;
            while(k % i == 0) {
                k /= i;
                cnt++;
            }
            ma[i] = cnt;
        }
    }
    if(k > 1) {
        ma[k] = 1;
    }
    rep(i, 0, n) cin >> a[i];
    int num = 0;
    map<int, int> ma2;
    ll ans = 0;
    int j = 0;
    rep(i, 0, n) {
        while(j < n && num < sz(ma)) {
            int x = a[j];
            for(auto &p : ma) {
                int cnt = 0;
                while(x % p.first == 0) {
                    x /= p.first;
                    cnt++;
                }
                if(ma2[p.first] < p.second && ma2[p.first] + cnt >= p.second) num++;
                ma2[p.first] += cnt;
            }
            j++;
        }
        int x = a[i];
        if(num >= sz(ma)) ans += n - j + 1;
        for(auto &p : ma) {
            int cnt = 0;
            while(x % p.first == 0) {
                x /= p.first;
                cnt++;
            }
            if(ma2[p.first] >= p.second && ma2[p.first] - cnt < p.second) num--;
            ma2[p.first] -= cnt;
        }
    }
    cout << ans << '\n';
}