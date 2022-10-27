#include<bits/stdc++.h>
using namespace std;
const int nax = 1e5 + 10;
const int B = 150;
const int ITER = (nax + 2 * B) / B;
int n;
int a[nax];
int16_t q[ITER][nax];
int f[nax * B * 2];
int ans;
vector <int> memo[ITER];

void solve() {
    for (int x = 0 ; x <= B ; ++ x) {
        for (int i = 0 ; i < n ; ++ i) {
            ans = max(ans, f[a[i] - i * x + nax * B] += 1);
        }
        for (int i = 0 ; i < n ; ++ i)
            f[a[i] - i * x + nax * B] -= 1;
    }

    int cur = 0;
    vector <pair< int, int>> buffer;
    int other_ans = 0;
    for (int i = 0 ; i < n ; ++ i) {
        buffer.clear();
        for (int x = max(0, i - ITER) ; x < i ; ++ x) {
            int l = i - x;
            int g = (a[i] - a[x]);
            if (g < 0 || g % l) continue;
            int d = g / l;
            int where = x % ITER;
            int cc = q[where][d];
            other_ans = max(other_ans, 1 + q[where][d]);
            buffer.emplace_back(d, 1 + q[where][d]);
        }
        for (int y : memo[cur]) {
            q[cur][y] = 0;
        }
        memo[cur].clear();
        for (auto [y, z] : buffer) {
            memo[cur].push_back(y);
            q[cur][y] = max(q[cur][y], int16_t(z));
        }
        cur = (cur == ITER - 1) ? 0 : cur + 1;
    }
    ans = max(ans, other_ans + 1);
    for (int i = 0 ; i < ITER ; ++ i) {
        memo[i].clear();
    }
    memset(q, 0, sizeof(q));
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 0 ; i < n ; ++ i)
        cin >> a[i];


    for (int i = 0 ; i < 2 ; ++ i) {
        solve();
        reverse(a, a + n);
    }
    cout << n - ans << '\n';
}