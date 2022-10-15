#include <iostream>
//#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
#include <algorithm>

using namespace std;

typedef long long ll;

namespace useful {
    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    bool space(vector<T>) { return false; }

    template<typename T>
    bool space(T) { return true; }

    bool space(char) { return false; }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << (space(t) ? "" : ""); }
        os << "\n";
        return os;
    }

    template<typename T>
    T gcd(T a, T b) {
        while (b) {
            T mod = a % b;
            a = b;
            b = mod;
        }
        return a;
    }

    template<typename T>
    void incr_sort(vector<T> &v) { stable_sort(v.begin(), v.end()); }

    template<typename T>
    void decr_sort(vector<T> &v) { stable_sort(v.rbegin(), v.rend()); }

    ll sum(vector<int> v) {
        int s = 0;
        for (int value : v) s += value;
        return s;
    }
}
using namespace useful;

void solve();

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);
    /*int t;
    cin >> t;
    for (int i = 0; i < t; ++i)*/ solve();
}

//----------------------------------------

void set(bool L, vector<bool> &guest){
    if (L){
        for (int i = 0; i < 10; ++i) {
            if (!guest[i]) {guest[i] = true;return;}
        }
    } else {
        for (int i = 9; i >= 0; --i) {
            if (!guest[i]) {guest[i] = true;return;}
        }
    }
}


void solve() {
    int n;
    cin >> n;
    vector<char> c(n);
    cin >> c;
    vector<bool> guest(10, false);
    for (int i = 0; i < n; ++i) {
        if (c[i] == 'L' || c[i] == 'R') set(c[i] == 'L', guest); else guest[c[i] - 48] = false;
    }
    cout << guest;
}