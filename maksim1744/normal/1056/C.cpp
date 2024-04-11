/*
    author:  Maksim1744
    created: 17.04.2019 17:18:05
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n * 2);
    cin >> p;
    vector<pair<int, int>> pp(m);
    set<pair<int, int>> s;
    set<pair<int, int>> s2;
    vector<int> with(n * 2, -1);
    for (int i = 0; i < n * 2; ++i) {
        s.insert({p[i], i});
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        if (p[a] < p[b])
            swap(a, b);
        s2.insert({a, b});
        with[a] = b;
        with[b] = a;
        pp[i] = {a, b};
    }
    int t;
    cin >> t;
    if (t == 1) {
        for (int i = 0; i < m; ++i) {
            int a = pp[i].first;
            int b = pp[i].second;
            s.erase({p[a], a});
            s.erase({p[b], b});
        }
        for (int i = 0; i < m; ++i) {
            cout << pp[i].first + 1 << endl;
            int k;
            cin >> k;
            if (k == -1) throw;
        }
        for (int i = 0; i < n - m; ++i) {
            auto it = s.end();
            --it;
            cout << it->second + 1 << endl;
            s.erase(it);
            int h;
            cin >> h;
            if (h == -1) throw;
            --h;
            s.erase({p[h], h});
        }
    } else {
        while (!s.empty()) {
            int k;
            cin >> k;
            if (k == -1) throw;
            --k;
            s.erase({p[k], k});
            if (with[k] == -1 && !s2.empty()) {
                for (auto pr : s2) {
                    cout << pr.first + 1 << endl;
                    s.erase({p[pr.first], pr.first});
                    cin >> k;
                    if (k == -1) throw;
                    --k;
                    s.erase({p[k], k});
                }
                s2.clear();
            }
            if (s.empty())
                break;
            if (with[k] == -1 || s.find({p[with[k]], with[k]}) == s.end()) {
                auto it = s.end();
                --it;
                cout << it->second + 1 << endl;
                s.erase(--s.end());
            } else {
                cout << with[k] + 1 << endl;
                s.erase({p[with[k]], with[k]});
                s2.erase({k, with[k]});
                s2.erase({with[k], k});
            }
        }
    }
    return 0;
}