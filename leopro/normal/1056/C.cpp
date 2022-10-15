#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

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

    template<typename T>
    vector<vector<T>> vv(unsigned n, unsigned m, T val = T()) {
        return vector<vector<int>>(n, vector<int>(m, val));
    }

    template<typename T>
    vector<vector<T>> &cin_vv(int &n, int &m) {
        if (n == 0 && m == 0) cin >> n >> m;
        vector<vector<int>> *v = new vector<vector<int>>(n, vector<int>(m));
        cin >> *v;
        return *v;
    }
}
using namespace useful;

void choose(vector<int> &power, vector<int> &pair) {
    int p = -1;
    for (int i = 0; i < pair.size(); ++i) {
        if (pair[i] != -1) p = i;
    }
    if (p != -1){
        if (power[p] < power[pair[p]]) p = pair[p];
        cout << p + 1 << endl;
        power[p] = -1;
        pair[pair[p]] = -1;
        pair[p] = -1;
        return;
    }
    p = 0;
    for (int i = 0; i < power.size(); ++i) {
        if (power[i] > power[p]) p = i;
    }
    cout << p + 1 << endl;
    power[p] = -1;
    return;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> power(2 * n);
    cin >> power;
    vector<int> pair(2 * n, -1);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        pair[x - 1] = y - 1;
        pair[y - 1] = x - 1;
    }
    int t;
    cin >> t;

    for (int i = 0; i < n; ++i) {
        if (t == 1) {
            choose(power, pair);
            int H;
            cin >> H;
            power[H - 1] = -1;
        }
        if (t == 2){
            int H;
            cin >> H;
            power[H - 1] = -1;
            if (pair[H - 1] != -1){
                cout << pair[H - 1] + 1 << endl;
                power[pair[H - 1]] = -1;
                pair[pair[H - 1]] = -1;
                pair[H - 1] = -1;
            } else {
                choose(power, pair);
            }
        }
    }
}