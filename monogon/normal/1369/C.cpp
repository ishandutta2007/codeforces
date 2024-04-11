
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
int t, n, k;
ll a[N];
int w[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> k;
        rep(i, 0, n) {
            cin >> a[i];
        }
        sort(a, a + n);
        vi ve;
        ll ans = 0;
        rep(i, 0, k) {
            cin >> w[i];
            if(w[i] == 1) {
                ans += a[n - 1] * 2;
                n--;
            }else {
                ve.push_back(w[i]);
            }
        }
        sort(all(ve));
        k = sz(ve);
        rep(i, 0, k) {
            ans += a[n - 1];
            n--;
        }
        int j = n;
        rep(i, 0, k) {
            j -= ve[i] - 1;
            ans += a[j];
        }
        cout << ans << '\n';
    }
}