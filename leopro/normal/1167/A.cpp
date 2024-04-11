#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<string>
#include <cmath>

using namespace std;

typedef long long ll;

namespace useful {
    template<typename T>
    istream &operator>>(istream &is, vector<T> &v) {
        for (T &t : v) is >> t;
        return is;
    }

    template<typename T>
    ostream &operator<<(ostream &os, const vector<T> &v) {
        for (const T &t : v) { os << t << " "; }
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

int main() {
    int t;
    cin >> t;
    while (t--){
        int n;
        string s;
        cin >> n >> s;
        bool YES = false;
        for (int i = 0; i < n - 10; ++i) {
            YES |= (s[i] == '8');
        }
        cout << (YES ? "YES\n" : "NO\n");
    }
}