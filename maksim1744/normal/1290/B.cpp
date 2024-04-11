/*
    author:  Maksim1744
    created: 02.02.2020 17:15:06
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
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    string s;
    cin >> s;
    int n = s.size();
    vector<int> v(n);
    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][s[i] - 'a']++;
    }
    v[0] = 0;
    for (int i = 1; i < n; ++i) {
        v[i] = v[i - 1];
        if (s[i] != s[i - 1])
            v[i]++;
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        --l; --r;
        if (l == r) {
            cout << "Yes\n";
        } else {
            if (v[l] == v[r]) {
                cout << "No\n";
            } else if (s[l] != s[r]) {
                cout << "Yes\n";
            } else {
                char c = s[l];
                int dif = 0;
                for (int j = 0; j < 26; ++j) {
                    if (c - 'a' == j) continue;
                    if (cnt[r + 1][j] != cnt[l][j]) ++dif;
                }
                if (dif >= 2)
                    cout << "Yes\n";
                else
                    cout << "No\n";
            }
        }
    }

                // if (s[l] == s[r] && cnt[r + 1][s[r] - 'a'] - cnt[l][s[l] - 'a'] == r - l)
                //     cout << "No\n";
                // else
                //     cout << "Yes\n";
    return 0;
}