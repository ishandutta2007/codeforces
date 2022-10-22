#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

constexpr int M = 200 * 100 + 1;
bool is_prime[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 2; i < M; i++) is_prime[i] = true;
    for(int i = 2; i < M; i++) {
        if (!is_prime[i]) continue;
        for(int j = i + i; j < M; j += i) is_prime[j] = false;
    }
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        int s = accumulate(all(a), 0);
        if (!is_prime[s]) {
            cout << n << '\n';
            rep(i, n) cout << i + 1 << " \n"[i + 1 == n];
            continue;
        }
        rep(i, n) if (a[i] % 2) {
            cout << n - 1 << '\n';
            rep(j, n) if (j != i) cout << j + 1 << ' ';
            cout << '\n';
            break;
        }
    }
}