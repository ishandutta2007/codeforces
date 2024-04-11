#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vec<vec<int>> a(n, vec<int>(m));
    for (auto &xs : a)
        for (auto &x : xs)
            cin >> x;
    vec<vec<int>> b(n, vec<int>(m));
    for (auto &xs : b)
        for (auto &x : xs)
            cin >> x;

    vec<int> bad(m);
    vec<int> que;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n - 1; i++)
            bad[j] += (b[i][j] > b[i + 1][j]);
        if (!bad[j])
            que.push_back(j);
    }

    vec<char> used(n);
    for (int st = 0; st < len(que); st++) {
        int j = que[st];
        for (int i = 0; i < n - 1; i++)
            if (!used[i] && b[i][j] != b[i + 1][j]) {
                used[i] = 1;
                for (int k = 0; k < m; k++)
                    if (b[i][k] > b[i + 1][k]) {
                        bad[k]--;
                        if (!bad[k])
                            que.push_back(k);
                    }
            }
    }

    reverse(all(que));
    vec<int> ord(n);
    iota(all(ord), 0);
    for (auto j : que)
        stable_sort(all(ord), [&](int x, int y) {
            return a[x][j] < a[y][j];
        });

    for (int i = 0; i < n; i++)
        if (b[i] != a[ord[i]]) {
            cout << "-1\n";
            return 0;
        }

    cout << len(que) << '\n';
    for (auto j : que)
        cout << j + 1 << ' ';
    cout << '\n';
}