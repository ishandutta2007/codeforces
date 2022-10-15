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

struct target {
    int i, j;

    target(int i, int j) : i(i), j(j) {}
};

struct triple {
    int a1, a2, a3;

    triple(int a1, int a2, int a3) : a1(a1), a2(a2), a3(a3) {}
};

void solve() {
    autoint n;
    vector<int> a(n);
    cin >> a;
    int last3 = n - 1 - (find(a.rbegin(), a.rend(), 3) - a.rbegin());
    int last2 = n - 1 - (find(a.rbegin(), a.rend(), 2) - a.rbegin());
    int last1 = n - 1 - (find(a.rbegin(), a.rend(), 1) - a.rbegin());

    if (last3 > last2 && last3 > last1) answer(-1);

    int cnt1 = count(a.begin(), a.end(), 1);
    int cur1 = 0, cur3 = cnt1;
    vector<int> ones;
    vector<target> ans;

    if (last3 > last2){
        bool f3 = true;
        for (int i = last1 - 1; i >= 0; --i){
            if (a[i] == 3){
                ans.emplace_back(i, cur3);
                ans.emplace_back(last1, cur3);
                if (f3) ans.emplace_back(last1, cur3 - 1);cur3++;
                f3 = false;
                last1 = i;
            } else if (a[i] == 2){
                if (ones.empty()) answer(-1);
                int x = ones.back();
                ones.pop_back();
                ans.emplace_back(i, cur1);
                ans.emplace_back(x, cur1++);
            }else if (a[i] == 1){
                ones.push_back(i);
            }
        }
        for (int x : ones){
            ans.emplace_back(x, cur1++);
        }
    } else {

        for (int i = a.size() - 1; i >= 0; --i){
            if (a[i] == 3){
                ans.emplace_back(i, cur3);
                ans.emplace_back(last2, cur3++);
                last2 = i;
            } else if (a[i] == 2){
                if (ones.empty()) answer(-1);
                int x = ones.back();
                ones.pop_back();
                ans.emplace_back(i, cur1);
                ans.emplace_back(x, cur1++);
            }else if (a[i] == 1){
                ones.push_back(i);
            }
        }
        for (int x : ones){
            ans.emplace_back(x, cur1++);
        }
    }
    cout << ans.size() << '\n';
    for (auto target : ans){
        cout << n - target.j << ' ' << target.i + 1 << '\n';
    }
}