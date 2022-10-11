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

    int n, k;
    cin >> n >> k;
    vector<vector<int>> positions(n);
    for (int i = 0; i < n * k; i++) {
        int color;
        cin >> color;
        positions[color - 1].push_back(i);
    }

    set<int> st;
    for (int i = 0; i < n; i++)
        st.insert(i);

    vector<pair<int, int>> answer(n);
    int in_one = (n + k - 2) / (k - 1);
    for (int pos = 1; len(st); pos++) {
        vector<int> ord(all(st));
        sort(all(ord), [&](int i, int j) {
            return positions[i][pos] < positions[j][pos];
        });

        for (int i = 0; i < len(ord) && i < in_one; i++) {
            st.erase(ord[i]);
            answer[ord[i]] = {positions[ord[i]][pos - 1], positions[ord[i]][pos]};
        }
    }

    for (const auto &[l, r] : answer)
        cout << l + 1 << ' ' << r + 1 << '\n';
}