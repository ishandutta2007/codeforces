#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

namespace Debug {
    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #define DEBUG

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    pii fir;
    fir.first = 1;
    fir.second = 2;
    for (int i = 3; i <= n; i++) {
        cout << "2 " << fir.first << ' ' << fir.second << ' ' << i << endl;
        int cur;
        cin >> cur;
        if (cur == -1)
            fir.second = i;
    }
    vector<ll> S(n + 1);
    vector<int> maybe;
    set<int> can_ask;
    for (int i = 1; i <= n; i++)
        can_ask.insert(i);
    can_ask.erase(fir.first);
    can_ask.erase(fir.second);
    for (int i = 1; i <= n; i++)
        if (i != fir.first && i != fir.second) {
            maybe.pb(i);
            cout << "1 " << fir.first << ' ' << fir.second << ' ' << i << endl;
            ll cur;
            cin >> cur;
            S[i] = cur;
        }
    sort(all(maybe), [&](int i, int j) {
        return S[i] < S[j];
    });
    deque<int> dq;
    dq.pb(fir.first);
    dq.pb(fir.second);
    for (auto el : maybe) {
        can_ask.erase(el);
        if (can_ask.empty()) {
            dq.pb(el);
            break;
        }
        cout << "2 " << el << ' ' << dq.back() << ' ' << *can_ask.begin() << endl;
        int cur;
        cin >> cur;
        if (cur == 1)
            dq.push_front(el);
        else
            dq.pb(el);
    }
    cout << "0 ";
    bool was = false;
    for (auto el : dq) {
        was |= (el == 1);
        if (was)
            cout << el << ' ';
    }
    was = false;
    for (auto el : dq) {
        was |= (el == 1);
        if (!was)
            cout << el << ' ';
    }
    cout << endl;
}