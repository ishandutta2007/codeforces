#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <typeinfo>
 
using namespace std;
 
typedef long long ll;

#define endl "\n"
 
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
 
void divide(vector<int> a, int k){
    long long sum = 0;
    for (int v: a) sum += v;
    if (sum % 2 != k % 2) {
        cout << "NO\n";
        return;
    }
    vector<int> r;
    sum = 0;
    for (int i = 0; i < a.size(); ++i){
        sum += a[i];
        if (sum % 2 == 1){
            sum = 0;
            r.push_back(i + 1);
        }
    }
    if (r.size() < k){
        cout << "NO\n";
        return;
    }
    r[r.size() - 1] = a.size();
    cout << "YES\n";
    for (int i = 0; i < k - 1; ++i) {
        cout << r[i] << " ";
    }
    cout << r[r.size() - 1] << endl;
}
 
int main() {
    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        cin >> a;
        divide(a, k);
    }
}