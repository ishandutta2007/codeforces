#include <bits/stdc++.h>

namespace {
    using namespace std;
#define int long long

    template<typename T>
    inline bool whitespace(const vector<T> &) { return false; }

    template<typename T>
    inline bool whitespace(const T &) { return true; }

    inline bool whitespace(const char) { return false; }

    template<typename F, typename S>
    inline bool whitespace(const pair<F, S> &) { return false; }

    template<typename F, typename S>
    ostream &operator<<(ostream &os, const pair<F, S> &p) {
        os << p.first << (whitespace(p.second) ? " " : "") << p.second << "\n";
        return os;
    }

    template<typename F, typename S>
    istream &operator>>(istream &is, pair<F, S> &p) {
        is >> p.first >> p.second;
        return is;
    }

    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    template<typename T>
    istream &operator>>(istream &is, deque<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const deque<T> &v) {
        for (const T &t : v) os << t << (whitespace(t) ? " " : "");
        os << "\n";
        return os;
    }

    class exit_exception : exception {
    };

    void answer() {}

    template<typename First, typename... Args>
    void answer(First &&val, Args &&... ans) {
        cout << val << "\n";
        answer(ans...);
        throw exit_exception();
    }

    struct autoint {
        int x;

        autoint(int i) : x(i) {}

        autoint() { cin >> x; }

        operator int() { return x; }

        int operator--() { return --x; }

        int operator--(signed) { return x--; }

        int operator++() { return ++x; }

        int operator++(signed) { return x++; }
    };
}

void solve();

signed main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { try { solve(); } catch (exit_exception &) {}} while (--t);
    return 0;
}

vector<string> find_x_sum(int x) {
    if (x == 0) return {""};
    if (x == 1 || x < 0) return {};
    vector<string> ans;
    for (int d = 2; d < 10; ++d) {
        auto next = find_x_sum(x - d);
        for (const auto &str : next) ans.push_back(to_string(d) + str);
    }
    return ans;
}

vector<string> find_prime_strings(int x) {
    vector<string> x_sum = find_x_sum(x);
    vector<string> x_prime;
    for (auto str : x_sum) {
        bool prime = true;
        for (int i = 0; i < str.size(); ++i) {
            for (int j = i; j < str.size(); ++j) {
                if (i == 0 && j == str.size() - 1) continue;
                int sum = 0;
                for (int k = i; k <= j; ++k) {
                    sum += str[k] - '0';
                }
                if (x % sum == 0) prime = false;
            }
        }
        if (prime) x_prime.push_back(str);
    }
    return x_prime;
}

void solve() {
    string s;
    cin >> s;
    autoint x;
    vector<string> x_prime = find_prime_strings(x);
    sort(x_prime.begin(), x_prime.end());
    if (x == 1) x_prime.emplace_back("1");


    set<string> prefixes{""};

    for (auto &str: x_prime) {
        string prefix;
        for (char c : str) {
            prefix += c;
            prefixes.insert(prefix);
        }
    }
    vector<string> states(prefixes.begin(), prefixes.end());

    auto state = [&](const string &s) -> int {
        string end;
        int suffix_prefix = 0;
        for (int i = (int)s.size() - 1; i >= 0; --i) {
            end = string(1, s[i]).append(end);
            auto iter = lower_bound(states.begin(), states.end(), end);
            if (*iter == end) suffix_prefix = iter - states.begin();
        }
        return suffix_prefix;
    };
    auto prime = [&](const string &s) { return *lower_bound(x_prime.begin(), x_prime.end(), s) == s; };

    vector<int> not_x_prime;
    for (int i = 0; i < states.size(); ++i) if (!prime(states[i])) not_x_prime.push_back(i);
    vector<vector<int>> next(states.size(), vector<int>(10));
    for (int i = 0; i < states.size(); ++i){
        for (int c = 1; c < 10; ++c){
            next[i][c] = state(states[i] + string(1, c + '0'));
        }
    }


    vector<vector<int>> dp(s.size() + 1, vector<int>(states.size(), s.size()));
    dp[0][state("")] = 0;

    for (int i = 0; i < s.size(); ++i) {
        for (int c : not_x_prime) {
            auto next_state = next[c][s[i] - '0'];
            dp[i + 1][next_state] = min(dp[i + 1][next_state], dp[i][c]);
            dp[i + 1][c] = min(dp[i + 1][c], dp[i][c] + 1);
        }
    }

    int ans = s.size();
    for (int c : not_x_prime) ans = min(ans, dp[s.size()][c]);
    cout << ans << '\n';
}