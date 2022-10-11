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

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> freq(n);
    for (auto &x : a) {
        cin >> x;
        x--;
        freq[x]++;
    }

    const int B = sqrt(n);
    const int x = max_element(all(freq)) - freq.begin();
    int answer = 0;

    int timer = 0;
    vector<int> used(2 * n);
    vector<int> first_seen(2 * n);

    auto reset = [&]() {
        timer++;
    };

    auto get = [&](int pos) {
        return used[pos] != timer ? -2 : first_seen[pos];
    };

    auto set_value = [&](int pos, int value) {
        first_seen[pos] = value;
        used[pos] = timer;
    };

    auto solve_big = [&](int y) {
        if (x == y || freq[y] == 0)
            return;

        reset();
        int pref = n;
        set_value(pref, -1);

        for (int i = 0; i < n; i++) {
            if (a[i] == x)
                pref++;
            else if (a[i] == y)
                pref--;

            if (get(pref) == -2)
                set_value(pref, i);
            else
                answer = max(answer, i - get(pref));
        }
    };

    vector<vector<int>> positions(n);
    for (int i = 0; i < n; i++)
        positions[a[i]].push_back(i);

    vector<int> prev(n, -1);
    for (int i = 1; i < n; i++)
        prev[i] = a[i - 1] == x ? i - 1 : prev[i - 1];

    vector<int> nxt(n, n);
    for (int i = n - 2; i >= 0; i--)
        nxt[i] = a[i + 1] == x ? i + 1 : nxt[i + 1];

    vector<pair<int, int>> new_a((B + 1) * 2 * B + B + 1);
    vector<pair<int, int>> tmp(B + 2);

    auto solve_small = [&](int y) {
        if (x == y || freq[y] == 0)
            return;

        int new_a_pos = 0;
        for (int i = 0; i < freq[y]; i++) {
            int tmp_pos = 0;
            for (int j = prev[positions[y][i]]; tmp_pos < freq[y] + 1 && j > (new_a_pos == 0 ? -1 : new_a[new_a_pos - 1].second); j = prev[j])
                tmp[tmp_pos++] = {1, j};

            while (tmp_pos)
                new_a[new_a_pos++] = tmp[--tmp_pos];

            new_a[new_a_pos++] = {-1, positions[y][i]};
            for (int j = nxt[positions[y][i]]; tmp_pos < freq[y] + 1 && j < (i == freq[y] - 1 ? n : positions[y][i + 1]); j = nxt[j], tmp_pos++)
                new_a[new_a_pos++] = {1, j};
        }

        reset();
        int pref = n;
        set_value(pref, prev[new_a[0].second]);

        for (int i = 0; i < new_a_pos; i++) {
            const auto &[type, position] = new_a[i];
            pref += type;

            if (get(pref) == -2)
                set_value(pref, position);
            else
                answer = max(answer, (i == new_a_pos - 1 ? n - 1 : new_a[i + 1].second - 1) - get(pref));
        }
    };

    for (int y = 0; y < n; y++)
        if (freq[y] > B)
            solve_big(y);
        else
            solve_small(y);

    cout << answer << '\n';
}