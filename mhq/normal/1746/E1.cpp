#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool check(int x) {
    cout << "! " << x << endl;
    string rep;
    cin >> rep;
    return (rep == ":)");
}
int Q = 0;
bool ask(vector<int> x) {
    assert(!x.empty());
    Q++;
    assert(Q <= 82);
    cout << "? " << x.size() << " ";
    for (int i : x) {
        cout << i << " ";
    }
    cout << endl;
    string rep;
    cin >> rep;
    return (rep == "YES");
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//#ifdef DEBUG
//    freopen("input.txt", "r", stdin);
//#endif
    int n;
    cin >> n;
    vector<int> f(n);
    iota(f.begin(), f.end(), 1);
    while (f.size() > 2) {
        int sz = f.size();
        vector<int> f1(f.begin(), f.begin() + sz / 3);
        vector<int> f2(f.begin() + sz / 3, f.begin() + sz / 3 + (sz + 1) / 3);
        vector<int> f3(f.begin() + sz / 3 + (sz + 1) / 3, f.begin() + sz / 3 + (sz + 1) / 3 + (sz + 2) / 3);
        assert(f1.size() == sz / 3);
        bool q1 = ask(f1);
        if (q1) {

        }
        else {
            q1 = ask(f1);
            if (!q1) {
                f.clear();
                for (int x : f2) f.emplace_back(x);
                for (int x : f3) f.emplace_back(x);
                continue;
            }
        }
        assert(q1);
        bool q2 = ask(f2);
        if (q2) {
            f.clear();
            for (int x : f1) f.emplace_back(x);
            for (int x : f2) f.emplace_back(x);
        }
        else {
            f.clear();
            for (int x : f1) f.emplace_back(x);
            for (int x : f3) f.emplace_back(x);
        }
    }
    if (check(f[0])) {
        return 0;
    }
    assert(check(f[1]));
    return 0;
}