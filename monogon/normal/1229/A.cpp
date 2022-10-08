
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

const int N = 7005;
int n;
ll a[N], b[N];
bool flag[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    rep(i, 0, n) {
        rep(j, 0, n) {
            if(j != i) {
                if(a[i] == a[j]) {
                    flag[i] = true;
                    break;
                }
            }
        }
        if(flag[i]) {
            rep(j, 0, n) {
                if((a[i] | a[j]) == a[i]) {
                    flag[j] = true;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 0, n) {
        if(flag[i]) ans += b[i];
    }
    cout << ans << '\n';
}