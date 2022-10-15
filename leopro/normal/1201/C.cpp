#include <iostream>
#include <set>
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
        for (const T &t : v) { os << t << (space(t) ? " " : ""); }
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
}
using namespace useful;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    cin >> a;
    incr_sort(a);
    int m = (n + 1) / 2;
    vector<ll> opts(m);
    for (int i = m - 1; i < n - 1; ++i) {
        opts[i - (m - 1)] = a[i + 1] - a[i];
        opts[i - (m - 1)] *= (i - (m - 1) + 1);
    }
    opts[n - m] = k;
    for (int i = 0; i < m; ++i) {
        if (k > opts[i]) k -= opts[i];
        else {
            int r = k / (i + 1);
            cout << a[m - 1 + i] + r << endl;
            return 0;
        }

    }
    return 0;
}