
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

const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vi cnt(N, 0);
    rep(i, 0, n) {
        int a;
        cin >> a;
        cnt[a]++;
    }
    int best = 0;
    for(int i = N - 1; i > 0; i--) {
        int c = cnt[i];
        for(int p = 2 * i; p < N; p += i) {
            cnt[i] = max(cnt[i], c + cnt[p]);
        }
        best = max(best, cnt[i]);
    }
    cout << n - best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}