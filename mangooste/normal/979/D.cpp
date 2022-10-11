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

    constexpr int A = 1e5 + 4;
    constexpr int LG = __lg(A) + 1;

    vector<vector<int>> divs(A);
    for (int i = 1; i < A; i++)
        for (int j = i; j < A; j += i)
            divs[j].push_back(i);

    vector<set<int>> st(A);
    int q;
    cin >> q;

    while (q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;
            for (auto y : divs[x])
                st[y].insert(x);
        } else {
            int x, k, mx;
            cin >> x >> k >> mx;
            mx -= x;

            if (x % k != 0) {
                cout << "-1\n";
                continue;
            }

            int answer = 0;
            for (int bit = LG - 1; bit >= 0; bit--) {
                int need = ((x >> bit) & 1) ^ 1;
                int l = answer ^ (need << bit), r = answer ^ (need << bit) ^ ((1 << bit) - 1);

                auto it_l = st[k].lower_bound(l);
                auto it_r = st[k].upper_bound(r);
                if (it_l != it_r && *it_l <= mx)
                    answer ^= need << bit;
                else
                    answer ^= (need ^ 1) << bit;
            }

            if (answer > mx || !st[k].count(answer))
                answer = -1;

            cout << answer << '\n';
        }
    }
}