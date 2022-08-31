#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = (int)1e9 + 7;
set < int > buy, add, hz;
int n;
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int main() {
    srand(time(0));
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int cnt = 1;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        int x;
        cin >> s >> x;
        if (s == "ADD") {
            if (!buy.empty()) {
                if (x <= (*(--buy.end()))) {
                    buy.insert(x);
                    continue;
                }
            }
            if (!add.empty()) {
                if (x >= (*add.begin())) {
                    add.insert(x);
                    continue;
                }
            }
            hz.insert(x);
        }
        else {
            if (!buy.empty()) {
                int v = (*(--buy.end()));
                if (v > x) {
                    cout << 0;
                    return 0;
                }
            }
            if (!add.empty()) {
                int v = (*(add.begin()));
                if (v < x) {
                    cout << 0;
                    return 0;
                }
            }
            auto it = hz.lower_bound(x);
            if (it != hz.end() && (*it == x)) cnt = mult(cnt, 2);
            for (int v : hz) {
                if (x > v) buy.insert(v);
                if (x < v) add.insert(v);
            }
            hz.clear();
            buy.erase(x);
            add.erase(x);
        }
    }
    cnt = mult(cnt, hz.size() + 1);
    cout << cnt;
    return 0;
}