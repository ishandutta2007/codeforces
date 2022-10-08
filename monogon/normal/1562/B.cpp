
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

void solve() {
    int k;
    cin >> k;
    string s;
    cin >> s;
    int best = 100;
    const int N = 100;
    vector<bool> prime(N, true);
    prime[1] = false;
    rep(i, 2, N) {
        if(prime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                prime[j] = false;
            }
        }
    }
    rep(i, 0, k) {
        int d = s[i] - '0';
        if(!prime[d]) best = min(best, d);
        rep(j, i + 1, k) {
            int num = d * 10 + (s[j] - '0');
            if(!prime[num]) best = min(best, num);
        }
    }
    cout << (best < 10 ? 1 : 2) << '\n';
    cout << best << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}