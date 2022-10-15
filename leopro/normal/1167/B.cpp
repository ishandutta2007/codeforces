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

bool check(int k, vector<int> answers, const int sum) {
    bool first = true;
    for (int i = 0; i < 4; ++i) {
        if (answers[i] % k != 0)
            first = false;
    }
    if (first) {
        cout << "! " << k << " ";
        int a = k;
        for (int i = 0; i < 4; ++i) {
            cout << answers[i] / k << " ";
            a += answers[i] / k;
        }
        cout << sum - a;
        return true;
    }
    return false;
}

int main() {
    const int sum = 4 + 8 + 15 + 16 + 23 + 42;
    vector<int> answers(4);
    for (int i = 1; i < 5; ++i) {
        cout << "? 1 " << i + 1 << endl;
        cout.flush();
        cin >> answers[i - 1];
    }
    if (check(23, answers, sum)) return 0;
    if (check(42, answers, sum)) return 0;
    if (check(15, answers, sum)) return 0;
    if (check(16, answers, sum)) return 0;
    if (check(8, answers, sum)) return 0;
    if (check(4, answers, sum)) return 0;
}