
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
int n;
ll a[N];
int cnt[20];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        rep(l, 0, 20) {
            if((a[i] >> l) & 1) {
                cnt[l]++;
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n) {
        a[i] = 0;
        rep(l, 0, 20) {
            if(cnt[l] > 0) {
                cnt[l]--;
                a[i] += (1LL << l);
            }
        }
        ans += a[i] * a[i];
    }
    cout << ans << '\n';
}