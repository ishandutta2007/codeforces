
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
int n, a[N];

int solve(int l, int r, int b) {
    if(b == -1 || l == r) return 0;
    int m = stable_partition(a + l, a + r, [&](int x) {
        return x >> b & 1;
    }) - a;
    int A = solve(l, m, b - 1);
    int B = solve(m, r, b - 1);
    if(m == l) return B;
    if(m == r) return A;
    return min(A + r - m - 1, B + m - l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    cout << solve(0, n, 30) << '\n';
}