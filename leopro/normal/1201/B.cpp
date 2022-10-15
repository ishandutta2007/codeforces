#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>

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
    int n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll sum = 0;
    for (int v : a) sum += v;
    if (sum & 1){
        cout << "NO\n";
        return 0;
    }
    ll half = sum / 2;
    for (int i = 0; i < n; ++i) {
        if (a[i] > half){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}