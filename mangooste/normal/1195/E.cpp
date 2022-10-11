#include <bits/stdc++.h>
using namespace std;
using ll = long long;
template<typename A, typename B = A> using pr = pair<A, B>;
#define vec vector
#define ar array
#define len(a) ((int)((a).size()))
#define all(a) (a).begin(), (a).end()

struct stack_min {
    vec<pr<int>> st;

    stack_min() {}

    inline int get_min() {
        if (!len(st))
            return INT_MAX;
        return st.back().second;
    }

    inline void push_back(int x) {
        int y = min(x, get_min());
        st.emplace_back(x, y);
    }

    inline void rev() {
        reverse(all(st));
        st[0].second = st[0].first;
        for (int i = 1; i < len(st); i++)
            st[i].second = min(st[i].first, st[i - 1].second);
    }

    inline void pop_back() {
        st.pop_back();
    }
};

struct queue_min {
    stack_min front, back;

    queue_min() {}

    inline void push(int x) {
        back.push_back(x);
    }

    inline void pop() {
        if (!len(front.st)) {
            swap(front, back);
            front.rev();
        }
        front.pop_back();
    }

    inline int get_min() {
        return min(front.get_min(), back.get_min());
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vec<int> g(n * m);
    int x, y, z;
    cin >> g[0] >> x >> y >> z;
    for (int i = 1; i < len(g); i++)
        g[i] = (1ll * g[i - 1] * x + y) % z;

    vec<vec<int>> mat(n, vec<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mat[i][j] = g[i * m + j];

    vec<vec<int>> right(n, vec<int>(m));
    for (int i = 0; i < n; i++) {
        queue_min q;
        for (int j = 0; j < b; j++)
            q.push(mat[i][j]);
        for (int j = 0; j + b <= m; j++) {
            right[i][j] = q.get_min();
            if (j + b != m) {
                q.pop();
                q.push(mat[i][j + b]);
            }
        }
    }

    ll ans = 0;
    for (int j = 0; j + b <= m; j++) {
        queue_min q;
        for (int i = 0; i < a; i++)
            q.push(right[i][j]);
        for (int i = 0; i + a <= n; i++) {
            ans += q.get_min();
            if (i + a != n) {
                q.pop();
                q.push(right[i + a][j]);
            }
        }
    }
    cout << ans << '\n';
}