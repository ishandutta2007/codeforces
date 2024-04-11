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
    [[maybe_unused]] int m;
    cin >> n >> m;
    array<set<pair<int, int>>, 2> valid;
    for (int i = 0; i < 2; i++)
        valid[i].emplace(0, -1);

    vector<array<int, 2>> parent(n);
    int previous = 0;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        array<pair<int, int>, 2> conds;
        for (int j = 0; j < 2; j++)
            cin >> conds[j].first >> conds[j].second;

        array<char, 2> dp;
        for (int j = 0; j < 2; j++)
            dp[j] = len(valid[j]) > 0;

        for (int j = 0; j < 2; j++) {
            if (!(conds[j].first <= value && value <= conds[j].second)) {
                valid[j].clear();
                continue;
            }

            if (dp[j ^ 1])
                valid[j].emplace(previous, i - 1);

            while (len(valid[j]) && valid[j].rbegin()->first > conds[j ^ 1].second)
                valid[j].erase(prev(valid[j].end()));

            while (len(valid[j]) && valid[j].begin()->first < conds[j ^ 1].first)
                valid[j].erase(valid[j].begin());

            if (len(valid[j]))
                parent[i][j] = valid[j].begin()->second;
        }
        previous = value;
    }

    if (len(valid[0]) + len(valid[1]) == 0) {
        cout << "No\n";
        return 0;
    }
    cout << "Yes\n";

    vector<int> answer(n);
    int who = len(valid[0]) == 0;
    for (int i = n - 1; i >= 0; i = parent[i][who], who ^= 1)
        for (int j = parent[i][who] + 1; j <= i; j++)
            answer[j] = who;

    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}