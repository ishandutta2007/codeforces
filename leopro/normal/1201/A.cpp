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

int count(int j, char c, const vector<string> &answers) {
    int r = 0;
    for (auto &answer : answers) {
        r += answer[j] == c;
    }
    return r;
}

int count(int j, const vector<string> &answers) {
    return max(max(max(count(j, 'A', answers), count(j, 'B', answers)),
                   max(count(j, 'C', answers), count(j, 'D', answers))), count(j, 'E', answers));
}

using namespace useful;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> answers(n);
    cin >> answers;
    vector<int> points(m);
    cin >> points;
    vector<int> ans(n);
    int r = 0;
    for (int i = 0; i < m; ++i) r += count(i, answers) * points[i];
    cout << r << endl;
}