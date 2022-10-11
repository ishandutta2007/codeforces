#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

inline int to_int(const string &s) {
    int x = 0;
    for (auto c : s) {
        x *= 10;
        x += c - '0';
    }
    return x;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    ar<set<int>, 2> free_poses;
    ar<set<int>, 2> bad_poses;
    ar<vec<string>, 2> free_files;
    vec<int> who(n, -1);
    auto get_index = [&](const string &s) {
        bool ok = true;
        ok &= s[0] != '0';
        for (auto x : s) {
            ok &= isdigit(x);
        }
        if (!ok) return -1;
        int x = to_int(s) - 1;
        if (0 <= x && x < n) return x;
        return -1;
    };
    set<string> names;
    int pretests = 0;
    for (int i = 0; i < n; i++) {
        string name;
        int type;
        cin >> name >> type;
        names.insert(name);
        pretests += type;
        int id = get_index(name);
        if (id == -1) {
            free_files[type].push_back(name);
        } else {
            who[id] = type;
        }
    }
    for (int i = 0; i < pretests; i++) {
        if (who[i] == 1) continue;
        if (who[i] == -1) {
            free_poses[1].insert(i);
        } else {
            bad_poses[1].insert(i);
        }
    }
    for (int i = pretests; i < n; i++) {
        if (who[i] == 0) continue;
        if (who[i] == -1) {
            free_poses[0].insert(i);
        } else {
            bad_poses[0].insert(i);
        }
    }
    vec<pair<string, string>> ans;
    if (len(free_poses[0]) + len(free_poses[1]) == 0 && len(bad_poses[0]) + len(bad_poses[1]) > 0) {
        for (int i = 0; i < 2; i++) {
            if (!len(bad_poses[i])) continue;
            int who = *bad_poses[i].begin();
            bad_poses[i].erase(bad_poses[i].begin());
            string name(6, 'a');
            while (names.count(name)) {
                for (auto &x : name) {
                    x = 'a' + rand() % 26;
                }
            }
            ans.emplace_back(to_string(who + 1), name);
            free_files[i ^ 1].push_back(name);
            free_poses[i].insert(who);
            break;
        }
    }
    // dbg(pretests);
    // dbg(free_files);
    // dbg(bad_poses);
    // dbg(free_poses);
    // for (int i = 0; i < 2; i++) {
    //     assert(len(free_poses[i]) + len(bad_poses[i]) == len(bad_poses[i ^ 1]) + len(free_files[i]));
    // }
    while (true) {
        bool any = false;
        for (int i = 0; i < 2; i++) {
            if (!len(free_poses[i]) || !len(bad_poses[i ^ 1])) continue;
            any = true;
            int to = *free_poses[i].begin();
            free_poses[i].erase(free_poses[i].begin());
            int from = *bad_poses[i ^ 1].begin();
            bad_poses[i ^ 1].erase(bad_poses[i ^ 1].begin());
            free_poses[i ^ 1].insert(from);
            ans.emplace_back(to_string(from + 1), to_string(to + 1));
            break;
        }
        if (!any) break;
    }
    // dbg(free_files);
    // dbg(bad_poses);
    // dbg(free_poses);
    for (int i = 0; i < 2; i++) {
        assert(len(free_files[i]) == len(free_poses[i]));
        while (len(free_files[i])) {
            string from = free_files[i].back();
            free_files[i].pop_back();
            int pos = *free_poses[i].begin();
            free_poses[i].erase(free_poses[i].begin());
            ans.emplace_back(from, to_string(pos + 1));
        }
    }
    cout << len(ans) << '\n';
    for (auto [s, t] : ans) {
        cout << "move " << s << ' ' << t << '\n';
    }
}