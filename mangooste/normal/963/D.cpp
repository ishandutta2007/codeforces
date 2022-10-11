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

template<typename T, int SZ>
struct container_hash {
    int add(int a, int b, int j) const {
        a += b;
        if (a >= mods[j])
            return a - mods[j];

        return a;
    }

    int mult(int a, int b, int j) const {
        return (long long) a * b % mods[j];
    }

    int sub(int a, int b, int j) const {
        a -= b;
        if (a < 0)
            return a + mods[j];

        return a;
    }

    // std::array<std::vector<int>, SZ> pref_hash;
    std::array<std::vector<int>, SZ> suf_hash;
    std::array<std::vector<int>, SZ> base_degree;

    std::array<int, SZ> mods;
    std::array<int, SZ> bases;

    container_hash() {}
    container_hash(const T &str, const std::array<int, SZ> &mods, const std::array<int, SZ> &bases)
        : mods(mods), bases(bases)
    {
        int n = str.size();
        for (int j = 0; j < SZ; j++) {
            base_degree[j].resize(n + 1, 1 % mods[j]);
            for (int i = 0; i < n; i++)
                base_degree[j][i + 1] = mult(base_degree[j][i], bases[j], j);

            // pref_hash[j].resize(n + 1);
            // for (int i = 0; i < n; i++)
            //     pref_hash[j][i + 1] = add(mult(pref_hash[j][i], bases[j], j), str[i], j);

            suf_hash[j].resize(n + 1);
            for (int i = n - 1; i >= 0; i--)
                suf_hash[j][i] = add(mult(suf_hash[j][i + 1], bases[j], j), str[i], j);
        }
    }

    // std::array<int, SZ> hash(int l, int r) const {
    //     std::array<int, SZ> current_hash;
    //     for (int j = 0; j < SZ; j++)
    //         current_hash[j] = sub(pref_hash[j][r], mult(pref_hash[j][l], base_degree[j][r - l], j), j);

    //     return current_hash;
    // }

    std::array<int, SZ> reversed_hash(int l, int r) const {
        std::array<int, SZ> current_hash;
        for (int j = 0; j < SZ; j++)
            current_hash[j] = sub(suf_hash[j][l], mult(suf_hash[j][r], base_degree[j][r - l], j), j);

        return current_hash;
    }
};

// constexpr int SZ = 3;
// constexpr array<int, SZ> mods = array<int, SZ>{int(1e9) + 7, int(1e9) + 9, int(1e9) + 21};
// constexpr array<int, SZ> bases = array<int, SZ>{239, 241, 991};

constexpr int SZ = 2;
constexpr array<int, SZ> mods = array<int, SZ>{int(1e9) + 7, int(1e9) + 9};
constexpr array<int, SZ> bases = array<int, SZ>{239, 241};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    string s;
    int q;
    cin >> s >> q;

    int n = len(s);
    container_hash<string, SZ> s_hash(s, mods, bases);

    vector<int> k(q);
    vector<string> strings(q);
    vector<int> answer(q, -1);
    vector<vector<int>> queries(n + 1);

    for (int i = 0; i < q; i++) {
        cin >> k[i] >> strings[i];
        if (len(strings[i]) <= n)
            queries[len(strings[i])].push_back(i);
    }

    vector<vector<int>> positions(q);
    for (int len = 1; len <= n; len++) {
        if (queries[len].empty())
            continue;

        map<array<int, SZ>, int> mapa;
        for (auto i : queries[len])
            mapa[container_hash<string, SZ>(strings[i], mods, bases).reversed_hash(0, len)] = i;

        for (int i = 0; i + len <= n; i++) {
            const auto current_hash = s_hash.reversed_hash(i, i + len);
            auto it = mapa.find(current_hash);
            if (it != mapa.end())
                positions[it->second].push_back(i);
        }

        for (auto i : queries[len]) {
            if (len(positions[i]) < k[i])
                continue;

            answer[i] = INT_MAX;
            for (int j = 0; j + k[i] <= len(positions[i]); j++)
                answer[i] = min(answer[i], positions[i][j + k[i] - 1] - positions[i][j]);

            answer[i] += len;
        }
    }

    for (auto x : answer)
        cout << x << '\n';
}