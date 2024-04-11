#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

int n, m;
vector<int> fenw;

int get(int pos) {
    int ans = 0;
    for (; pos >= 0; pos &= pos + 1, pos--)
        ans += fenw[pos];
    return ans;
}

int get(int L, int R) {
    return get(R) - get(L - 1);
}

void update(int pos, int new_val) {
    int del = new_val - get(pos, pos);
    for (; pos < n + m; pos |= pos + 1)
        fenw[pos] += del;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    vector<int> min_ans(n), max_ans(n);
    for (int i = 0; i < n; i++)
        min_ans[i] = max_ans[i] = i + 1;
    vector<int> q(m);
    for (int i = 0; i < m; i++) {
        cin >> q[i], q[i]--;
        min_ans[q[i]] = 1;
    }
    fenw.resize(n + m);
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        update(m + i, 1);
        pos[i] = m + i;
    }
    for (int i = 0; i < m; i++) {
        max_ans[q[i]] = max(max_ans[q[i]], get(0, pos[q[i]]));
        update(pos[q[i]], 0);
        pos[q[i]] = m - 1 - i;
        update(pos[q[i]], 1);
    }
    for (int i = 0; i < n; i++)
        max_ans[i] = max(max_ans[i], get(0, pos[i]));
    for (int i = 0; i < n; i++)
        cout << min_ans[i] << ' ' << max_ans[i] << '\n';
}