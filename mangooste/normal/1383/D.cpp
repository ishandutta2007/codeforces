#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif



int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto &xs : a)
        for (auto &x : xs)
            cin >> x;

    vector<char> row_max(n * m + 1);
    for (int i = 0; i < n; i++)
        row_max[*max_element(all(a[i]))] = 1;

    vector<char> col_max(n * m + 1);
    for (int j = 0; j < m; j++) {
        int mx = 0;
        for (int i = 0; i < n; i++)
            mx = max(mx, a[i][j]);

        col_max[mx] = 1;
    }

    vector<vector<int>> answer(n, vector<int>(m));
    queue<pair<int, int>> que;
    int cur_i = 0, cur_j = 0;
    for (int val = n * m; val; val--)
        if (row_max[val] && col_max[val]) {
            answer[cur_i][cur_j] = val;
            for (int j = cur_j - 1; j >= 0; j--)
                que.push({cur_i, j});

            for (int i = cur_i - 1; i >= 0; i--)
                que.push({i, cur_j});

            cur_i++, cur_j++;
        } else if (row_max[val]) {
            answer[cur_i][cur_j - 1] = val;
            for (int j = cur_j - 2; j >= 0; j--)
                que.push({cur_i, j});

            cur_i++;
        } else if (col_max[val]) {
            answer[cur_i - 1][cur_j] = val;
            for (int i = cur_i - 2; i >= 0; i--)
                que.push({i, cur_j});

            cur_j++;
        } else {
            const auto [x, y] = que.front();
            que.pop();
            answer[x][y] = val;
        }

    for (const auto &xs : answer) {
        for (auto x : xs)
            cout << x << ' ';

        cout << '\n';
    }
}