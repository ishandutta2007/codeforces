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
        for (T t : v) os << t << " ";
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
        cin >> n;
        vector<ll> d(n);
        cin >> d;
        incr_sort(d);
        ll ans = d[0] * d[n - 1];
        int i = 0;
        ll div = 2;
        for (; div <= sqrt(ans); ++div) {
            if (ans % div != 0) continue;
            if (i >= n || div != d[i++]) {
                cout << "-1\n";
                goto END;
            }
        }
        --div;
        if (div * div == ans) --div;
        for (; div >= 2; --div) {
            if (ans % div != 0) continue;
            if (i >= n || ans / div != d[i++]) {
                cout << "-1\n";
                goto END;
            }
        }
        cout << (i == n ? ans : -1) << "\n";
        END:;
    }
    return 0;
}