
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

// n! permutations total
// subtract increasing then decreasing permutations
// position of n is i
// (i - 1) elements before it
// (n - i) elements after it
// (n - 1 choose i - 1)
// (n - 1 choose 0) = 1
// (n - 1 choose i)

const int M = 1e9 + 7;
int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    ll ans = 1;
    rep(i, 1, n + 1) {
        ans = (ans * i) % M;
    }
    ll pow2 = 1;
    rep(i, 0, n - 1) {
        pow2 = (2 * pow2) % M;
    }
    ans = (ans - pow2) % M;
    ans = (ans + M) % M;
    cout << ans << '\n';
}