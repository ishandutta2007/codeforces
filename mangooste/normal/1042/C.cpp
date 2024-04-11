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
    array<vector<pair<int, int>>, 3> groups;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int type = x < 0 ? 0 : (x == 0 ? 1 : 2);
        groups[type].emplace_back(x, i);
    }

    vector<vector<int>> answer;
    if (len(groups[2]) > 0 || len(groups[0]) > 1) {
        sort(all(groups[0]));
        if (len(groups[0]) & 1) {
            if (len(groups[1]) > 0)
                answer.push_back({1, groups[0].back().second + 1, groups[1].back().second + 1});
            else
                answer.push_back({2, groups[0].back().second + 1});

            groups[0].pop_back();
        }

        int where, st = 0;
        if (len(groups[2]) > 0) {
            where = groups[2][0].second;
            groups[2].erase(groups[2].begin());
        } else {
            assert(len(groups[0]) > 0);
            st = 1;
            where = groups[0][0].second;
        }

        for (int i = 0; i < len(groups[1]) - 1; i++)
            answer.push_back({1, groups[1][i].second + 1, groups[1][i + 1].second + 1});

        if (len(groups[1]))
            answer.push_back({2, groups[1].back().second + 1});

        for (const auto [_, i] : groups[2])
            answer.push_back({1, i + 1, where + 1});

        for (int i = st; i < len(groups[0]); i++)
            answer.push_back({1, groups[0][i].second + 1, where + 1});

    } else if (len(groups[1])) {
        assert(len(groups[0]) <= 1);
        if (len(groups[0]))
            answer.push_back({1, groups[0][0].second + 1, groups[1].back().second + 1});

        for (int i = len(groups[1]) - 1; i > 0; i--)
            answer.push_back({1, groups[1][i].second + 1, groups[1][i - 1].second + 1});

    } else
        assert(false);

    assert(len(answer) == n - 1);
    for (const auto &vec : answer)
        copy(all(vec), ostream_iterator<int>(cout, " ")), cout << '\n';
}