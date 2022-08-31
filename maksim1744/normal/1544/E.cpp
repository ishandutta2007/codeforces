/*
    author:  Maksim1744
    created: 17.07.2021 18:03:27
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

void test_case(int test) {
    string s;
    cin >> s;
    int n = s.size();
    if (count(s.begin(), s.end(), s[0]) == s.size()) {
        cout << s << '\n';
        return;
    }

    vector<int> cnt(128);
    for (char c : s)
        cnt[c]++;
    vector<pair<char, int>> cnts;
    for (int i = 'a'; i <= 'z'; ++i)
        if (cnt[i])
            cnts.eb(i, cnt[i]);

    for (char c = 'a'; c <= 'z'; ++c) {
        if (cnt[c] == 1) {
            string t;
            t.pb(c);
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                int cur = cnt[c2];
                if (c2 == c) --cur;
                t += string(cur, c2);
            }
            cout << t << '\n';
            return;
        }
    }

    vector<string> cands;

    // xx...
    {
        for (char c = 'a'; c <= 'z'; ++c) {
            if (cnt[c] >= 2) {
                int other = n - cnt[c];
                int me = cnt[c] - 2;
                if (me > other) continue;

                string tmp;
                for (auto [a, b] : cnts) {
                    if (a != c) {
                        tmp += string(b, a);
                    }
                }

                string t;
                for (char x : tmp) {
                    if (x > c && me > 0 && !t.empty()) {
                        --me;
                        t.pb(c);
                    }
                    t.pb(x);
                }
                reverse(t.begin(), t.end());
                tmp = t;
                t.clear();
                if (me > 0 && tmp[0] < c) {
                    t.pb(c);
                    --me;
                }
                for (char x : tmp) {
                    t.pb(x);
                    if (x < c && me > 0) {
                        --me;
                        t.pb(c);
                    }
                }
                t.pb(c);
                t.pb(c);
                reverse(t.begin(), t.end());
                if (me)
                    t.pb(c);
                cands.pb(t);
                break;
            }
        }
    }

    // xy...
    {
        bool found = false;
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            if (cnt[c1] == 0) continue;
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                if (c1 == c2) continue;
                if (cnt[c2] == 0) continue;

                string t;
                for (char c = 'a'; c <= 'z'; ++c) {
                    int cur = cnt[c];
                    if (c == c1 || c == c2) --cur;
                    t += string(cur, c);
                }

                for (int i = 0; i + 1 < t.size(); ++i) {
                    if (t[i] == c1 && t[i + 1] == c2) {
                        bool ok = false;
                        for (int j = i + 1; j < t.size(); ++j) {
                            if (t[j] != t[i + 1]) {
                                swap(t[j], t[i + 1]);
                                ok = true;
                                break;
                            }
                        }
                        if (ok) break;

                        int j = i;
                        while (j - 1 >= 0 && t[j - 1] == t[j])
                            --j;
                        reverse(t.begin() + j, t.end());
                        break;
                    }
                }

                reverse(t.begin(), t.end());
                t += c2;
                t += c1;
                reverse(t.begin(), t.end());

                found = true;
                cands.pb(t);
                break;
            }
            if (found) break;
        }
    }

    show(cands);

    assert(!cands.empty());
    cout << mine(cands) << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}