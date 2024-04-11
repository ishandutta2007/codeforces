/*
    author:  Maksim1744
    created: 06.11.2019 20:56:07
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        vector<int> cnt(26, 0);
        for (auto c : s + t) {
            cnt[c - 'a']++;
        }
        bool ok = true;
        for (auto k : cnt) {
            if (k % 2 == 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            cout << "No\n";
            continue;
        }
        cout << "Yes\n";
        // queue<char> q;
        vector<int> cs(26, 0);
        for (auto c : s) {
            cs[c - 'a']++;
        }
        for (int i = 0; i < 26; ++i) {
            cnt[i] /= 2;
        }
        // for (int i = 0; i < 26; ++i) {
        //     for (int j = 0; j < cs[i] - cnt[i]; ++j) {
        //         q.push('a' + i);
        //     }
        // }
        vector<pair<int, int>> ans;
        while (s != t) {
            // auto c = q.front();
            // q.pop();
            char c = 0;
            show(cs, cnt);
            for (int i = 0; i < 26; ++i) {
                if (cs[i] > cnt[i])
                    c = 'a' + i;
            }
            if (c == 0) {
                int i1 = 0;
                while (s[i1] == t[i1])
                    ++i1;
                for (int i = 0; i < n; ++i) {
                    if (s[i] != t[i] && s[i] != t[i1]) {
                        cs[s[i] - 'a']--;
                        swap(s[i], t[i1]);
                        cs[s[i] - 'a']++;
                        ans.eb(i1 + 1, i + 1);
                        break;
                    }
                }
                continue;
            }
            int i1 = -1;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i] && s[i] == c) {
                    i1 = i;
                    break;
                }
            }
            int i2 = -1;
            for (int i = i1 + 1; i < n; ++i) {
                if (s[i] != t[i] && s[i] == s[i1]) {
                    i2 = i;
                }
            }
            show(s, t);
            show(c, i1, i2);
            assert(i2 != -1);
            cs[s[i2] - 'a']--;
            swap(t[i1], s[i2]);
            cs[s[i2] - 'a']++;
            ans.eb(i2 + 1, i1 + 1);
        }
        cout << ans.size() << '\n';
        for (auto [x, y] : ans) {
            cout << x << ' ' << y << '\n';
        }
    }
    return 0;
}